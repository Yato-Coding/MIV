#ifndef INSERT_STATE_HPP
#define INSERT_STATE_HPP

#include "GapBuffer.hpp"
#include "Coordinates.hpp"
#include "StateInterface.hpp"

class ModeStateMachine;

class InsertState : public StateInterface{
private:
    GapBuffer& gapBuffer;
    Coordinates& coords;

public:
    ~InsertState() = default;
    InsertState(GapBuffer& gapBuffer, Coordinates& cursorPosition);
    void calculateCursor();
    void handleInput(ModeStateMachine& stateMachine, int c);
};

#endif
