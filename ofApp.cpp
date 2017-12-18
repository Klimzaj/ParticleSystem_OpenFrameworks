#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    light.setup();
    light.setPosition(-100, 200,0);

    ofBackground(0, 0, 0, 0);
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());

    // Droga mleczna
    int N = 2000;  //pozmieniac wszystko na zmienne importowane z jednego pliku!
    for(int i = 0; i < N;i++)
    {
        b.push_back(Particle(ofRandom(2,10),ofRandom(1,9),ofVec3f(ofRandom(-500,-400),ofRandom(-70,150),ofRandom(80,120)),100,120));
    }
    AllParticles.addToMess(b);
    AllParticles.setAllForces(10,2,0,0.02);

    // Fajerwerki
    AllFire = Fireworks(50,100);
    AllFire.shotAllMess();
    FireMess = AllFire.getMess();
    
    // Moon
    _Moon = Particle(80,100,ofVec3f(320,200,100),100,100);
    m.push_back(_Moon);
    // m.push_back(Particle(100,70,ofVec3f(320,200,100),100,100));
    Moon.addToMess(m);
    Moon.setPosition();    
    
    // ofEnableDepthTest();  //hmm??
}

//--------------------------------------------------------------
void ofApp::update(){
    // Droga mleczna
    AllParticles.moveAllByForce();
    AllParticles.setPosition();
    AllParticles.moveByCollision(_Moon);   //dodac ksiezyc
    AllParticles.checkTime();
    
    // Fajerwerki
    AllFire.explode();
    AllFire.moveAllByForce();
    AllFire.setPosition();
    AllFire.checkTime();
    AllFire.moveByCollision(_Moon);
    
    // // Ksieżyc
    // Moon.moveAllByForce();
    // Moon.setPosition();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
        // cam.lookAt(ofVec3f(0,0,0));
        ofSetColor(255,92,138,60);
        AllFire.draw();
        ofSetColor(188,71,254,255);
        Moon.draw();
        ofSetColor(91,228,97,90);
        AllParticles.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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