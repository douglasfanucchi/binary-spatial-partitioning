#include <Dot.hpp>
#include <asserts.hpp>

void test_should_create_a_dot()
{
    Dot dot(Fixed(0), Fixed(1));

    ASSERT_TRUE(dot.getAbscissa() == Fixed(0));
    ASSERT_TRUE(dot.getOrdinates() == Fixed(1));
}

void test_should_compare_two_dots_as_equals()
{
    Dot p1(Fixed(2.5), Fixed(2.5)), p2(Fixed(2.5), Fixed(2.5));

    bool result = p1 == p2;

    ASSERT_TRUE(result);
}

void RUN_DOT_TEST_SUITE()
{
    test_should_create_a_dot();
    test_should_compare_two_dots_as_equals();
}
