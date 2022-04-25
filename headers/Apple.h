/*!
\file
\brief Заголовочный файл с описанием класса Apple

Данный файл содержит в себе объявление методов и полей класса Apple
Объект класса Apple является яблоком
*/

#pragma once
#ifndef Apple_h
#define Apple_h
#include <SFML/Graphics.hpp>

class Apple
{
public:

    /**
     * @brief Конструктор нового объекта Apple
     * 
     */
    Apple();

    Apple(const Apple &rhs) = delete;

    ~Apple() = default;

    /**
     * @brief Генерация новых координат для объекта класса Apple
     * 
     */

    
    void generateNewApplePosition();

    /**
     * @brief Отрисовка яблока
     * 
     * @param window Окно, в котором будет отрисовка
     */
    void drawApple(sf::RenderWindow &window);

    /**
     * @brief Получение координат объекта класса Apple
     * 
     * @return Вектор с координатами
     */
    const sf::Vector2f getApplePosition() const;
private:

    /**
     * @brief Координаты объекта Apple
     * 
     */
    sf::Vector2f applePosition;

    /**
     * @brief Спрайт объекта Apple
     * 
     */
    sf::CircleShape sprite;
};

#endif /* Apple_h */