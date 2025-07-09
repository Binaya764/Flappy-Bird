#include <iostream>
#include "SplashState.hpp"
#include "DEFINATIONS.hpp"
#include "MainMenuState.hpp"  // Make sure this exists

namespace CE {

    SplashState::SplashState(GameDataRef data) : _data(data) { }

    void SplashState::Init()
    {
        _data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assets.GetTexture("Splash State Background"));
    }

    void SplashState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _data->window.close();
        }
    }

    void SplashState::Update(float dt)
    {
        if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            std::cout << "Go To Main Menu" << std::endl;

            // Replace SplashState with MainMenuState
            _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }

    void SplashState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }
   
}


