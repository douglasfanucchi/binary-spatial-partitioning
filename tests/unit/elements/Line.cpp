#include <asserts.hpp>
#include <Line.hpp>

void test_should_create_line()
{
    Dot p1 = Dot(Fixed(0), Fixed(0));
    Dot p2 = Dot(Fixed(1), Fixed(1));
    Line line(p1, p2);

    Fixed angularCoefficient = line.getAngularCoefficient();
    Fixed linearCoefficient = line.getLinearCoefficient();

    ASSERT_TRUE(line.isFunction());
    ASSERT_TRUE(angularCoefficient == Fixed(1));
    ASSERT_TRUE(linearCoefficient == Fixed(0));
}

void test_should_create_line_parallel_to_y_axis()
{
    Dot p1(Fixed(1), Fixed(2));
    Dot p2(Fixed(1), Fixed(4));

    Line line(p1, p2);

    ASSERT_FALSE(line.isFunction());
}

void test_should_get_perpendicular_vector()
{
    Dot p1(Fixed(-20), Fixed(0));
    Dot p2(Fixed(0), Fixed(10));
    Line line(p1, p2);

    Vector2D v = line.getPerpendicularVector();

    ASSERT_TRUE(v.getTip() == Dot(Fixed(-4), Fixed(8)));
    ASSERT_TRUE(v.getTail() == ORIGIN);
}

void RUN_LINE_TEST_SUITE()
{
    test_should_create_line();
    test_should_create_line_parallel_to_y_axis();
    test_should_get_perpendicular_vector();
}
