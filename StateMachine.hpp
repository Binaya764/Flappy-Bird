#pragma once
#include<memory>
#include<stack>     // state is based on stack
#include "State.hpp"


namespace CE{
     typedef std::unique_ptr<State> StateRef;
     class StateMachine{
        public:
            StateMachine () {}           //constructor
            ~StateMachine () {}          //Destructor

            void AddState(StateRef newstate, bool isReplacing = true);                  //adds state on the stack
                                                                                        // which runs and everthing pauses
            void RemoveState();

            void ProcessStateChanges();

            StateRef &GetActiveState();
            bool IsEmpty() const;
        private:
            std::stack<StateRef> _states;
            StateRef _newState;

            bool _isRemoving;
            bool _isAdding;
            bool _isReplacing;
     };     
}