#include <iostream>
#include <vector>
#include "SnakeSegment.h"
#include "Fruit.h"
#include "GameController.h"

int main()
{
    GameController controller;
    bool gameRunning = true;

    sf::RenderWindow window(sf::VideoMode(600, 600), "Snake");
    std::vector<SnakeSegment> Snake;

    Location headLoc; headLoc.x = 270; headLoc.y = 270;
    SnakeSegment head(headLoc);
    Snake.emplace_back(head);

    Fruit fruit;
    fruit.moveFruit(Snake);

    window.setFramerateLimit(10);

    Location speed; speed.x = 0; speed.y = 0;

    sf::Event event;
    while (window.isOpen())
    {
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
        return 0;
    }
}
