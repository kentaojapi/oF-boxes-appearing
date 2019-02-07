#include "ofApp.h"
using namespace std;
// refer to https://junkiyoshi.com/openframeworks20190202/.
//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(19);
	ofSetColor(210);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.75);

	vector<glm::vec3> locations;
	for (int i = 0; i < 650; i++) {

		glm::vec3 random_point(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.001), 0, 1, -1, 1),
			ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.001), 0, 1, -1, 1), 
			ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.001), 0, 1, -1, 1));

		int len = 300;
		random_point = glm::normalize(random_point) * len;
		locations.push_back(random_point);
	}

	for (int i = 0; i < locations.size(); i++) {
		for (int j = i + 1; j < locations.size(); j++) {
			float length = glm::distance(locations[i], locations[j]);
			if (length < 30) {
				ofDrawBox(locations[i], length);
			}
		}
	}

	this->cam.end();
}
