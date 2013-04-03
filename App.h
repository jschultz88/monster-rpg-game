//==============================================================================
// SDL Tutorial 8
//==============================================================================
#ifndef _APP_H_
    #define _APP_H_

#include <SDL/SDL.h>
#include <iostream>


#include "Define.h"

#include "FPS.h"

#include "Area.h"
#include "Camera.h"
#include "Entity.h"
#include "Event.h"
#include "Surface.h"

#include "Player.h"

//==============================================================================
class App : public Event {
    private:
        bool            Running;

        SDL_Surface*    Surf_Display;

        Player			Player1;
        Player			Player2;

    public:
        App();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event* Event);

        	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        	void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

            void OnExit();

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

//==============================================================================

#endif
