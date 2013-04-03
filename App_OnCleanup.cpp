//==============================================================================
#include "App.h"

//==============================================================================
//cleans up memory
void App::OnCleanup() {
	Area::AreaControl.OnCleanup();  //cleans up the areas

    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < Entity::EntityList.size();i++) { //runs through all of the entities and cleans them
        if(!Entity::EntityList[i]) continue;

        Entity::EntityList[i]->OnCleanup();
    }

    Entity::EntityList.clear();						//clears out the entity list

    SDL_FreeSurface(Surf_Display);					//frees the surfae resources
    SDL_Quit();										//Quits SDL
}

//==============================================================================
