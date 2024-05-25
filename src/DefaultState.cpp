#include "ModeEnum.hpp"
#include "ncurses.h"
#include "ModeStateMachine.hpp"
#include "DefaultState.hpp"

DefaultState::DefaultState(Coordinates& coords) : coords(coords){}

/* TODO: Rework Movement
*  Rework movement so that it has the following attributes:
*  - Dont go past the end of a line
*  - Dont go offscreen 
*  - Dont go past the end of the buffer
*/

void DefaultState::handleInput(ModeStateMachine& stateMachine, int c){
    switch(c){
        case 'i':
            stateMachine.setState(State::INSERT);
            return;
        case ':':
            stateMachine.setState(State::COMMANDS);
            return;
        case 'l':
            move(coords.y, ++coords.x);
            break;
        case 'h':
            move(coords.y, --coords.x);
            break;
        case 'j':
            move(++coords.y, coords.x);
            break;
        case 'k':
            move(--coords.y, coords.x);
            break;
        default:
            move(coords.y, coords.x);
            break;
    }
}
