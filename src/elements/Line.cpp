#include <Line.hpp>

Line::Line(const Dot &p1, const Dot &p2) {
    Fixed dy(p1.getOrdinates() - p2.getOrdinates());
    Fixed dx(p1.getAbscissa() - p2.getAbscissa());

    if (dx == 0) {
        this->_isFunction = false;
        return;
    }
    this->a = dy/dx;
    this->b = p1.getOrdinates() - this->a * p1.getAbscissa();
    this->_isFunction = true;
}

Fixed Line::getAngularCoefficient(void) const {
    return this->a;
}

Fixed Line::getLinearCoefficient(void) const {
    return this->b;
}

bool Line::isFunction(void) const {
    return this->_isFunction;
}

Vector2D Line::getPerpendicularVector(void) const {
    Fixed a = this->getAngularCoefficient();
    Fixed b = this->getLinearCoefficient();
    Fixed root = Fixed(-1)*b/a;
    Fixed xPerpendicular = (root * b * b) / (root * root + b * b);
    Fixed yPerpendicular = a*xPerpendicular + b;

    return Vector2D(Dot(xPerpendicular, yPerpendicular));
}
