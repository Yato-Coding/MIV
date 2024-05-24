#include "ModeEnum.hpp"
#include "ModeStateMachine.hpp"
#include "DefaultState.hpp"
#include "InsertState.hpp"
#include "ncurses.h"

ModeStateMachine::ModeStateMachine(State state, DefaultState &defaultState, InsertState &insertState) : state(state), defaultState(defaultState), insertState(insertState){}

void ModeStateMachine::handleStates(){
        switch(state){
            case State::INSERT:
                insertState.handleInput(*this, getch());
                break;
            case State::COMMANDS:
                break;
            case State::DEFAULT:
                defaultState.handleInput(*this, getch());
                break;
            default:
                break;
        }
    }

void ModeStateMachine::setState(State newstate){
    state = newstate;
}

