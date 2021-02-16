#include <SDL2\SDL.h>
#include <iostream>
//Screen dimension constants
const int SCREEN_WIDTH = 640,SCREEN_HEIGHT= 480;

int main( int argc, char* args[] ){
 SDL_Window* window = NULL;  //The window we'll be rendering to
 SDL_Surface* screenSurface = NULL;  //The surface contained by the window
 //Initialize SDL
 if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
  std::cout<<"SDL_Error: %s\n"<<SDL_GetError()<<std::endl;
 }else{
  //Create window
  window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  if( window == NULL ){
   std::cout<<"SDL_Error: %s\n"<<SDL_GetError()<<std::endl;
  }else{
   screenSurface = SDL_GetWindowSurface( window ); //Get window surface
   SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0xFF, 0xFF ) );
 //Fill the surface with color
   SDL_UpdateWindowSurface( window ); //Update the surface
   SDL_Delay( 2000 ); //Wait two seconds
  }
 }
 SDL_DestroyWindow( window ); //Destroy window
 SDL_Quit();  //Quit SDL subsystems
 return 0;
}
