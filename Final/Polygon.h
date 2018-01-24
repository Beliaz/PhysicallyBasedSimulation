//
// Created by ivan on 16/01/18.
//

#ifndef PHYSICALLYBASEDSIMULATION_POLYGON_H
#define PHYSICALLYBASEDSIMULATION_POLYGON_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Vec2.h"

static const Vector2 gravity = Vector2(0, 9.81);

class polygon 
{
public:
    polygon(const Vector2& center, std::vector<Vector2> points);

    static polygon create_rectangle(const Vector2 pos, const Vector2 scale);
    static polygon create_line(const Vector2 start, const Vector2 end);
    static polygon create_circle(const Vector2 center, const double radius);
    static polygon create_random(const Vector2 center, const size_t vertex_count);

    void update(double dt);

    const sf::ConvexShape& get_shape() const { return shape_; }

    void increase(double dt);

    void enable();

    friend std::ostream& operator<<(std::ostream& os, const polygon& p);

private:
    sf::ConvexShape shape_;
    Vector2 velocity_;
    bool enabled_;
};

#endif //PHYSICALLYBASEDSIMULATION_POLYGON_H
