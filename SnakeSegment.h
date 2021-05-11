#include <SFML/Graphics.hpp>
#include "Location.h"

#ifndef TEST_SFML_SNAKESEGMENT_H
#define TEST_SFML_SNAKESEGMENT_H


class SnakeSegment
{
private:
    sf::RectangleShape segment;
    Location segmentLoc;

public:
    SnakeSegment(Location & loc);
    void moveSegment(Location & loc);
    sf::RectangleShape getSegment();
    Location getLocation();
};


#endif