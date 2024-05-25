#ifndef MODESTATEMACHINE_HPP
#define MODESTATEMACHINE_HPP

#include "Coordinates.hpp"
#include "StateInterface.hpp"

class ModeStateMachine;


class DefaultState : public StateInterface{
private:
    Coordinates& coords;
public:
    ~DefaultState() = default;
    DefaultState(Coordinates& coords);
    void handleInput(ModeStateMachine& stateMachine, int c);
};

#endif
