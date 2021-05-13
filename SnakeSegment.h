#include <SFML/Graphics.hpp>
#include "Location.h"

#ifndef TEST_SFML_SNAKESEGMENT_H
#define TEST_SFML_SNAKESEGMENT_H


class SnakeSegment
{
private:
    Location segmentLoc;
    sf::RectangleShape segment;

public:
    SnakeSegment(Location & loc);
    void moveHead(Location loc);
    sf::RectangleShape getSegment();
    Location getLocation();
    void update(Location loc);
};


#endif
