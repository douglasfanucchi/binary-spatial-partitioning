#ifndef VECTOR_2D_H
# define VECTOR_2D_H

#include <Dot.hpp>

class Vector2D {
    private:
        Dot tip, tail;

    public:
        Vector2D(const Dot&);
        Vector2D(const Dot&, const Dot&);
        Dot getTip(void) const;
        Dot getTail(void) const;
        Vector2D toOrigin(void) const;
        Fixed operator*(const Vector2D&) const;
        Fixed operator*(const Dot&) const;
        bool operator>(const Vector2D&) const;
};

#endif