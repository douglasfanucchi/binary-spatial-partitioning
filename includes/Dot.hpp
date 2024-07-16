#ifndef DOT_H
# define DOT_H

#include <Fixed.hpp>

#define ORIGIN Dot(Fixed(0), Fixed(0))

class Dot {
    private:
        const Fixed x, y;

    public:
        Dot(const Fixed&, const Fixed&);
        Fixed getAbscissa(void) const;
        Fixed getOrdinates(void) const;
        bool operator==(const Dot&) const;
};

#endif