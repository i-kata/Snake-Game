#include <iostream>
#include <vector>
#include <string>
#include "SnakeSegment.h"
#include "Fruit.h"
#include "GameController.h"

int main()
{
    GameController controller;
    bool gameRunning = false;

    sf::Texture texture;
    texture.loadFromFile("C:\\Users\\Iwan\\OneDrive\\Pulpit\\resources\\background.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Font font;
    font.loadFromFile("C:\\Users\\Iwan\\OneDrive\\Pulpit\\resources/font.ttf");
    sf::Text text;
    text.setFont(font);

    sf::RenderWindow window(sf::VideoMode(600, 600), "Snake");
    std::vector<SnakeSegment> Snake;

    Location headLoc; headLoc.x = 270; headLoc.y = 270;
    SnakeSegment head(headLoc);
    Snake.emplace_back(head);

    Fruit fruit;
    fruit.moveFruit(Snake);

    Location speed; speed.x = 0; speed.y = 0;

    sf::Event event;
    while (window.isOpen())
    {
        while (gameRunning == false)
        {
            sf::Event event1;
            controller.controlEventsGF(window, event1, gameRunning);
            window.clear();
            window.draw(sprite);
            window.display();
        }

        while (gameRunning)
        {
            controller.controlEvents(gameRunning, speed, event, window);

            for(size_t i = Snake.size() - 1; i > 0; i--)
            {
                Snake[i].update(Snake[i - 1].getLocation());
            }

            Snake[0].moveHead(speed);
            controller.collisionDetector(Snake, gameRunning);
            controller.foodPickedDetector(Snake, fruit);
            controller.overBoardDetector(Snake, gameRunning);
            window.clear();
            controller.draw(Snake, window);
            window.draw(fruit.getShape());
            window.display();
        }

        window.clear();
        text.setString( "Score: " + std::to_string(Snake.size() - 1) );
        text.setPosition(240, 270);
        window.draw(text);
        window.display();
        sf::Time time = sf::seconds(2);
        sf::sleep(time);
        Snake.clear();
        Snake.push_back(head);
        speed.x = 0; speed.y = 0;
    }
    return 0;
}
