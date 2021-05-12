#include "GameController.h"
#include "iostream"

void GameController::controlEvents(bool & gameRunning, Location &speed, sf::Event &event, sf::RenderWindow & window)
{
    while (window.pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed:
                gameRunning = false;
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    speed.x = 0;
                    speed.y = -30;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    speed.x = 30;
                    speed.y = 0;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    speed.x = -30;
                    speed.y = 0;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    speed.x = 0;
                    speed.y = 30;
                }
        }
    }
}

void GameController::overBoardDetector(std::vector<SnakeSegment> Snake, bool & gameRunning)
{
    if (Snake[0].getLocation().x == 0 or Snake[0].getLocation().x == 600 or Snake[0].getLocation().y == 0 or Snake[0].getLocation().y == 600)
    {
        gameRunning = false;
        std::cout << "Game Over" << std::endl;
        std::cout << Snake.size() << std::endl;
    }
}

void GameController::draw(std::vector<SnakeSegment> Snake, sf::RenderWindow & window)
{
    for (auto &s : Snake)
        window.draw(s.getSegment());
}

void GameController::foodPickedDetector(std::vector<SnakeSegment> & Snake, Fruit &fruit, int & score)
{
    if (Snake[0].getLocation().x == fruit.getLocation().x and Snake[0].getLocation().y == fruit.getLocation().y)
    {
        score++;
        fruit.moveFruit(Snake);
        Location newSegLoc;
        newSegLoc.x = fruit.getLocation().x;
        newSegLoc.y = fruit.getLocation().y;

        SnakeSegment newSegment(newSegLoc);
        Snake.push_back(newSegment);
    }
}

