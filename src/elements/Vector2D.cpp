#include <Vector2D.hpp>

Vector2D::Vector2D(const Dot &p) : Line(p, Dot(Fixed(0), Fixed(0))),
                                   tip(p), tail(Dot(Fixed(0), Fixed(0))) {}

Dot Vector2D::getTip(void) const {
    return this->tip;
}

Dot Vector2D::getTail(void) const {
    return this->tail;
}
