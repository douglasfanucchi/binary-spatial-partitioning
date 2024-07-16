#ifndef VECTOR_2D_H
# define VECTOR_2D_H

#include <Dot.hpp>
#include <Line.hpp>

class Vector2D : public Line {
    private:
        Dot tip, tail;

    public:
        Vector2D(const Dot&);
        Vector2D(const Dot&, const Dot&);
        Dot getTip(void) const;
        Dot getTail(void) const;
        Vector2D toOrigin(void) const;
        static Vector2D getPerpendicularVector(const Line&);
};

#endif