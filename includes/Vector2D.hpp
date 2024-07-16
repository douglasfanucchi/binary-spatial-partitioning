#ifndef VECTOR_2D_H
# define VECTOR_2D_H

#include <Dot.hpp>
#include <Line.hpp>

class Vector2D : public Line {
    private:
        Dot tip, tail;

    public:
        Vector2D(const Dot&);
        Dot getTip(void) const;
        Dot getTail(void) const;
};

#endif