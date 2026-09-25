#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "globals.hpp"
#include "spring.hpp"
#include <raylib.h>

class Circle
{
    public:
        Coordinates positionCenter;
        Coordinates previousCenter;
        float mass;
        float radius;
        //bool hasPointInside(Spring *points, int numberOfPoints, Spring **returnPoint);
        void moveCircle(Vector2 newPos);
        void resolveConflict(Spring *points, int numberOfPoints);
};
#endif