#include <Dot.hpp>

Dot::Dot(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Fixed Dot::getAbscissa(void) const {
    return this->x;
}

Fixed Dot::getOrdinates(void) const {
    return this->y;
}
