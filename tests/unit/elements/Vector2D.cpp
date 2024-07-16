#include <asserts.hpp>
#include <Vector2D.hpp>

void test_should_create_a_vector_located_at_origin()
{
    Dot p = Dot(Fixed(1), Fixed(1)), origin = Dot(Fixed(0), Fixed(0));
    Vector2D v(p);

    ASSERT_TRUE(v.getTip() == p);
    ASSERT_TRUE(v.getTail() == origin);
}

void RUN_2D_VECTOR_TEST_SUITE()
{
    test_should_create_a_vector_located_at_origin();
}
