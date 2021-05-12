#include <iostream>
#include <vector>
#include "SnakeSegment.h"
#include "Fruit.h"
#include "GameController.h"

int main()
{
    GameController controller;
    bool gameRunning = true;
    int score = 0;

    sf::RenderWindow window(sf::VideoMode(600, 600), "Snake");
    std::vector<SnakeSegment> Snake;

    Location headLoc; headLoc.x = 270; headLoc.y = 270;
    SnakeSegment head(headLoc);
    Snake.push_back(head);

    Fruit fruit;
    fruit.moveFruit(Snake);

    window.setFramerateLimit(10);

    Location speed; speed.x = 0; speed.y = 0;

    sf::Event event;
    while (window.isOpen())
    {
        while (gameRunning)
        {

            Snake[0].moveHead(speed);

            controller.controlEvents(gameRunning, speed, event, window);

            controller.overBoardDetector(Snake, gameRunning);

            controller.foodPickedDetector(Snake, fruit, score);

            window.clear();
            controller.draw(Snake, window);
            window.draw(fruit.getShape());
            window.display();

        }
        return 0;
    }
}
