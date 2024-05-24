#include <ncurses.h>
#include "ModeStateMachine.hpp"
#include "DefaultState.hpp"
#include "InsertState.hpp"
#include "ModeEnum.hpp"

int main(){
    initscr();
    noecho();
    clear();
    printw("Hello World");
    refresh();
    DefaultState defaultState;
    InsertState insertState;
    ModeStateMachine stateMachine(State::DEFAULT, defaultState, insertState);
    while(true){
        stateMachine.handleStates();
    }
    endwin();
    return 0;
}

