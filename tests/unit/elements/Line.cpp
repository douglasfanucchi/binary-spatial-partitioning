#include <asserts.hpp>
#include <Line.hpp>

void test_should_create_line()
{
    Dot p1 = Dot(Fixed(0), Fixed(0));
    Dot p2 = Dot(Fixed(1), Fixed(1));
    Line line(p1, p2);

    Fixed angularCoefficient = line.getAngularCoefficient();
    Fixed linearCoefficient = line.getLinearCoefficient();

    ASSERT_TRUE(angularCoefficient == Fixed(1));
    ASSERT_TRUE(linearCoefficient == Fixed(0));
}

void RUN_LINE_TEST_SUITE()
{
    test_should_create_line();
}
