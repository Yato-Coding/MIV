#ifndef MODESTATEMACHINE_HPP
#define MODESTATEMACHINE_HPP

#include "StateInterface.hpp"

class ModeStateMachine;


class DefaultState : public StateInterface{
private:
    int x{0};
    int y{0};
public:
    ~DefaultState() = default;
    void handleInput(ModeStateMachine& stateMachine, char c);
};

#endif