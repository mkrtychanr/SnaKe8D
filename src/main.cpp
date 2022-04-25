#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "Snake.h"
#include "Map.h"
#include "Apple.h"
#include <string>

int main()
{
    std::string file("../map.txt");
    unsigned int movingTime = std::clock();
    unsigned int changeDirectionTime = std::clock();
    sf::RenderWindow window(sf::VideoMode(1000,1000), "SnaKe8D");
    Map map = Map(file);
    Snake snake = Snake();
    Apple apple = Apple();
    int lastDirection = 0;
    snake.changeDirection(0);
    snake.drawSnake(window);
    window.display();
    map.show();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (std::clock() - changeDirectionTime > 70000)
            {
                if (event.key.code == sf::Keyboard::W && event.type == sf::Event::KeyPressed && lastDirection != 0)
                {
                    if (snake.changeDirection(0))
                    changeDirectionTime = std::clock();
                    lastDirection = 0;
                }
                if (event.key.code == sf::Keyboard::D && event.type == sf::Event::KeyPressed && lastDirection != 1)
                {
                    if (snake.changeDirection(1))
                    changeDirectionTime = std::clock();
                    lastDirection = 1;
                }
                if (event.key.code == sf::Keyboard::S && event.type == sf::Event::KeyPressed && lastDirection != 2)
                {
                    if (snake.changeDirection(2))
                    changeDirectionTime = std::clock();
                    lastDirection = 2;
                }
                if (event.key.code == sf::Keyboard::A && event.type == sf::Event::KeyPressed && lastDirection != 3)
                {
                    if (snake.changeDirection(3))
                    changeDirectionTime = std::clock();
                    lastDirection = 3;
                }

            }
        }
        if (std::clock() - movingTime > 100000)
        {
            window.clear();
            movingTime = std::clock();
            snake.moveForward(map);
            if (snake.snakeInPointWithoutHead())
            {
                std::cout<<"1"<<std::endl;
                snake.show();
                window.close();
            }
            if (snake.getSnakeHeadPosition() == apple.getApplePosition())
            {
                snake.eatApple();
                while (snake.snakeInPoint(apple.getApplePosition()))
                {
                    apple.generateNewApplePosition();
                }
            }
            if (map.isBorder(snake.getSnakeHeadPosition()))
            {
                std::cout<<snake.getSnakeHeadPosition().x<<" "<<snake.getSnakeHeadPosition().y<<std::endl;
                std::cout<<"2"<<std::endl;
                window.close();
            }
            
            snake.drawSnake(window);
            map.drawMap(window);
            apple.drawApple(window);
        }
        window.display();
    }
}