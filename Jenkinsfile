/*
  Copyright (c) 2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

pipeline {
  agent none
  
  // The environment in use. Change it according to your needs
  environment {
    // IAR Build Tools settings
    BX_ARCH       = 'arm'                                            // Change to the desired <arch>
    BX_VERSION    = '9.10.1'                                         // Change to the desired <version>
    BX_LMS2_IP    = 'license-server.example.com'                     // Point to your IAR License Server (IP or FQDN) 
    
    // Docker image settings
    BX_IMAGE      = 'iarsystems/bx${BX_ARCH}:${BX_VERSION}'          
    BX_LMS2_DIR   = '/tmp/.lms-jenkins'
    BX_IMAGE_ARGS = "-v ${env.BX_LMS2_DIR}:/.lms"
    // Build settings
    ARCH_DIR      = "${env.BX_ARCH}"
    BUILD_CONFIGURATION = 'Debug'
  }
  
  // Update these parameters whenever more artifacts should be kept (/for longer)
  options {
    buildDiscarder(logRotator(daysToKeepStr: "14", artifactNumToKeepStr: "20"))
  }

  /* 
    Initialize the directory for storing IAR license data
    This stage runs outside the container so the license token
    can be shared among parallel jobs within the host
  */
  stages {
    stage('Initialization') {
      options {
        skipDefaultCheckout()
      }
      agent any
      stages {
        stage('Create license dir?') {
          steps {
            dir (env.BX_LMS2_DIR) {
              writeFile file:'placeholder', text:''
            }
          }
        }
      }
    }
    
    // The entire IAR Build Tools stage runs from a Docker container
    stage('IAR Build Tools') {
      agent {
        docker { 
          alwaysPull false
          reuseNode true
          image env.BX_IMAGE
          args  env.BX_IMAGE_ARGS
        }
      }
      stages {
        stage('License setup') {
          steps {
            sh 'lightlicensemanager setup -s ' + env.BX_LMS2_IP
          }
        }
        stage('Checkout code') {
          steps {
//            cleanWs()
            checkout scm
          }
        }
        stage('Build Library') {
          steps {
            sh '''
            iarbuild ${ARCH_DIR}/library.ewp -build ${BUILD_CONFIGURATION} -log all -parallel $(nproc)
            iarbuild ${ARCH_DIR}/library.ewp -cstat_analyze ${BUILD_CONFIGURATION} -log all -parallel $(nproc)
            '''
          }
        }
        stage('Build Component A') {
          steps {
            sh '''
            iarbuild ${ARCH_DIR}/componentA.ewp -build ${BUILD_CONFIGURATION} -log all -parallel $(nproc)
            iarbuild ${ARCH_DIR}/componentA.ewp -cstat_analyze ${BUILD_CONFIGURATION} -log all -parallel $(nproc)
            '''
          }
        }
        stage('Build Component B') {
          steps {
            sh '''
            iarbuild ${ARCH_DIR}/componentB.ewp -build ${BUILD_CONFIGURATION} -log all -parallel $(nproc)
            iarbuild ${ARCH_DIR}/componentB.ewp -cstat_analyze ${BUILD_CONFIGURATION} -log all -parallel $(nproc)
            '''
          }
        }
      }
      
      // The post-stages comes with three hypotesis
      post {
        always {
          sh 'echo This will execute whenever the pipeline ends.'                         
        }
        failure {
          sh 'echo This will execute when the pipeline fails.'
        }
        success {
          sh 'echo This will execute when succesful.'
          sh 'icstat --db ${ARCH_DIR}/${BUILD_CONFIGURATION}/Obj/cstat.db load'
          recordIssues(tools: [iar(), iarCstat()])
        }
      }
    }
  }
}
// END of the Jenkinsfile
