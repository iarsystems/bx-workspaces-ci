/*
  Copyright (c) 2021-2022 IAR Systems AB.
  See LICENSE for detailed license information.
*/

pipeline {
  agent {
    /* The Docker image: change it according to your needs. */
    docker { 
      image 'iarsystems/bxarm:9.20.4' 
      args '-v LMS2:/usr/local/etc/IARSystems --hostname ${NODE_NAME}'
    }
  }

  /* The environment: change it according to your needs. */
  environment {
    BX_ARCH        = 'arm'
    BX_INSTALL_DIR = "/opt/iarsystems/bx${env.BX_ARCH}"
    BX_BUILD_CFG   = 'Release'  
  }
	
  stages {
    stage('Test compiler') {
      steps {
        echo 'If this stage fails, it is likely there is a license issue.'
        sh '${BX_INSTALL_DIR}/${BX_ARCH}/bin/icc${BX_ARCH} --version'
      }
    }
    
    /* Build stages */
    stage('Build: Library') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${BX_ARCH}/library.ewp -build ${BX_BUILD_CFG}'
      }
    }
    stage('Build: Component A') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${BX_ARCH}/componentA.ewp -build ${BX_BUILD_CFG}'
      }
    }
    stage('Build: Component B') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${BX_ARCH}/componentB.ewp -build ${BX_BUILD_CFG}'
      }
    }
		
    /* Analysis stages */
    stage('Analysis: Library') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${BX_ARCH}/library.ewp -cstat_analyze ${BX_BUILD_CFG}'
      }
    }
    stage('Analysis: Component A') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${BX_ARCH}/componentA.ewp -cstat_analyze ${BX_BUILD_CFG}'
      }
    }
    stage('Analysis: Component B') {
      steps {
        sh '${BX_INSTALL_DIR}/common/bin/iarbuild ${BX_ARCH}/componentB.ewp -cstat_analyze ${BX_BUILD_CFG}'
      }
    }
  }

  /* Post stages */
  post {
    always {
      echo 'This will always execute at the pipeline ending.'
      /* Load the C-STAT warnings for the recordIssues() function from the warnings-ng plugin */
      sh '${BX_INSTALL_DIR}/${BX_ARCH}/bin/icstat --db ${BX_ARCH}/Release/C-STAT/cstat.db load'
      recordIssues(tools: [iar(), iarCstat()])			
    }
    failure {
      echo 'This will execute when one or more pipeline stages fail.'
    }
    success {
      echo 'This will execute when all pipeline stages are succesful.'
    }
  }
}
