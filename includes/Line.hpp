#ifndef LINE_H
#define LINE_H

#include <Dot.hpp>
#include <Fixed.hpp>

class Line {
    private:
        Fixed a, b;
    public:
        Line(const Dot&, const Dot&);
        Fixed getAngularCoefficient(void) const;
        Fixed getLinearCoefficient(void) const;
};

#endif