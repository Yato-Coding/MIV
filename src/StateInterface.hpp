#ifndef MODE
#define MODE
class ModeStateMachine;

class StateInterface{
public:
    virtual void handleInput(ModeStateMachine& stateMachine, int c) = 0;
};

#endif
