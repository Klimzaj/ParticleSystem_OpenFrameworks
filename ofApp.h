#pragma once

#include "ofMain.h"
#include "particle.h"
#include "particles.h"
#include "fireworks.h"
#include <vector>

class ofApp : public ofBaseApp{
	public:
		int N;

		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		std::vector<Particle> b;
		std::vector<Particle> m;
		std::vector<Particle> f;
		std::vector<Particle> FireMess;

		Particle _Moon;
		Fireworks AllFire;
		Particles AllParticles;
		Particles Moon;



		ofLight light;
		ofEasyCam cam;
};
