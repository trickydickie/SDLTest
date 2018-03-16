/*
 * Particle.cpp
 *
 *  Created on: 16 Mar 2018
 *      Author: richard
 */

#include "Particle.h"
#include <math.h>



void Particle::moveParticle(double angle){
  xPos = 320+(100*angle)*sin(angle);
  yPos = 240+100*cos(angle);

}



