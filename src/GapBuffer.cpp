#include "GapBuffer.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

GapBuffer::GapBuffer(int bufferLength, int gapLength) : buffer(bufferLength+gapLength), gap{0, gapLength-1, gapLength}{}

void GapBuffer::drawBuffer(){
    for(int i = 0; i < buffer.size(); i++){
        if(i < gap.leftEdge || i > gap.rightEdge){
            buffer[i] = '#';
        }
        else{
            buffer[i] = '*';
        }
    }
}

void GapBuffer::printBuffer(){
    drawBuffer();
    for(int i = 0; i < buffer.size(); i++){
        std::cout << buffer[i];
    }
    std::cout << std::endl;
}

void GapBuffer::moveCursor(int direction){
    switch(direction){
        case 0: // left
            if(gap.leftEdge > 0){
                gap.leftEdge--;
                gap.rightEdge--;
            }
            break;
        case 1:
            if(gap.rightEdge < buffer.size() - 1){
                gap.leftEdge++;
                gap.rightEdge++;
            }
            break;
        default:
            break;
    }
}

