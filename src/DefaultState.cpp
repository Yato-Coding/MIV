#include "ModeEnum.hpp"
#include "ncurses.h"
#include "ModeStateMachine.hpp"
#include "DefaultState.hpp"

DefaultState::DefaultState(Coordinates& coords) : coords(coords){}

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
