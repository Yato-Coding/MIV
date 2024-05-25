#include <ncurses.h>
#include "GapBuffer.hpp"
#include "Coordinates.hpp"
#include "ModeStateMachine.hpp"
#include "DefaultState.hpp"
#include "InsertState.hpp"
#include "ModeEnum.hpp"


int main(){
    initscr();
    noecho();
    keypad(stdscr, TRUE); // Enable keypad mode to capture special keys
    clear();
    refresh();
    GapBuffer gapBuffer(5, 5);
    Coordinates coords{0, 0, 0};
    DefaultState defaultState(coords);
    InsertState insertState(gapBuffer, coords);
    ModeStateMachine stateMachine(State::DEFAULT, defaultState, insertState);
    while(true){
        stateMachine.handleStates();
        refresh();
    }
    endwin();
    return 0;
}
