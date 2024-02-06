/*
  Copyright (c) 2021-2024 IAR Systems AB.
  See LICENSE for detailed license information.
*/

pipeline {
  agent {
    /* The Docker image: change it according to your needs. */
    docker { 
      image 'iarsystems/bxarm:9.50.1'
      args '-v LMS2:/usr/local/etc/IARSystems -e HOME=${WORKSPACE} --hostname ${NODE_NAME}'
    }
  }
  /* The environment: change it according to your needs. */
  environment {
    BX_BINDIR      = "/opt/iarsystems/bxarm/arm/bin"
    BX_COMMON      = "/opt/iarsystems/bxarm/common/bin"
    TARGET_DIR     = "targets/arm"
    BUILD_TYPE     = 'Release'
  }
  stages {
    stage('Test compiler') {
      steps {
        echo 'If this stage fails, it is likely there is a license issue.'
        sh '${BX_BINDIR}/icc`basename ${TARGET_DIR}` --version'
      }
    }
    /* Build stages */
    stage('Build: library') {
      steps {
        sh '${BX_COMMON}/iarbuild ${TARGET_DIR}/library.ewp -build ${BUILD_TYPE}'
      }
    }
    stage('Build: test-crc16') {
      steps {
        sh '${BX_COMMON}/iarbuild ${TARGET_DIR}/test-crc16.ewp -build ${BUILD_TYPE}'
      }
    }
    stage('Build: test-crc32') {
      steps {
        sh '${BX_COMMON}/iarbuild ${TARGET_DIR}/test-crc32.ewp -build ${BUILD_TYPE}'
      }
    }
    /* Analysis stages */
    stage('Analyze: library') {
      steps {
        sh '${BX_COMMON}/iarbuild ${TARGET_DIR}/library.ewp -cstat_analyze ${BUILD_TYPE}'
      }
    }
    stage('Analyze: test-crc16') {
      steps {
        sh '${BX_COMMON}/iarbuild ${TARGET_DIR}/test-crc16.ewp -cstat_analyze ${BUILD_TYPE}'
      }
    }
    stage('Analyze: test-crc32') {
      steps {
        sh '${BX_COMMON}/iarbuild ${TARGET_DIR}/test-crc32.ewp -cstat_analyze ${BUILD_TYPE}'
      }
    }
  }
  /* Post stages */
  post {
    always {
      echo 'This will always execute at the pipeline ending.'
      /* Load the C-STAT warnings for the recordIssues() function from the warnings-ng plugin */
      sh '${BX_BINDIR}/icstat --db ${TARGET_DIR}/${BUILD_TYPE}/C-STAT/cstat.db load'
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
