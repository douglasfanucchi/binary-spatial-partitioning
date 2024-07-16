#ifndef DOT_H
# define DOT_H

#include <Fixed.hpp>

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