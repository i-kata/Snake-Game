#include <SFML/Graphics.hpp>
#include "Location.h"
#include "SnakeSegment.h"

#ifndef TEST_SFML_FRUIT_H
#define TEST_SFML_FRUIT_H

class Fruit
{
    sf::RectangleShape fruitShape;
    Location fruitLoc;

public:
    Fruit();
    sf::RectangleShape getShape();
    Location getLocation();
    void moveFruit(std::vector<SnakeSegment> vec);
};


#endif
