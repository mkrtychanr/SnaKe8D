/*!
\file
\brief Заголовочный файл с описанием класса Map

Данный файл содержит в себе объявление методов и полей класса Map
Объект класса Map является картой игры
*/


#pragma once
#ifndef Map_h
#define Map_h
#include <SFML/Graphics.hpp>

class Map
{
public:

    Map() = delete;

    /**
     * @brief Конструктор объекта Map
     * 
     * @param path Путь к карте (map.txt)
     */
    Map(std::string path);
    

    Map(const Map &rhs) = delete;

    ~Map() = default;

    /**
     * @brief Отрисовка карты
     * 
     * @param window Окно, в котором будет отрисовка
     */
    void drawMap(sf::RenderWindow &window);

    /**
     * @brief Проверка на коллизию стены с головой змеи
     * 
     * @param snakeHeadPosition Координаты головы змеи
     * @return true - коллизия обнаружена - игра завершается
     * @return false - коллизии не обнаружена - игра продолжается
     */
    bool isBorder(sf::Vector2f snakeHeadPosition);

    /**
     * @brief Перегрузка опреатора []
     * 
     * @param i - строка матрицы _map
     * @return возращает ссылку на vector<char>
     */
    const std::vector<char>& operator[](int i) const;

    void show();

    /**
     * @brief Получение размера матрицы по Y(количество строк)
     * 
     * @return Количество строк 
     */
    const int size() const;


private:

    /**
     * @brief Матрица/карта
     * 
     */
    std::vector<std::vector<char>> _map;
};

#endif /* Map_h */