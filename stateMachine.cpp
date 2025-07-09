#include "StateMachine.hpp"
#include <iostream>
#include <cassert>

namespace CE {

    void StateMachine::AddState(StateRef newState, bool isReplacing) {                          //request new game state
        std::cout << "[StateMachine] Adding state, replacing? " << (isReplacing ? "Yes" : "No") << "\n";
        if (!newState) {
            std::cerr << "[StateMachine] WARNING: Attempt to add null state!\n";
            return;  
        }
        this->_isAdding = true;
        this->_isReplacing = isReplacing;
        this->_newState = std::move(newState);
    }

    void StateMachine::RemoveState() {
        std::cout << "[StateMachine] Marking state for removal\n";
        this->_isRemoving = true;
    }

    void StateMachine::ProcessStateChanges() {
        if (this->_isRemoving && !this->_states.empty()) {
            std::cout << "[StateMachine] Removing state\n";
            this->_states.pop();
            if (!this->_states.empty()) {
                this->_states.top()->Resume();
            }
            this->_isRemoving = false;
        }

        if (this->_isAdding) {
            if (!this->_states.empty()) {
                if (this->_isReplacing) {
                    std::cout << "[StateMachine] Replacing current state\n";
                    this->_states.pop();
                } else {
                    std::cout << "[StateMachine] Pausing current state\n";
                    this->_states.top()->pause();
                }
            }

            if (!_newState) {
                std::cerr << "[StateMachine] ERROR: _newState is null, cannot push\n";
                this->_isAdding = false;
                return;
            }

            std::cout << "[StateMachine] Pushing new state\n";
            this->_states.push(std::move(this->_newState));
            this->_states.top()->Init();
            this->_isAdding = false;
        }
    }

    StateRef& StateMachine::GetActiveState() {
        assert(!_states.empty() && "StateMachine::GetActiveState() called with empty state stack!");
        return this->_states.top();
    }
     bool CE::StateMachine::IsEmpty() const {
    return _states.empty();

}
}