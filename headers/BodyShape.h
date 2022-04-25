/*!
\file
\brief Заголовочный файл с описанием класса BodyShape

Данный файл содержит в себе объявление методов и полей класса BodyShape
Объект класса BodyShape является одной логической частью змеи
*/
#pragma once
#ifndef BodyShape_h
#define BodyShape_h
#include <SFML/Graphics.hpp>
#include <iostream>

class BodyShape
{
public:

    /**
     * @brief Спрайт объекта BodyShape
     * 
     */
    sf::RectangleShape sprite;

    /**
     * @brief Конструктор объекта BodyShape по координатам
     * 
     * @param x Координата абсцисс
     * @param y Координата ординат 
     */
    BodyShape(int x, int y);

    /**
     * @brief Конструктор объекта BodyShape по вектору SFML
     * 
     * @param newPoint Вектор SFML
     */
    BodyShape(sf::Vector2f newPoint);
    
    ~BodyShape() = default;

    /**
     * @brief Установка новой позиции объекта BodyShape по координатам
     * 
     * @param x Координата абсцисс
     * @param y Координата ординат
     */
    void setPosition(int x, int y);

    /**
     * @brief Установка новой позиции объекта BodyShape по вектору SFML
     * 
     * @param newPoint Вектор SFML
     */
    void setPosition(sf::Vector2f newPoint);

    /**
     * @brief Получение позиции объекта BodyShape по вектору SFML
     * 
     * @return Вектор SFML
     */
    const sf::Vector2f getPosition() const;

    /**
     * @brief Получение позиции объекта BodyShape по вектору SFML
     * 
     * @return Вектор SFML 
     */
    sf::Vector2f& getPosition();

    /**
     * @brief Передвижение объекта BodyShape вверх
     * 
     */
    void moveUp();

    /**
     * @brief Передвижение объекта BodyShape вправо
     * 
     */
    void moveRight();

    /**
     * @brief Передвижение объекта BodyShape вниз
     * 
     */
    void moveDown();

    /**
     * @brief Передвижение объекта BodyShape влево
     * 
     */
    void moveLeft();

private:

    /**
     * @brief Координаты объекта BodyShape
     * 
     */
    sf::Vector2f point;
};

#endif /* BodyShape_h */