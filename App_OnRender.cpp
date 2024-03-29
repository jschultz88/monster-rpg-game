//==============================================================================
#include "App.h"

//==============================================================================
void App::OnRender() {
	SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.w = WWIDTH;
	Rect.h = WHEIGHT;

	//fills the window
	SDL_FillRect(Surf_Display, &Rect, 0);
	
	//displays the proper map
	Area::AreaControl.OnRender(Surf_Display, -Camera::CameraControl.GetX(), -Camera::CameraControl.GetY(), Player1.GetX(), Player1.GetY());
	
	


    //--------------------------------------------------------------------------
    // Entities - displays all of the entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;

        Entity::EntityList[i]->OnRender(Surf_Display);
    }
	
	
	SDL_Flip(Surf_Display);
}

//==============================================================================
