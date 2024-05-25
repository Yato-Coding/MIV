#include "InsertState.hpp"
#include "ModeEnum.hpp"
#include "ModeStateMachine.hpp"
#include <ncurses.h>

InsertState::InsertState(GapBuffer& gapBuffer, Coordinates& coords) : gapBuffer(gapBuffer), coords(coords){}

void InsertState::calculateCursor(){
    if(coords.y >= coords.newLineIndices.size()){
        coords.y = coords.newLineIndices.size() - 1;
    }
    coords.cursorPosition = coords.x + coords.newLineIndices.at(coords.y);
}

void InsertState::handleInput(ModeStateMachine& stateMachine, const int c){
    calculateCursor();
    gapBuffer.moveCursor(coords.cursorPosition);
    switch(c){
        case 27: // ESC
            stateMachine.setState(State::DEFAULT);
            return;
        case 32: // SPACE
            gapBuffer.insertChar(' ');
            coords.x++;
            break;
        case 263: // BACKSPACE
            if(coords.cursorPosition > 0){
                gapBuffer.deleteChar();
                coords.x--;
            }
            break;
        case 10: // ENTER
            gapBuffer.insertChar(c);
            coords.newLineIndices.insert(coords.newLineIndices.begin() + coords.y + 1, coords.cursorPosition + 1);
            coords.x = 0;
            coords.y++;
            break;
        default:
            gapBuffer.insertChar(c);
            coords.x++;
    }
    clear();
    gapBuffer.displayBuffer();
    move(coords.y, coords.x);

}
