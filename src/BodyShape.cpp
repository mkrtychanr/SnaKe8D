#include "BodyShape.h"
#include <SFML/Graphics.hpp>


BodyShape::BodyShape(int x, int y)
{
    //50 на 50 -- размер квадрата
    sprite = sf::RectangleShape(sf::Vector2f(50, 50));
    //умножение на 50 для простоты воспринятия в конструкторе
    setPosition(x * 50, y * 50);
}

//конструктор по вектору
BodyShape::BodyShape(sf::Vector2f newPoint)
{
    sprite = sf::RectangleShape(sf::Vector2f(50, 50));
    setPosition(newPoint);
}

//смена позиции по координатам
void BodyShape::setPosition(int x, int y)
{
    point = sf::Vector2f(x, y);
    sprite.setPosition(point);
}

//смена позиции по вектору
void BodyShape::setPosition(sf::Vector2f newPoint)
{
    point = newPoint;
    sprite.setPosition(point);
}

//получение координат
const sf::Vector2f BodyShape::getPosition() const
{
    return point;
}

//получение координат
sf::Vector2f& BodyShape::getPosition()
{
    return point;
}

void BodyShape::moveUp()
{
    point -= sf::Vector2f(0, 50);
    sprite.setPosition(point);
}

void BodyShape::moveRight()
{
    point += sf::Vector2f(50, 0);
    sprite.setPosition(point);
}

void BodyShape::moveDown()
{
    point += sf::Vector2f(0, 50);
    sprite.setPosition(point);
}

void BodyShape::moveLeft()
{
    point -= sf::Vector2f(50, 0);
    sprite.setPosition(point);
}






