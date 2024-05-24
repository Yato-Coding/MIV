#include <ncurses.h>
#include "ModeStateMachine.hpp"
#include "DefaultState.hpp"
#include "InsertState.hpp"
#include "ModeEnum.hpp"
#include "GapBuffer.hpp"

// int main(){
//     initscr();
//     noecho();
//     clear();
//     printw("Hello World");
//     refresh();
//     DefaultState defaultState;
//     InsertState insertState;
//     ModeStateMachine stateMachine(State::DEFAULT, defaultState, insertState);
//     while(true){
//         stateMachine.handleStates();
//     }
//     endwin();
//     return 0;
// }

int main(){
    GapBuffer buffer(10, 10);
    int i{0};
    while(i < 20){
        if(i < 10){
            buffer.printBuffer();
            buffer.moveCursor(1);
        }
        else{
            buffer.printBuffer();
            buffer.moveCursor(0);
        }
        i++;
    }

}
