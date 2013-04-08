//==============================================================================
#include "App.h"

//------------------------------------------------------------------------------
void App::OnEvent(SDL_Event* Event) {
    Event::OnEvent(Event);
}

//------------------------------------------------------------------------------
//controls what happens when keys are pressed down
void App::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {  
	switch(sym) {
		case SDLK_LEFT: {
			Player1.MoveLeft = true;
			
			break;
		}

		case SDLK_RIGHT: {
			Player1.MoveRight = true;
			
			break;
		}
		
		case SDLK_UP: {
			Player1.MoveUp = true;
			
			break;
		}

		case SDLK_DOWN: {
			Player1.MoveDown = true;
			
			break;
		}

    case SDLK_ESCAPE: {
      OnExit();
      break;
    }

		default: {
		}
	}
}

//------------------------------------------------------------------------------
//controls what happens when keys are released
void App::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) { 
	switch(sym) {
		case SDLK_LEFT: {
			Player1.MoveLeft = false;
			break;
		}

		case SDLK_RIGHT: {
			Player1.MoveRight = false;
			break;
		}
		
		case SDLK_UP: {
			Player1.MoveUp = false;
			break;
		}

		case SDLK_DOWN: {
			Player1.MoveDown = false;
			break;
		}
		
		default: {
		}
	}
}

//------------------------------------------------------------------------------
//ends program
void App::OnExit() {
	Running = false;
}

//==============================================================================
