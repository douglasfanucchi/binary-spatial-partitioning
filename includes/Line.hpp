#ifndef LINE_H
#define LINE_H

#include <Dot.hpp>
#include <Fixed.hpp>
#include <Vector2D.hpp>

class Line {
    private:
        Fixed a, b;
        bool _isFunction;
    public:
        Line(const Dot&, const Dot&);
        Fixed getAngularCoefficient(void) const;
        Fixed getLinearCoefficient(void) const;
        bool isFunction(void) const;
        Vector2D getPerpendicularVector(void) const;
};

#endif