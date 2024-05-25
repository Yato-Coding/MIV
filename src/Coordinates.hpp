#ifndef CURSORPOSITION_HPP
#define CURSORPOSITION_HPP

#include <vector>

struct Coordinates{
    int x;
    int y;
    int cursorPosition;
    std::vector<int> newLineIndices{0};
};

#endif
