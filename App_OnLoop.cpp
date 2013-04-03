//==============================================================================
#include "App.h"

//==============================================================================
void App::OnLoop() {
    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    //calls OnLoop for each entity
    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;

        Entity::EntityList[i]->OnLoop();
    }
	
	//regulates fps
    FPS::FPSControl.OnLoop();

    char Buffer[255];
    sprintf(Buffer, "%d", FPS::FPSControl.GetFPS());
    SDL_WM_SetCaption(Buffer, Buffer);
}

//==============================================================================
