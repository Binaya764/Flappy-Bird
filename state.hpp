#pragma once  //prevents a header file from being included multiple times during the compilation process.
namespace CE{
    class state{
        public:
        virtual void Init()=0;                  //Initialize the state
        virtual void HandleInput() =0;          //Handles input in particular state
        virtual void Update()  =0;              //Updates after input from the user
        virtual void Draw(float dt) =0;         //Allows to create frame independent gameplay

        virtual void pause(){}                  //Pause the game
        virtual void Resume(){}                 //Called when paused the game
        virtual ~State() {}
    };
}




