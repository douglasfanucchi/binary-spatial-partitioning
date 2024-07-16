#include <Dot.hpp>
#include <asserts.hpp>

void test_should_create_a_dot()
{
    Dot dot(Fixed(0), Fixed(1));

    ASSERT_TRUE(dot.getAbscissa() == Fixed(0));
    ASSERT_TRUE(dot.getOrdinates() == Fixed(1));
}

void RUN_DOT_TEST_SUITE()
{
    test_should_create_a_dot();
}
