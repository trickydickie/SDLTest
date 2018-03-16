/*
 * Particle.cpp
 *
 *  Created on: 16 Mar 2018
 *      Author: richard
 */

#include "Particle.h"



void Particle::moveParticle(){
  xPos += xVel;
  yPos += yVel;

  if (xPos > 640){
	  	xPos = 0;
  };

  if (yPos > 480){
  	  	yPos = 0;
    };
}

