#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


int main()
{

    sf::RenderWindow gameWindow(sf::VideoMode(600, 600), "Snake");
    sf::RectangleShape snakeHead(sf::Vector2f(30.f, 30.f));
    snakeHead.setFillColor(sf::Color::Red);
    snakeHead.setPosition(300, 300);
    snakeHead.setOrigin(15, 15);
    float snakeSpeed = 0.02;
    float snakePosX = 20;
    float snakePosY = 20;

    gameWindow.setFramerateLimit(30);

    while (gameWindow.isOpen())
    {


        sf::Event event;

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

        }

        snakePosX += snakePosX * snakeSpeed;
        snakeHead.setPosition(snakePosX, snakePosY);
        std::cout << snakePosX << " ";

        gameWindow.clear();
        gameWindow.draw(snakeHead);
        gameWindow.display();
    }

    std::cout << "Hello World";
}