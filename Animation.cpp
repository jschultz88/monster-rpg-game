//==============================================================================
#include "Animation.h"

//==============================================================================
//Sets default variables
Animation::Animation() {	
    CurrentFrame    = 0;	
    MaxFrames       = 0;
    FrameInc        = 1;

    FrameRate       = 100; //Milliseconds
    OldTime         = 0;

    Oscillate       = false;
}

//------------------------------------------------------------------------------
//Controls animation of entities
void Animation::OnAnimate() {
    if(OldTime + FrameRate > SDL_GetTicks()) {		//kicks it back if it isn't time to animate yet
        return;
    }

    OldTime = SDL_GetTicks();		//sets OldTime to the current time

    CurrentFrame += FrameInc;		//increments CurrentFrame to get the next animation frame

    if(Oscillate) {					//This is for oscillating animations (example 0,1,2,3,3,2,1,0)
        if(FrameInc > 0) {
            if(CurrentFrame >= MaxFrames - 1) {
                FrameInc = -FrameInc;
            }
        }else{
            if(CurrentFrame <= 0) {
                FrameInc = -FrameInc;
            }
        }
    }else{
        if(CurrentFrame >= MaxFrames - 1) { //This is for non-oscillating animations. If it is at the last frame...
            CurrentFrame = 0;				//...put it back to the beginning.
        }
    }
}

//==============================================================================
//Sets the framerate to user defined rate
void Animation::SetFrameRate(int Rate) {
    FrameRate = Rate;
}

//------------------------------------------------------------------------------
//Sets entity to specific frame
void Animation::SetCurrentFrame(int Frame) {
    if(Frame < 0 || Frame >= MaxFrames) return; //this kicks it back it Frame does not exist

    CurrentFrame = Frame;
}

//------------------------------------------------------------------------------
int Animation::GetCurrentFrame() { //returns the current frame
    return CurrentFrame;
}

//==============================================================================
