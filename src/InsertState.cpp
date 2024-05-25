#include "InsertState.hpp"
#include "ModeEnum.hpp"
#include "ModeStateMachine.hpp"
#include <ncurses.h>

InsertState::InsertState(GapBuffer& gapBuffer, Coordinates& coords) : gapBuffer(gapBuffer), coords(coords){}

void InsertState::handleInput(ModeStateMachine& stateMachine, const int c){
    gapBuffer.moveCursor(coords.cursorPosition);
    switch(c){
        case 27: // ESC
            stateMachine.setState(State::DEFAULT);
            return;
        case 32: // SPACE
            gapBuffer.insertChar(' ');
            coords.cursorPosition++;
            break;
        case 263: // BACKSPACE
            if(coords.cursorPosition > 0){
                gapBuffer.deleteChar();
                coords.cursorPosition--;
            }
            break;
        default:
            gapBuffer.insertChar(c);
            coords.cursorPosition++;
    }
    clear();
    gapBuffer.displayBuffer();
    move(coords.y, coords.cursorPosition);

}
