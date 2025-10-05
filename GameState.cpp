#include <iostream>
#include "GameState.hpp"
#include "DEFINATIONS.hpp"
#include "GameOverState.hpp"

namespace CE {

    GameState::GameState(GameDataRef data) : _data(data) {}

    void GameState::Init()
    {
        if(!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
        {
            std::cout << "Error loading Hit Sound effect" << std::endl;
        }
        if(!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH))
        {
            std::cout << "Error loading Point Sound effect" << std::endl;
        }
        if(!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH))
        {
            std::cout << "Error loading Wing Sound effect" << std::endl;
        }

        _hitSound.setBuffer(_hitSoundBuffer);
        _pointSound.setBuffer(_pointSoundBuffer);
        _wingSound.setBuffer(_wingSoundBuffer);

        _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
        _data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        _data->assets.LoadTexture("Land", LAND_FILEPATH);
        _data->assets.LoadTexture("Bird frame 1", BIRD_FRAME_1_FILEPATH);
        _data->assets.LoadTexture("Bird frame 2", BIRD_FRAME_2_FILEPATH);
        _data->assets.LoadTexture("Bird frame 3", BIRD_FRAME_3_FILEPATH);
        _data->assets.LoadTexture("Bird frame 4", BIRD_FRAME_4_FILEPATH);
        _data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
        _data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

        pipe = new Pipe(_data);
        land = new Land(_data);
        bird = new Bird(_data);
        hud  = new HUD(_data);

        _background.setTexture(_data->assets.GetTexture("Game Background"));
        _score = 0;
        hud->UpdateScore(_score);
        _gameState = GameStates::eReady;
    }

    void GameState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _data->window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
                {
                    if (GameStates::eGameOver != _gameState)
                    {
                        _gameState = GameStates::ePlaying;
                        bird->Tap();
                        _wingSound.play();
                    }
                }
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    if(_data->input.IsSpriteClicked(_background, event, _data->window))
                    {
                        if (GameStates::eGameOver != _gameState)
                        {
                            _gameState = GameStates::ePlaying;
                            bird->Tap();
                            _wingSound.play();
                        }
                    }
                }
            }
        }
    }

    void GameState::Update(float dt)
    {
        if (GameStates::eGameOver != _gameState)
        {
            bird->Animate(dt);
            land->MoveLand(dt);
        }

        if (GameStates::ePlaying == _gameState)
        {
            pipe->MovePipes(dt);

            if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
            {
                pipe->SpawnBottomPipe();
                pipe->SpawnTopPipe();
                pipe->RandowmisePipeOffset();
                pipe->SpawnScoringPipe();
                clock.restart();
            }

            bird->Update(dt);

            std::vector<sf::Sprite> landSprites = land->GetSprites();
            for (std::size_t i = 0; i < landSprites.size(); i++)
            {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 2.50f, landSprites.at(i), 0.0f))
                {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                    _hitSound.play();
                }
            }

            std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
            for (std::size_t i = 0; i < pipeSprites.size(); i++)
            {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 2.50f, pipeSprites.at(i), 1.50f))
                {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                    _hitSound.play();
                }
            }

            std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprites();
            for (std::size_t i = 0; i < scoringSprites.size(); i++)
            {
                if (_gameState == GameStates::ePlaying &&
                    bird->GetSprite().getPosition().x > scoringSprites.at(i).getPosition().x &&
                    collision.CheckSpriteCollision(bird->GetSprite(), 2.50f, scoringSprites.at(i), 1.50f))
                {
                    _score++;
                    hud->UpdateScore(_score);
                    scoringSprites.erase(scoringSprites.begin() + i);
                    _pointSound.play();
                }
            }
        }

        if(GameStates::eGameOver == _gameState)
        {
            if(clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
            {
                _data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
            }
        }
    }

    void GameState::Draw(float dt)
    {
        _data->window.clear();

        _data->window.draw(_background);

        pipe->DrawPipes();
        land->DrawLand();
        bird->Draw();
        hud->Draw();

        _data->window.display();
    }
}
