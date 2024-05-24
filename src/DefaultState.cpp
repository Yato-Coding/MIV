#include "ModeEnum.hpp"
#include "ncurses.h"
#include "ModeStateMachine.hpp"
#include "DefaultState.hpp"


void DefaultState::handleInput(ModeStateMachine& stateMachine, char c){
    switch(c){
        case 'i':
            stateMachine.setState(State::INSERT);
            return;
        case ':':
            stateMachine.setState(State::COMMANDS);
            return;
        case 'l':
            clear();
            move(y, ++x);
            break;
        case 'h':
            clear();
            move(y, --x);
            break;
        case 'j':
            clear();
            move(++y, x);
            break;
        case 'k':
            clear();
            move(--y, x);
            break;
        default:
            clear();
            move(y, x);
            break;
    }
    refresh();
}
