#include "Bird.hpp"

namespace CE
{
    Bird::Bird(GameDataRef data) : _data(data)
    {
        _animationIterator = 0;

        // Load bird animation frames from asset manager
        _animationFrames.push_back(_data->assets.GetTexture("Bird frame 1"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird frame 2"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird frame 3"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird frame 4"));

        // Set initial bird sprite texture
        _birdSprite.setTexture(_animationFrames.at(_animationIterator));

        //setting position of the bird
        _birdSprite.setPosition((_data->window.getSize().x/4)-(_birdSprite.getGlobalBounds().width/2), 
        (_data->window.getSize().y/2) - (_birdSprite.getGlobalBounds().height/2));

        _birdState= BIRD_STATE_STILL;  //Sets the intial state to still

        sf::Vector2f Origin = sf::Vector2f(_birdSprite.getGlobalBounds().width/2,
         _birdSprite.getGlobalBounds().height/2);

         _birdSprite.setOrigin( Origin);
          _rotation = 0;

       
    }

    void Bird::Draw()
    {
        _data->window.draw(_birdSprite);
    }

    void Bird::Animate(float dt)
    {
        // Animate the bird if enough time has passed
        if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
        {
            _animationIterator = (_animationIterator + 1) % _animationFrames.size();
            _birdSprite.setTexture(_animationFrames.at(_animationIterator));
            _clock.restart();

            /*If _animationIterator was 3 and you have 4 frames:(3+1)%4=0
                    So it loops back to the first frame.*/

           /*Every 0.1 seconds, change the bird’s image to the next one in 
           the list, and loop back to the first frame when done.*/
        }
    }

    void Bird::Update(float dt)
    {
        if(BIRD_STATE_FALLING == _birdState)
        {
            _birdSprite.move(0, GRAVITY*dt);   //If the state is falling it moves downward due to gravity
            _rotation += ROTATION_SPEED* dt;

            if(_rotation> 25.0f)
            {
                _rotation= 25.0f;
            }
           

        }
        else if(BIRD_STATE_FLYING == _birdState)
        {
            _birdSprite.move(0, -FLYING_SPEED*dt);  //If the state is flying it moves upward with flying speed.
            _rotation -= ROTATION_SPEED*dt;

            if(_rotation < -25.0f)
            {
                _rotation = -25.0f;
            }

        }
         _birdSprite.setRotation( _rotation);

        if(_movementclock.getElapsedTime().asSeconds() > FLYING_DURATION)
        {
            _movementclock.restart();  //If the time interval is greater than o.25 then the clock resets and bird falls
            _birdState = BIRD_STATE_FALLING;
        }
    }

    void Bird::Tap()
    {
        _movementclock.restart();  //TO Know the accurate time since the click
        _birdState = BIRD_STATE_FLYING;
    }

     const sf:: Sprite &Bird::GetSprite() const
     {
        return _birdSprite;
     }
}
