#include "InsertState.hpp"
#include "ModeEnum.hpp"
#include "ModeStateMachine.hpp"

void InsertState::handleInput(ModeStateMachine& stateMachine, char c){
    switch(c){
        case 27:
            stateMachine.setState(State::DEFAULT);
            return;
        default:
            break;
    }
}