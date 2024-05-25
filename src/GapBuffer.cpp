#include "GapBuffer.hpp"
#include <cmath>
#include <ncurses.h>
#include <ostream>
#include <stdexcept>
#include <vector>
#include <iostream>

GapBuffer::GapBuffer(int bufferLength, int gapLength)
    : buffer(bufferLength + gapLength), 
    gap{0, gapLength - 1, gapLength}
{

    if (gapLength <= 0)
    {
        throw std::invalid_argument("gapLength must be non-negative and non-zero");
    }
}

void GapBuffer::createGap() {
    const int newGapSize = gap.length;
    int insertPosition = gap.leftEdge + 1;

    buffer.insert(buffer.begin() + insertPosition, newGapSize, ' ');

    gap.currentLength = newGapSize;
    gap.rightEdge = gap.leftEdge + newGapSize - 1;
}

void GapBuffer::shrinkGap(){
    gap.leftEdge++;
    if(gap.currentLength > 1){
        gap.currentLength--;
    }
    else{
        createGap();
    }
    
}

void GapBuffer::insertChar(char c){
    buffer.at(gap.leftEdge) = c;
    shrinkGap();
}

void GapBuffer::deleteChar(){
    if(gap.leftEdge > 0){
        gap.leftEdge--;
        gap.currentLength++;
    }
    for(int i{0}; i < gap.currentLength; i++){
        buffer.at(gap.leftEdge+i) = ' ';
    }
}

void GapBuffer::moveCursor(int cursorPosition){
    if(cursorPosition >= 0 && cursorPosition <= getBufferLength()){
        if(cursorPosition < gap.leftEdge){
            int moveDistance = gap.leftEdge - cursorPosition;
            for(int i{0}; i < moveDistance; i++){
                buffer.at(gap.rightEdge- i) = buffer.at(gap.leftEdge - 1 - i); 
                buffer.at(gap.leftEdge- 1 - i) = ' ';
            }
        }
        else if(cursorPosition > gap.leftEdge){
            int moveDistance = cursorPosition - gap.leftEdge;
            for(int i{0}; i < moveDistance; i++){
                buffer.at(gap.leftEdge + i) = buffer.at(gap.rightEdge + 1 + i);
                buffer.at(gap.rightEdge + 1 + i) = ' ';
            }
        }
        gap.leftEdge = cursorPosition;
        gap.rightEdge = gap.leftEdge + gap.currentLength-1;
    }
    else{
        throw std::invalid_argument("Invalid cursor position");
    }
}


void GapBuffer::displayBuffer(){
    for(int i = 0; i < buffer.size(); i++){
        if(i < gap.leftEdge || i > gap.rightEdge){
            printw("%c", buffer.at(i));
        }
    }
}

void GapBuffer::printBuffer(){
    drawBuffer();
    for(int i = 0; i < buffer.size(); i++){
        std::cout << buffer.at(i);
    }
    std::cout << '\n';
}

void GapBuffer::drawBuffer(){
    for(int i = 0; i < buffer.size(); i++){
        if(i < gap.leftEdge || i > gap.rightEdge){
            buffer[i] = (buffer[i] != '!') ? '#' : buffer[i];
        }
        else{
            buffer[i] = '*';
        }
    }
}
