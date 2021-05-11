#include "SnakeSegment.h"

SnakeSegment::SnakeSegment(Location & loc) : segmentLoc(loc)
{
    segment.setSize(sf::Vector2f(30, 30));
    segment.setFillColor(sf::Color::Red);
    segment.setPosition(segmentLoc.x, segmentLoc.y);
}

void SnakeSegment::moveSegment(Location & loc)
{
    segmentLoc.x += loc.x;
    segmentLoc.y += loc.y;
    segment.setPosition(segmentLoc.x, segmentLoc.y);
}

sf::RectangleShape SnakeSegment::getSegment()
{
    return segment;
}

Location SnakeSegment::getLocation()
{
    return segmentLoc;
}
