#include <Vector2D.hpp>

Vector2D::Vector2D(const Dot &p) : tip(p), tail(Dot(Fixed(0), Fixed(0))) {}


Vector2D::Vector2D(const Dot &tip, const Dot &tail) : tip(tip), tail(tail) {}

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

Fixed Vector2D::operator*(const Vector2D &v) const {
    Vector2D thisOrigin = this->toOrigin();
    Vector2D vOrigin = v.toOrigin();

    return vOrigin.getTip().getAbscissa() * thisOrigin.getTip().getAbscissa() +
           vOrigin.getTip().getOrdinates() * thisOrigin.getTip().getOrdinates();
}

Fixed Vector2D::operator*(const Dot &p) const {
    return (*this) * Vector2D(p);
}
