#include "Game.hpp"
#include "SplashState.hpp"
#include "MainMenuState.hpp"  

namespace CE {

    Game::Game(int width, int height, std::string title)
    : _data(std::make_shared<GameData>())
    {
        // Create the game window
        _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

        
        _data->machine.AddState(StateRef(new SplashState(_data)), true);

        
        _data->machine.ProcessStateChanges();

        

        // Start the game loop
        Run();
    }

    void Game::Run()
    {
        float newTime, frameTime;
        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->window.isOpen())
        {
            // Process any pending state changes (push, pop, replace)
            this->_data->machine.ProcessStateChanges();

            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            
            if (frameTime > 0.25f)
                frameTime = 0.25f;

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt)
            {
                // Make sure active state exists before calling methods
                if (!this->_data->machine.IsEmpty())
                {
                    this->_data->machine.GetActiveState()->HandleInput();
                    this->_data->machine.GetActiveState()->Update(dt);
                }
                accumulator -= dt;
            }

            float interpolation = accumulator / dt;

            if (!this->_data->machine.IsEmpty())
            {
                this->_data->machine.GetActiveState()->Draw(interpolation);
            }
        }
    }
}
