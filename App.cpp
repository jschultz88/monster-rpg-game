//==============================================================================
#include "App.h"
using namespace std;
//==============================================================================
//sets default variables
App::App() {
    Surf_Display = NULL;

    Running = true;
}

//------------------------------------------------------------------------------
//controls execution of the program
int App::OnExecute() {
    if(OnInit() == false) {  //kicks it back if program hasn't initialized yet
        return -1;				//sends error
    }

    SDL_Event Event;		//creates an SDL Event

    while(Running) {					//checks that program is running
        while(SDL_PollEvent(&Event)) {  //watches for user input
            OnEvent(&Event);			//runs OnEvent for users input
        }

        OnLoop();						//runs OnLoop
        OnRender();						//renders graphics
    }

    OnCleanup();						//Cleans up

    return 0;							//no error
}

//==============================================================================
//main function runs OnExecute
int main(int argc, char* argv[]) {
    App theApp;						

    return theApp.OnExecute();
}

//==============================================================================
