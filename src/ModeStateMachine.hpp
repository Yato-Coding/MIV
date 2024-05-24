#ifndef MODE_STATE_MACHINE
#define MODE_STATE_MACHINE

#include "ModeEnum.hpp"

class DefaultState;
class InsertState;

class ModeStateMachine{
private:
    DefaultState &defaultState;
    InsertState &insertState;
    State state;
public:
    ModeStateMachine(State state, DefaultState &defaultState, InsertState &insertState);
    virtual ~ModeStateMachine() = default;
    void handleStates();
    void setState(State state);
};

#endif