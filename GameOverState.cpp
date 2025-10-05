#include <iostream>
#include "GameOverState.hpp"
#include "DEFINATIONS.hpp"
#include "GameState.hpp"
#include <fstream>  // file handling

namespace CE {

    GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score) {}

    void GameOverState::Init()
    {
        _highScore = 0;

        // Read high score safely
        std::ifstream readFile("Resources/HighScore.txt");
        if(readFile.is_open())
        {
            readFile >> _highScore;
        }
        readFile.close();

        // Update high score if needed
        if(_score > _highScore)
        {
            _highScore = _score;

            std::ofstream writeFile("Resources/HighScore.txt");
            if(writeFile.is_open())
            {
                writeFile << _highScore;
            }
            writeFile.close();
        }

        _data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
        _data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
        _data->assets.LoadTexture("Retry Button", RETRY_BUTTON_FILEPATH);

        _background.setTexture(_data->assets.GetTexture("Game Over Background"));
        _gameOverTitle.setTexture(_data->assets.GetTexture("Game Over Title"));
        _gameOvercontainer.setTexture(_data->assets.GetTexture("Game Over Body"));
        _retryButton.setTexture(_data->assets.GetTexture("Retry Button"));

        // Center the container
        _gameOvercontainer.setPosition(
            (_data->window.getSize().x / 2.f) - (_gameOvercontainer.getGlobalBounds().width / 2.f),
            (_data->window.getSize().y / 2.f) - (_gameOvercontainer.getGlobalBounds().height / 2.f)
        );

        // Position title above container
        _gameOverTitle.setPosition(
            (_data->window.getSize().x / 2.f) - (_gameOvercontainer.getGlobalBounds().width / 1.5f),
            _gameOvercontainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 0.7f)
        );

        // Position retry button below container
        _retryButton.setPosition(
            (_data->window.getSize().x / 2.f) - (_gameOvercontainer.getGlobalBounds().width / 2.75f),
            _gameOvercontainer.getPosition().y + _gameOvercontainer.getGlobalBounds().height +
            (_retryButton.getGlobalBounds().height * 0.17f)
        );

        // Setup score text
        _scoreText.setFont(_data->assets.GetFont("Flappy Font"));
        _scoreText.setString(std::to_string(_score));
        _scoreText.setCharacterSize(56);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(
            _scoreText.getGlobalBounds().width / 2.f,
            _scoreText.getGlobalBounds().height / 2.f
        );
        _scoreText.setPosition(_data->window.getSize().x / 10.f * 7.25f, _data->window.getSize().y / 2.25f);

        // Setup high score text
        _highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
        _highScoreText.setString(std::to_string(_highScore));
        _highScoreText.setCharacterSize(56);
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(
            _highScoreText.getGlobalBounds().width / 2.f,
            _highScoreText.getGlobalBounds().height / 2.f
        );
        _highScoreText.setPosition(_data->window.getSize().x / 10.f * 7.25f, _data->window.getSize().y / 1.78f);
    }

    void GameOverState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _data->window.close();
            }
            // Use event-based click detection for retry button
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if(_data->input.IsSpriteClicked(_retryButton, event, _data->window))
                {
                    _data->machine.AddState(StateRef(new GameState(_data)), true);
                }
            }
        }
    }

    void GameOverState::Update(float dt)
    {
        
    }

    void GameOverState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_gameOverTitle);
        _data->window.draw(_gameOvercontainer);
        _data->window.draw(_retryButton);
        _data->window.draw(_scoreText);
        _data->window.draw(_highScoreText);
        _data->window.display();
    }
}
