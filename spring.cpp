#include "spring.hpp"
#include "globals.hpp"

#include <cmath>

Spring::Spring()
{
    this->amortization = 0.95;
    this->rigidity = 0.01f;
    this->anchorPosition.x = rand()%SCREEN_WIDTH;
    this->anchorPosition.y = rand()%SCREEN_HEIGHT;
    this->velocity.x = 0;
    this->velocity.y = 0;

    this->position.x = this->anchorPosition.x;
    this->position.y = this->anchorPosition.y;
}

void Spring::updateSpring()
{
    float dx = this->anchorPosition.x - this->position.x;
    float dy = this->anchorPosition.y - this->position.y;

    this->velocity.x += (dx * this->rigidity);
    this->velocity.x *= this->amortization;

    this->velocity.y += (dy * this->rigidity);
    this->velocity.y *= this->amortization;

    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;
}