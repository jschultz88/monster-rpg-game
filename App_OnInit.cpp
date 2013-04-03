//==============================================================================
#include "App.h"

//==============================================================================
bool App::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    
    freopen("CON", "w", stdout); // redirects stdout
	freopen("CON", "w", stderr); // redirects stderr

    if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if(Area::AreaControl.OnLoad((char*)"./maps/1.area") == false) {
    	return false;
    }

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    if(Player1.OnLoad((char*)"images/yoshi.png", 64, 64, 8) == false) {
    	return false;
    }


    Entity::EntityList.push_back(&Player1);


	//Camera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    //Camera::CameraControl.SetPos(AreaControl.GetMap.X, AreaControl.GetMap.Y);

    return true;
}

//==============================================================================
