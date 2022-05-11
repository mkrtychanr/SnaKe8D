/*!
\file
\brief Заголовочный файл с описанием класса Snake

Данный файл содержит в себе объявление методов и полей класса Snake
Объект класса Snake является змеей
*/


#pragma once
#ifndef Snake_h
#define Snake_h
#include "BodyShape.h"
#include "Map.h"
#include <vector>
#include <SFML/Graphics.hpp>
class Snake
{
public:

    /**
     * @brief Конструктор объекта Snake по умолчанию
     * 
     */
    Snake();
    ~Snake() = default;

    /**
     * @brief Отрисовка змеи
     * 
     * @param window Окно, в котором будет отрисовка
     */
    void drawSnake(sf::RenderWindow &window);

    /**
     * @brief Смена направления движения змеи
     * 
     * @param newDirection. Где 0 - вверх
     *                          1 - вправо
     *                          2 - вниз
     *                          3 - влево
     * @return true - если смена направления возможна
     * @return false - если смена направления невозможна
     */
    bool changeDirection(int newDirection);

    /**
     * @brief Увеличение змеи на один BodyShape
     * 
     */
    void eatApple();

    /**
     * @brief Проверка наличия BodyShape'ов змеи по координатам яблока
     * 
     * @param newApplePosition - координаты яблока
     * @return true - яблоко заспавнилось в месте, где есть змея
     * @return false - яблоко заспавнилось в месте, где нет змеи
     */
    bool snakeInPoint(sf::Vector2f newApplePosition);

    /**
     * @brief Проверка коллизии головы змеи с остальным ее телом
     * 
     * @return true - коллизия обнаружена - игра завершается
     * @return false - коллизии не обнаружено - игра продолжается
     */
    bool snakeInPointWithoutHead();

    void show();

    /**
     * @brief Движение змеи вперед по направлению
     * 
     * @param map Карта поля
     */
    void moveForward(const Map &map);

    /**
     * @brief Получение координат змеи в векторе SFML
     * 
     * @return Вектор SFML
     */
    const sf::Vector2f getSnakeHeadPosition() const;


private:

    /**
     * @brief Направление движения змеи
     * 0 - вверх
     * 1 - вправо
     * 2 - вниз
     * 3 - влево
     * 
     */
    int direction;
    int nextDirection;

    /**
     * @brief Вектор объектов BodyShape, которые составляют тело змеи
     * 
     */
    std::vector<BodyShape> body;
    sf::Vector2f lastBodyShapePosition;
    void swap(sf::Vector2f &a, sf::Vector2f &b);
};

#endif /* Shake_h */