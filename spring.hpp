#ifndef SPRING_HPP
#define SPRING_HPP

#include "globals.hpp"

class Spring
{
    public:
        Coordinates position;
        Coordinates anchorPosition;
        float rigidity;
        float amortization;
        Coordinates velocity;
        Spring();
        void updateSpring();
};

#endif