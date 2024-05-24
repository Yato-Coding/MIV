#ifndef GAPBUFFER_HPP
#define GAPBUFFER_HPP

#include <vector>

struct Gap{
    int leftEdge;
    int rightEdge;
    int length;
}; 

class GapBuffer{
private:
    std::vector<char> buffer;
    Gap gap;

public:
    GapBuffer(int bufferLength, int gapLength);
    ~GapBuffer() = default;

    void insertChar(char c);
    void shrinkGap();
    void deleteChar();
    void extendGap();
    void moveCursor(int direction);
    void printBuffer();
    void drawBuffer();
    std::vector<char>& getBuffer() { return buffer; }
    Gap& getGap() { return gap; }
};

#endif
