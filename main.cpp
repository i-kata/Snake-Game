#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SnakeSegment.h"
#include <random>


int main()
{
    sf::RenderWindow gameWindow(sf::VideoMode(600, 600), "Snake");
    gameWindow.setFramerateLimit(30);

    Location starting;
    Location fruitLocation;
    starting.x = 100;
    starting.y = 200;
    std::vector<Location> snakeLocations;

    srand(time(nullptr));
    fruitLocation.x = rand() % 570 + 30;
    fruitLocation.y = rand() % 570 + 30;

    sf::RectangleShape snakeHead(sf::Vector2f(30.f, 30.f));
    snakeHead.setFillColor(sf::Color::Red);
    snakeHead.setPosition(starting.x, starting.y);
    sf::RectangleShape fruit(sf::Vector2f(30.f, 30.f));
    fruit.setFillColor(sf::Color::Blue);
    fruit.setPosition(fruitLocation.x, fruitLocation.y);

    snakeLocations.push_back(starting);

    while (gameWindow.isOpen())
    {
        sf::Event event;

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();
        }

        //std::cout << snakeLocations.size() << std::endl;

        gameWindow.clear();

        int i = 0;
        while (i != snakeLocations.size())
        {
            std::cout << i << std::endl;
            sf::RectangleShape snakeSegment(sf::Vector2f(30.f, 30.f));
            snakeSegment.setPosition(snakeLocations[i].x, snakeLocations[i].y);
            gameWindow.draw(snakeSegment);
            i++;
        }

        gameWindow.display();
    }
}