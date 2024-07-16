#ifndef DOT_H
# define DOT_H

#include <Fixed.hpp>

class Dot {
    public:
        Dot(const Fixed&, const Fixed&);
        Fixed getAbscissa(void) const;
        Fixed getOrdinates(void) const;
};

#endif