#ifndef INSERT_STATE_HPP
#define INSERT_STATE_HPP

#include "StateInterface.hpp"

class ModeStateMachine;

class InsertState : public StateInterface{
private:

public:
    ~InsertState() = default;
    void handleInput(ModeStateMachine& stateMachine, char c);
};

#endif