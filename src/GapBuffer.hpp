#ifndef GAPBUFFER_HPP
#define GAPBUFFER_HPP

#include <vector>

struct Gap{
    int leftEdge;
    int rightEdge;
    const int length;
    int currentLength = length;
}; 

class GapBuffer{
private:
    std::vector<char> buffer;
    Gap gap;

public:
    GapBuffer(int bufferLength = 0, int gapLength = 256);
    ~GapBuffer() = default;

    void createGap();
    void shrinkGap();
    void insertChar(char c);
    void deleteChar();
    void moveCursor(int cursorPosition);
    void displayBuffer();
    void printBuffer();
    void drawBuffer();

    // Getters, mostly for Testing Purposes
    std::vector<char>& getBuffer() { return buffer; }; 
    Gap& getGap() { return gap; }
    int getBufferLength(){return buffer.size() - gap.currentLength;}
};

#endif
