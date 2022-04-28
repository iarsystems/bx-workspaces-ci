/*
  Copyright (c) 2021-2022 IAR Systems AB.
  See LICENSE for detailed license information.
*/

pipeline {
  agent {
    docker { 
      image 'iarsystems/bxarm:9.20.4' 
      args '-v LMS2:/usr/local/etc/IARSystems --hostname bxarm-build-agent-1'
    }
  }
	
  stages {
    stage('Test compiler') {
      steps {
        echo 'If this stage fails, it is likely there is a license issue.'
        sh '/opt/iarsystems/bxarm/arm/bin/iccarm --version'
      }
    }
		
    stage('Build: Library') {
			steps {
				sh '/opt/iarsystems/bxarm/common/bin/iarbuild arm/library.ewp -build Release'
      }
    }
    stage('Build: Component A') {
			steps {
				sh '/opt/iarsystems/bxarm/common/bin/iarbuild arm/componentA.ewp -build Release'
			}
    }
    stage('Build: Component B') {
      steps {
        sh '/opt/iarsystems/bxarm/common/bin/iarbuild arm/componentB.ewp -build Release'
      }
    }
		
    stage('Analysis: Library') {
      steps {
				sh '/opt/iarsystems/bxarm/common/bin/iarbuild arm/library.ewp -cstat_analyze Release'
      }
    }
		stage('Analysis: Component A') {
      steps {
				sh '/opt/iarsystems/bxarm/common/bin/iarbuild arm/library.ewp -cstat_analyze Release'
      }
    }
		stage('Analysis: Component B') {
			steps {
				sh '/opt/iarsystems/bxarm/common/bin/iarbuild arm/componentB.ewp -cstat_analyze Release'
			}
    }
  }

	post {
		always {
			echo 'This will always execute at the pipeline ending.'
			sh '/opt/iarsystems/bxarm/arm/bin/icstat --db arm/Release/C-STAT/cstat.db load'
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
