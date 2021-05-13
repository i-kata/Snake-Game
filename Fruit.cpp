#include "Fruit.h"

Fruit::Fruit()
{
    fruitShape.setSize(sf::Vector2f(30, 30));
    fruitShape.setFillColor(sf::Color::Blue);
}

sf::RectangleShape Fruit::getShape()
{
    return fruitShape;
}

Location Fruit::getLocation()
{
    return fruitLoc;
}

void Fruit::moveFruit(std::vector<SnakeSegment> & vec)
{
    bool fruitMoved = false;

    while (fruitMoved == false)
    {
        int testLocX = (rand() % 19 + 1) * 30;
        int testLocY = (rand() % 19 + 1) * 30;
        bool noMatch = true;

        for (auto & s : vec)
        {
            if (s.getLocation().x == testLocX and s.getLocation().y == testLocY)
            {
                noMatch = false;
            }
        }

        if (noMatch == true)
        {
            fruitLoc.x = testLocX;
            fruitLoc.y = testLocY;
            fruitMoved = true;
            fruitShape.setPosition(fruitLoc.x, fruitLoc.y);
        }
    }
}