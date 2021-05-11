#include <iostream>
#include <vector>
#include "SnakeSegment.h"
#include "Fruit.h"

int main()
{
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
            Snake[0].moveSegment(speed);

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

            if (Snake[0].getLocation().x == 0 or Snake[0].getLocation().x == 570 or Snake[0].getLocation().y == 0 or Snake[0].getLocation().y == 570)
            {
                gameRunning = false;
                std::cout << score << std::endl;
                std::cout << "Game Over" << std::endl;
            }

            if (Snake[0].getLocation().x == fruit.getLocation().x and Snake[0].getLocation().y == fruit.getLocation().y)
            {
                score++;
                fruit.moveFruit(Snake);
                Location newSegLoc;
                newSegLoc.x = Snake[Snake.size() - 1].getLocation().x;
                newSegLoc.y = Snake[Snake.size() - 1].getLocation().y;

                SnakeSegment newSegment(newSegLoc);
                Snake.push_back(newSegment);
            }

            window.clear();
            for (auto &s : Snake)
            {
                window.draw(s.getSegment());
            }
            window.draw(fruit.getShape());
            window.display();
        }
        return 0;
    }
}
