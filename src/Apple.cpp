#include "Apple.h"
#include <stdlib.h>

Apple::Apple()
{
    applePosition = sf::Vector2f(10 * 50, 5 * 50);
    sprite = sf::CircleShape(20);
    sprite.setFillColor(sf::Color::Red);
    sprite.setPosition(sf::Vector2f(10 * 50, 5 * 50));
}
void Apple::generateNewApplePosition()
{
    applePosition = sf::Vector2f((std::rand() % 18 + 1) * 50, (std::rand() % 18 + 1) * 50);
    sprite.setPosition(applePosition);
}

void Apple::drawApple(sf::RenderWindow &window)
{
    window.draw(sprite);
}

const sf::Vector2f Apple::getApplePosition() const
{
    return applePosition;
}