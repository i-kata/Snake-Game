#ifndef TEST_SFML_GAMECONTROLLER_H
#define TEST_SFML_GAMECONTROLLER_H
#include "SnakeSegment.h"
#include "Fruit.h"

class GameController {
public:
    void foodPickedDetector(std::vector<SnakeSegment> & Snake, Fruit & fruit, int & score);
    void draw(std::vector<SnakeSegment> Snake, sf::RenderWindow & window);
    void controlEvents(bool & gameRunning, Location & speed, sf::Event & event, sf::RenderWindow & window);
    void overBoardDetector(std::vector<SnakeSegment> Snake, bool & gameRunning);
};


#endif
