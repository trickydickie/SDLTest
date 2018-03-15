/*
 * Main.cpp
 *
 *  Created on: 15 Mar 2018
 *      Author: richard
 */


#include <iostream>
#include <SDL.h>

using namespace std;

int main(){

	if (SDL_Init(SDL_INIT_VIDEO) !=0){
		cout << "SDL_Init Error " << SDL_GetError() << endl;
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("Hello World!",100,100,640,480,SDL_WINDOW_SHOWN);

	if (win == NULL){
		cout << "SDL Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (ren==NULL){
		SDL_DestroyWindow(win);
		cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	SDL_Surface *bmp = SDL_LoadBMP("/home/richard/hello.bmp");

	if (bmp==NULL){
			SDL_DestroyRenderer(ren);
			SDL_DestroyWindow(win);
			cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
			SDL_Quit();
			return 1;
		}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren,bmp);
	SDL_FreeSurface(bmp);
	if (tex==NULL){
				SDL_DestroyRenderer(ren);
				SDL_DestroyWindow(win);
				cout << "SDL_CTFS Error: " << SDL_GetError() << endl;
				SDL_Quit();
				return 1;
			}

	SDL_RenderClear(ren);
	SDL_RenderCopy(ren,tex,NULL,NULL);

	SDL_RenderPresent(ren);

	SDL_Delay(3000);
	//SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
