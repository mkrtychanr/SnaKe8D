#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(std::string path)
{
    std::string line;
    std::ifstream file(path);
    std::vector<std::vector<char>> map;

    if (file.is_open())
    {
        for (int i = 0; getline(file, line); i++)
        {
            map.push_back(std::vector<char> (0, 20));
            for (int j = 0; j < 20; j++)
            {
                if (line.length() <= j)
                {
                    map[i].push_back(' ');
                }
                else
                {
                    map[i].push_back(line[j]);
                }
            }
        }
    }
    else
    {
        std::cout<<"wrong file"<<std::endl;
    }

    _map = map;
}

void Map::drawMap(sf::RenderWindow &window)
{
    sf::RectangleShape tempShape;

    for (int i = 0; i < _map.size(); i++)
    {
        for (int j = 0 ; j < _map[i].size(); j++)
        {

            if (_map[i][j] == '1')
            {
                tempShape = sf::RectangleShape(sf::Vector2f(50, 50));
                tempShape.setPosition(j * 50, i * 50);
                tempShape.setFillColor(sf::Color(128, 128, 128));
                window.draw(tempShape);
            }

            if (_map[i][j] == '2')
            {
                tempShape = sf::RectangleShape(sf::Vector2f(50, 50));
                tempShape.setPosition(j * 50, i * 50);
                tempShape.setFillColor(sf::Color(128, 0, 128));
                window.draw(tempShape);
            }

            if (_map[i][j] == '3')
            {
                tempShape = sf::RectangleShape(sf::Vector2f(50, 50));
                tempShape.setPosition(j * 50, i * 50);
                tempShape.setFillColor(sf::Color::Blue);
                window.draw(tempShape);
            }

            if (_map[i][j] == '4')
            {
                tempShape = sf::RectangleShape(sf::Vector2f(50, 50));
                tempShape.setPosition(j * 50, i * 50);
                tempShape.setFillColor(sf::Color(1, 54, 61));
                window.draw(tempShape);
            }

            if (_map[i][j] == '5')
            {
                tempShape = sf::RectangleShape(sf::Vector2f(50, 50));
                tempShape.setPosition(j * 50, i * 50);
                tempShape.setFillColor(sf::Color::Yellow);
                window.draw(tempShape);
            }

            if (_map[i][j] == '6')
            {
                tempShape = sf::RectangleShape(sf::Vector2f(50, 50));
                tempShape.setPosition(j * 50, i * 50);               
                tempShape.setFillColor(sf::Color(71, 81, 95));
                window.draw(tempShape);
            }


        }
    }
}

bool Map::isBorder(sf::Vector2f snakeHeadPosition)
{
    if (_map[snakeHeadPosition.y/50][snakeHeadPosition.x/50] == '1')
    {
        return true;
    }
    return false;
}

const std::vector<char>& Map::operator[](int i) const
{
    return _map[i];
}

const int Map::size() const
{
    return _map.size();
}

void Map::show()
{
    for (int i = 0; i < _map.size(); i++)
    {
        for (int j = 0; j < _map[i].size(); j++)
        {
            std::cout<<_map[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}