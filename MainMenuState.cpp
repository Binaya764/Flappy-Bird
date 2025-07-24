#include <sstream>
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "DEFINATIONS.hpp"
#include <iostream>

namespace CE {
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
    }

    void MainMenuState::Init()
    {
        // Load textures
        _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
        _data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

        // Set textures to sprites
        _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
        _title.setTexture(this->_data->assets.GetTexture("Game Title"));
        _PlayButton.setTexture(this->_data->assets.GetTexture("Play Button"));

        // Position title and play button in center horizontally
        _title.setPosition(
            (SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2),
            _title.getGlobalBounds().height / 2
        );

        _PlayButton.setPosition(
            (SCREEN_WIDTH / 2) - (_PlayButton.getGlobalBounds().width / 2),
            (SCREEN_HEIGHT / 2) - (_PlayButton.getGlobalBounds().height / 2)
        );
    }

    void MainMenuState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _data->window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (_data->input.IsSpriteClicked(_PlayButton, event, _data->window))
                {
                    // Switch to GameState
                    _data->machine.AddState(StateRef(new GameState(_data)), true);
                }
            }
        }
    }

    void MainMenuState::Update(float dt)
    {
        // No update logic needed here for now
    }

    void MainMenuState::Draw(float dt)
    {
        _data->window.clear();

        _data->window.draw(_background);
        _data->window.draw(_title);
        _data->window.draw(_PlayButton);

        _data->window.display();
    }
}
