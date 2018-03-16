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

const int WIDTH = 640;
const int HEIGHT = 480;

using namespace std;

int rows(int r){
	return WIDTH*4*(r-1) ;
}
int columns(int c){
	return (4*(c-1)) ;
}

int main(){

	if (SDL_Init(SDL_INIT_VIDEO) !=0){
		cout << "SDL_Init Error " << SDL_GetError() << endl;
		return 1;
	}


	SDL_Window *win = SDL_CreateWindow("Hello World!",100,100,WIDTH,HEIGHT,0);


	SDL_Renderer *ren = SDL_CreateRenderer(win,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Texture *tex = SDL_CreateTexture(ren,SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, WIDTH,HEIGHT);
	bool quit = false;
	SDL_Event event;

	vector< unsigned char > pixels(WIDTH*HEIGHT*4,0);
	unsigned char setPixel[4]={255,255,255,255};

	std::copy(setPixel,setPixel+4,&pixels[rows(240)+columns(320)]); //one way to set a group

	/*const unsigned int x = rand() % texWidth;
            const unsigned int y = rand() % texHeight;

            const unsigned int offset = ( texWidth * 4 * y ) + x * 4;
            pixels[ offset + 0 ] = rand() % 256;        // b
            pixels[ offset + 1 ] = rand() % 256;        // g
            pixels[ offset + 2 ] = rand() % 256;        // r
            pixels[ offset + 3 ] = SDL_ALPHA_OPAQUE;    // a                 another way to set a group*/

	while (!quit)
	    {
		SDL_UpdateTexture(tex,NULL,&pixels[0],640*sizeof(Uint32));

	        SDL_WaitEvent(&event);
	        switch (event.type)
	        {
	            case SDL_QUIT:
	                quit = true;
	                break;
	        }

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
