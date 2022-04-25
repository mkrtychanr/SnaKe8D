#include "Snake.h"


//конструктор змеи
Snake::Snake()
{
    body.push_back(BodyShape(10, 10));
    body.push_back(BodyShape(10, 11));
    body.push_back(BodyShape(10, 12));
    body[0].sprite.setFillColor(sf::Color::Green);
    direction = 0;
}

//отрисовка змеи
void Snake::drawSnake(sf::RenderWindow &window)
{
    for (int i = 0; i < body.size(); i++)
    {
        window.draw(body[i].sprite);
    }
}

//изменение направления змеи
bool Snake::changeDirection(int newDirection)
{
    if ((direction == 0 && newDirection != 2) || (direction == 1 && newDirection != 3) || (direction == 2 && newDirection != 0) || (direction == 3 && newDirection != 1))
    {
        nextDirection = newDirection;
        return true;
    }
    return false;
}

//метод съедения яблока
void Snake::eatApple()
{
    body.push_back(BodyShape(lastBodyShapePosition));
}

//проверка присутствия змеи в заданной точке
bool Snake::snakeInPoint(sf::Vector2f newApplePosition)
{
    for (int i = 0; i < body.size(); i++)
    {
        if (body[i].getPosition() == newApplePosition)
        {
            return true;
        }
    }
    return false;
}

bool Snake::snakeInPointWithoutHead()
{
    for (int i = 1; i < body.size(); i++)
    {
        if (body[0].getPosition() == body[i].getPosition())
        {
            return true;
        }
    }
    return false;
}

//движение вперед по заданному направлению
void Snake::moveForward(const Map &map)
{
    direction = nextDirection;
    sf::Vector2f temp = body[0].getPosition();
    lastBodyShapePosition = body.back().getPosition();
    switch (direction)
    {
        case 0:
            body[0].moveUp();
            break;
        
        case 1:
            body[0].moveRight();
            break;
        
        case 2:
            body[0].moveDown();
            break;

        case 3: 
            body[0].moveLeft();
            break;

    }
    if (map[temp.y/50][temp.x/50] != ' ')
    {
        char position = map[temp.y/50][temp.x/50];
        if (map[temp.y/50][temp.x/50] == '0' && (temp.x/50 == 0 || temp.x/50 == 19) && (direction == 1 || direction == 3))
        {
            if (getSnakeHeadPosition().x == -1 * 50)
            {
                body[0].setPosition(19 * 50, getSnakeHeadPosition().y);
            }

            if (getSnakeHeadPosition().x == 20 * 50)
            {
                body[0].setPosition(0, getSnakeHeadPosition().y);
            }
        }
        else if (map[temp.y/50][temp.y/50] == '0' && (temp.y/50 == 0 || temp.y/50 == 19) && (direction == 0 || direction == 2))
        {
            if (getSnakeHeadPosition().y == -1 * 50)
            {
                body[0].setPosition(getSnakeHeadPosition().x, 19 * 50);
            }

            if (getSnakeHeadPosition().y == 20 * 50)
            {
                body[0].setPosition(getSnakeHeadPosition().x, 0);
            }
        }
        //else if (map[temp.y/50][temp.x/50] == '2' || )
        else if (position == '2' || position == '3' || position == '4' || position == '5')
        {
            sf::Vector2f enterPosition = sf::Vector2f(temp.y/50, temp.x/50);
            sf::Vector2f  exitPosition;
            for (int i = 0; i < map.size(); i++)
            {
                for (int j = 0; j < map[i].size(); j++)
                {
                    if (map[i][j] == position && (i != enterPosition.x || j != enterPosition.y))
                    {
                        exitPosition = sf::Vector2f(j, i);
                    }
                }
            }
            //std::cout<<"enterPosition x: "<<enterPosition.x<<"\ty: "<<enterPosition.y<<std::endl;
            //std::cout<<" exitPosition x: "<<exitPosition.x<<"\ty: "<<exitPosition.y<<std::endl;
            if (direction == 0)
            {
                body[0].setPosition(exitPosition.x * 50, (exitPosition.y - 1) * 50);
            }
            if (direction == 1)
            {
                body[0].setPosition((exitPosition.x + 1) * 50, exitPosition.y * 50);
            }
            if (direction == 2)
            {
                body[0].setPosition(exitPosition.x * 50, (exitPosition.y + 1) * 50);
            }
            if (direction == 3)
            {
                body[0].setPosition((exitPosition.x - 1) * 50, exitPosition.y * 50);
            }
        }
    }
    for (int i = 1; i < body.size(); i++)
    {
        swap(temp, body[i].getPosition());
        body[i].setPosition(body[i].getPosition());
    }
}

//вспомогательный метод для удобного перемещения координат змеи
void Snake::swap(sf::Vector2f &a, sf::Vector2f &b)
{
    sf::Vector2f temp = sf::Vector2f(a);
    a = sf::Vector2f(b);
    b = temp;
}


//вывод в консоль координаты змеи в настоящий момент
void Snake::show()
{
    std::cout<<"--------------------------------------------------"<<std::endl;
    for (int i = 0; i < body.size(); i++)
    {
        std::cout<<i<<"\tx: "<<int(body[i].getPosition().x)/50<<"\ty: "<<int(body[i].getPosition().y)/50<<std::endl;
    }
    std::cout<<"--------------------------------------------------"<<std::endl;
}

const sf::Vector2f Snake::getSnakeHeadPosition() const
{
    return body[0].getPosition();
}


