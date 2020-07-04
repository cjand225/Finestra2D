#ifndef AABB_H
#define AABB_H

#include <SFML/Graphics.hpp>


class AABB {

public:
    AABB();

    ~AABB();

    AABB overlaps(AABB &otherBox);

    AABB contains(AABB &otherBox);

    AABB combine(AABB &otherBox);

    AABB intersects(AABB &otherBox);

    float getSurfaceArea();

    float getWidth();

    float getHeight();


private:
    float p1, p2, p3, p4;   //p2 - p1 = top, p3 - p2, = right, p3 - p4 = bottom, p4 - p1 = left
};


#endif // AABB_H
