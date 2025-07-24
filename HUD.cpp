#include "HUD.hpp"
#include <string>

namespace CE
{
    HUD::HUD(GameDataRef data) : _data(data)
    {
        _scoreText.setFont(_data->assets.GetFont("Flappy Font"));
        _scoreText.setString("0");
        _scoreText.setCharacterSize(80);
        _scoreText.setFillColor(sf::Color::White);

        // Initial position in the top-right corner
        sf::FloatRect textBounds = _scoreText.getGlobalBounds();
        float margin = 50.0f;
        float posX = _data->window.getSize().x - textBounds.width - margin;
        float posY = margin;
        _scoreText.setPosition(posX, posY);
    }

    void HUD::Draw()
    {
        _data->window.draw(_scoreText);
    }

    void HUD::UpdateScore(int score)
    {
        _scoreText.setString(std::to_string(score));

        // Recalculate position after updating the text, since width may change
        sf::FloatRect textBounds = _scoreText.getGlobalBounds();
        float margin = 50.0f;
        float posX = _data->window.getSize().x - textBounds.width - margin;
        float posY = margin;
        _scoreText.setPosition(posX, posY);
    }
}
