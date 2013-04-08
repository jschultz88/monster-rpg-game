//==============================================================================
#include "App.h"

//------------------------------------------------------------------------------
//initializes everything
bool App::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) { //kicks back if SDL errors out
        return false;
    }
    
    //kicks back if there is nothing to display
    if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
	
	//kicks back if there is nothing in 1.area
    if(Area::AreaControl.OnLoad((char*)"./maps/1.area") == false) {
    	return false;
    }

	//sets the repeat rate
    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    //kicks back if there is nothing in yoshi.png
    if(Player1.OnLoad((char*)"images/yoshi.png", 64, 64, 8) == false) {
    	return false;
    }
	
	Player1.X = 20;
	Player1.Y = 20;
	//enables push_back so that entities don't overlap
    Entity::EntityList.push_back(&Player1);
	//Camera::CameraControl.SetPos(640,480);
	//sets camera over player1
	//Camera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    //Camera::CameraControl.SetPos(AreaControl.GetMap.X, AreaControl.GetMap.Y);

    //says that there are no errors
    return true;
}

//==============================================================================
