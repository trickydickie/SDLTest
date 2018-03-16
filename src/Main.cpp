/*
 * Main.cpp
 *
 *  Created on: 15 Mar 2018
 *      Author: richard
 */


#include <iostream>
#include <string>
#include <SDL.h>
#include <vector>
#include "Particle.h"

const int WIDTH = 640;
const int HEIGHT = 480;

using namespace std;


int main(){

	if (SDL_Init(SDL_INIT_VIDEO) !=0){
		cout << "SDL_Init Error " << SDL_GetError() << endl;
		return 1;
	}


	SDL_Window *win = SDL_CreateWindow("Hello World!",100,100,WIDTH,HEIGHT,0);


	SDL_Renderer *ren = SDL_CreateRenderer(win,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Texture *tex = SDL_CreateTexture(ren,SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, WIDTH,HEIGHT);
	bool quit = false;


	vector< unsigned char > pixels(WIDTH*HEIGHT*4,0);
	//const unsigned char setPixel[4]={255,255,255,255};

	 //one way to set a group




   unsigned int offset=0;
   unsigned int newoffset=0;

	Particle particle;
	double angle = 0;

	while (!quit)
	    {
		angle += 0.01;

		particle.moveParticle(angle);

		offset = newoffset;
		newoffset= ( WIDTH * 4 * particle.y() ) + particle.x() * 4;
		            pixels[ newoffset + 0 ] = rand()%255;        // b
		            pixels[ newoffset + 1 ] = rand()%255;       // g
		            pixels[ newoffset + 2 ] = rand()%255;       // r
		            pixels[ newoffset + 3 ] = rand()%255;    // a
		            //pixels[ offset + 0 ] = 0 ;      // b
		            //pixels[ offset + 1 ] = 0 ;       // g
		            //pixels[ offset + 2 ] = 0 ;      // r
		            //pixels[ offset + 3 ] = 0;



		SDL_UpdateTexture(tex,NULL,&pixels[0],640*sizeof(Uint32));
		SDL_Delay(10);
		//the SDL_WaitEvent was lagging the whole thing down horribly
	       /* SDL_WaitEvent(&event);
	        switch (event.type)
	        {
	            case SDL_QUIT:
	                quit = true;
	                break;
	        }*/

	        SDL_RenderClear(ren);
	        SDL_RenderCopy(ren,tex,NULL,NULL);
	        SDL_RenderPresent(ren);

	    }


//testing
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
