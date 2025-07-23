#include"Pipe.hpp"
#include<iostream>
namespace CE
{
    Pipe::Pipe( GameDataRef data): _data( data)
    {
        _landHeight= _data->assets.GetTexture("Land").getSize().y;
        _PipeSpawnYOffset=0;
    }
    //spawning pipes
        void Pipe::SpawnBottomPipe()
        {
            sf::Sprite sprite( _data->assets.GetTexture("Pipe Up"));
            sprite.setPosition( _data->window.getSize().x,
             _data->window.getSize().y-sprite.getGlobalBounds().height - _PipeSpawnYOffset);
        
             pipeSprites.push_back( sprite);
        }
        void Pipe::SpawnTopPipe()
        {
             sf::Sprite sprite( _data->assets.GetTexture("Pipe Down"));
            sprite.setPosition( _data->window.getSize().x,-_PipeSpawnYOffset);
             
             pipeSprites.push_back( sprite);
        }
        
         void Pipe::SpawnInvisiblePipe()
        {
             sf::Sprite sprite( _data->assets.GetTexture("Scoring Pipe"));
            sprite.setPosition( _data->window.getSize().x,-_PipeSpawnYOffset);
             
            sprite.setColor(sf::Color(0,0,0,0));
             pipeSprites.push_back( sprite);
        }

        void Pipe::SpawnScoringPipe()
        {
             sf::Sprite sprite( _data->assets.GetTexture("Scoring Pipe"));
            sprite.setPosition( _data->window.getSize().x,0);
        
             
             ScoringPipes.push_back( sprite);
        }

        void Pipe::MovePipes(float dt)
        {
            for(unsigned short int i=0; i< pipeSprites.size(); i++)
         {
            //Deletes pipes when it passes and is no longer visible on the screen
           if (pipeSprites.at(i).getPosition().x<0 - pipeSprites.at(i).getGlobalBounds().width){
            pipeSprites.erase(pipeSprites.begin()+ i);
            
           }
        

    else
        {
           float movement = PIPE_MOVEMENT_SPEED * dt;  //helps create frame independent gameplay
            
           pipeSprites.at(i).move( -movement, 0);
        }

        }
    
     for(unsigned short int i=0; i< ScoringPipes.size(); i++)
         {
            //Deletes pipes when it passes and is no longer visible on the screen
           if (ScoringPipes.at(i).getPosition().x<0 - ScoringPipes.at(i).getGlobalBounds().width){
            ScoringPipes.erase(ScoringPipes.begin()+ i);
            
           }
        

    else
        {
           float movement = PIPE_MOVEMENT_SPEED * dt;  //helps create frame independent gameplay
            
           ScoringPipes.at(i).move( -movement, 0);
        }

        }
    
    }
    
    void Pipe::DrawPipes()
    {
        for(unsigned short int i=0; i< pipeSprites.size(); i++)
        {
            _data->window.draw( pipeSprites.at(i));
        }
    }

    void Pipe::RandowmisePipeOffset()
    {
        _PipeSpawnYOffset= rand()%(_landHeight+1);  /* rand passes random value suppose 823
                                                        let land height be 200 then 
                                                        823 % 201 = 19   
                                                        so, the pipe offsets by 19 pixel*/
    }
     const std::vector<sf::Sprite> &Pipe::GetSprites() const
     {
        return pipeSprites;
     }

      std::vector<sf::Sprite> &Pipe::GetScoringSprites() 
     {
        return ScoringPipes;
     }
}