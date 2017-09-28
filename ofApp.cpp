#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	for (int x = 0; x < 24; x++) {
		for (int y = 0; y < 24; y++) {
			this->values[x][y] = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int x = 0; x < 24; x++) {
		for (int y = 0; y < 24; y++) {
			if (ofNoise(x * 0.5, y * 0.5, ofGetFrameNum() * 0.005) > 0.5) {
				this->values[x][y] = true;
			}
			else {
				this->values[x][y] = false;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int x = 0; x < 24; x++) {
		for (int y = 0; y < 24; y++) {
			float location_x = x * this->spacing;
			float location_y = y * this->spacing;

			ofSetColor(255);
			if (this->values[x][y]) {
				ofLine(location_x, location_y, location_x + spacing, location_y + spacing);
			} else {
				ofLine(location_x, location_y + spacing, location_x + spacing, location_y);
			}

			if (x >= 0 && x < 24 - 1) {
				if (y >= 0 && y < 24 - 1) {
					if (this->values[x][y] == false && this->values[x + 1][y] == true && this->values[x][y + 1] == true && this->values[x + 1][y + 1] == false)
					{
						//ofEllipse(ofVec3f(location_x, location_y + spacing), 10, 10);
						//ofEllipse(ofVec3f(location_x + spacing, location_y), 10, 10);
						//ofEllipse(ofVec3f(location_x + spacing + spacing, location_y + spacing), 10, 10);
						//ofEllipse(ofVec3f(location_x + spacing, location_y + spacing + spacing), 10, 10);

						ofSetColor(128, 128);
						ofBeginShape();
						ofVertex(ofVec3f(location_x, location_y + spacing));
						ofVertex(ofVec3f(location_x + spacing, location_y));
						ofVertex(ofVec3f(location_x + spacing + spacing, location_y + spacing));
						ofVertex(ofVec3f(location_x + spacing, location_y + spacing + spacing));
						ofEndShape(true);
					}
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
