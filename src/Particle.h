/*
 * Particle.h
 *
 *  Created on: 16 Mar 2018
 *      Author: richard
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_


class Particle {
private:
	int xPos;
	int yPos;
	int xVel;
	int yVel;
public:
	Particle():xPos(0),yPos(100),xVel(35),yVel(35){};
	void moveParticle(double angle);
	int y(){return yPos;};
	int x(){return xPos;};
};

#endif /* PARTICLE_H_ */
