#include <Vector2D.hpp>

Vector2D::Vector2D(const Dot &p) : Line(p, Dot(Fixed(0), Fixed(0))),
                                   tip(p), tail(Dot(Fixed(0), Fixed(0))) {}


Vector2D::Vector2D(const Dot &tip, const Dot &tail) : Line(tip, tail), tip(tip), tail(tail) {}

Dot Vector2D::getTip(void) const {
    return this->tip;
}

Dot Vector2D::getTail(void) const {
    return this->tail;
}

Vector2D Vector2D::toOrigin(void) const {
    Dot tip = this->getTip(), tail = this->getTail();
    Dot newTip = Dot(
        Fixed(tip.getAbscissa() - tail.getAbscissa()),
        Fixed(tip.getOrdinates() - tail.getOrdinates())
    );
    return Vector2D(newTip);
}

Vector2D Vector2D::getPerpendicularVector(const Line &r) {
    Fixed a = r.getAngularCoefficient();
    Fixed b = r.getLinearCoefficient();
    Fixed root = Fixed(-1)*b/a;
    Fixed xPerpendicular = (root * b * b) / (root * root + b * b);
    Fixed yPerpendicular = a*xPerpendicular + b;

    return Vector2D(Dot(xPerpendicular, yPerpendicular));
}

Fixed Vector2D::operator*(const Vector2D &v) const {
    Vector2D thisOrigin = this->toOrigin();
    Vector2D vOrigin = v.toOrigin();

    return vOrigin.getTip().getAbscissa() * thisOrigin.getTip().getAbscissa() +
           vOrigin.getTip().getOrdinates() * thisOrigin.getTip().getOrdinates();
}

Fixed Vector2D::operator*(const Dot &p) const {
    return (*this) * Vector2D(p);
}
