#include "GameController.h"
#include "iostream"

void GameController::controlEvents(bool & gameRunning, Location &speed, sf::Event &event, sf::RenderWindow & window)
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
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
                break;

            default:
                break;
        }
    }
}

void GameController::overBoardDetector(std::vector<SnakeSegment> Snake, bool & gameRunning)
{
    if (Snake[0].getLocation().x < 0 or Snake[0].getLocation().x == 600 or Snake[0].getLocation().y < 0 or Snake[0].getLocation().y == 600)
    {
        gameRunning = false;
        std::cout << "Game Over" << std::endl;
        std::cout << "Score: " << Snake.size() - 1 << std::endl;
    }
}

void GameController::draw(std::vector<SnakeSegment> & Snake, sf::RenderWindow & window)
{
    for (auto &s : Snake)
    {
        window.draw(s.getSegment());
    }
}

void GameController::foodPickedDetector(std::vector<SnakeSegment> & Snake, Fruit &fruit)
{
    if (Snake[0].getLocation().x == fruit.getLocation().x and Snake[0].getLocation().y == fruit.getLocation().y)
    {
        Location newSegLoc;
        newSegLoc.x = fruit.getLocation().x;
        newSegLoc.y = fruit.getLocation().y;
        fruit.moveFruit(Snake);

        SnakeSegment newSegment(newSegLoc);
        Snake.emplace_back(newSegment);
    }
}

void GameController::collisionDetector(std::vector<SnakeSegment> &Snake, bool & gameRunning)
{
    for (size_t i = 1; i < Snake.size(); i++)
    {
        if (Snake[0].getLocation().x == Snake[i].getLocation().x and Snake[0].getLocation().y == Snake[i].getLocation().y)
            gameRunning = false;
    }
}

void GameController::controlEventsGF(sf::RenderWindow &window, sf::Event &event1, bool &gameRunning)
{
    while (window.pollEvent(event1))
    {
        switch (event1.type)
        {
            case sf::Event::Closed:
            {
                window.close();
                exit(0);
            }

            case sf::Event::MouseButtonPressed:
            {
                int mouseX = event1.mouseButton.x;
                int mouseY = event1.mouseButton.y;

                if (event1.mouseButton.button == sf::Mouse::Left)
                {
                    if (mouseX > 200 and mouseX < 400 and mouseY > 200 and mouseY < 250)
                    {
                        gameRunning = true;
                        window.setFramerateLimit(5);
                    }

                    if (mouseX > 150 and mouseX < 430 and mouseY > 340 and mouseY < 400)
                    {
                        gameRunning = true;
                        window.setFramerateLimit(7);
                    }

                    if (mouseX > 200 and mouseX < 400 and mouseY > 470 and mouseY < 550)
                    {
                        gameRunning = true;
                        window.setFramerateLimit(9);
                    }
                }
                break;
            }
            default:
                break;
        }
    }
}


