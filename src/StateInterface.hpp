#ifndef MODE
#define MODE
class ModeStateMachine;

class StateInterface{
public:
    virtual void handleInput(ModeStateMachine& stateMachine, char c) = 0;
};

#endif