#include <iostream>
#include <cmath>
#include "circle.hpp"
#include "spring.hpp"

bool Circle::hasPointInside(Spring *points, int numberOfPoints, Spring **returnedPoint)
{
    for(int i = 0; i < numberOfPoints; ++i)
    {
        float dx = points[i].position.x - this->positionCenter.x;
        float dy = points[i].position.y - this->positionCenter.y;

        float distance = dx * dx + dy * dy;

        if(distance < this->radius * this->radius)
        {
            *returnedPoint = &points[i];
            return 1;
        }
    }
    return 0;
}

void Circle::resolveConflict(Spring *points, int numberOfPoints)
{
    Spring *returnPoint = NULL;
    for(int i = 0; i < numberOfPoints; ++i)
    {
        Spring *returnPoint = &points[i];

            float dx = returnPoint->position.x - this->positionCenter.x;
            float dy = returnPoint->position.y - this->positionCenter.y;

            float distance = sqrt(dx * dx + dy * dy);

        if(distance < this->radius)
        {
            if(distance == 0)
            {
                returnPoint->position.x = this->positionCenter.x + this->radius + 1.0f;
                continue;
            }
            
            float normalx = dx/distance;
            float normaly = dy/distance;

            float overlap = this->radius - distance;

            returnPoint->position.x += normalx * overlap;
            returnPoint->position.y += normaly * overlap;

            float dotProduct = (returnPoint->velocity.x * normalx) + (returnPoint->velocity.y * normaly);

            if(dotProduct < 0)
            {
                returnPoint->velocity.x -= dotProduct * normalx;
                returnPoint->velocity.y -= dotProduct * normaly;
            }
        }      
    }    
}

void Circle::moveCircle(Vector2 newPos)
{
    this->positionCenter.x = newPos.x;
    this->positionCenter.y = newPos.y;
}

