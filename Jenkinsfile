pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'g++ datatypes.cpp -o democpp'
      }
    }

    stage('Test') {
      steps {
        sh './democpp'
      }
    }

    stage('Deliver') {
      steps {
        sh 'tar -czf demo.tar.gz democpp'
        archiveArtifacts(artifacts: 'demo.tar.gz', fingerprint: true)
      }
    }

  }
}