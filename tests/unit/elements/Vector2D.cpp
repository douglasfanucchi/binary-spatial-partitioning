#include <asserts.hpp>
#include <Vector2D.hpp>

void test_should_create_a_vector_located_at_origin()
{
    Dot p = Dot(Fixed(1), Fixed(1)), origin = Dot(Fixed(0), Fixed(0));
    Vector2D v(p);

    ASSERT_TRUE(v.getTip() == p);
    ASSERT_TRUE(v.getTail() == origin);
}

void test_should_create_a_vector_that_isnt_located_at_origin()
{
    Dot p1 = Dot(Fixed(5), Fixed(5)), p2 = Dot(Fixed(1), Fixed(1));

    Vector2D v(p1, p2);

    ASSERT_TRUE(v.getTip() == p1);
    ASSERT_TRUE(v.getTail() == p2);
}

void test_should_translate_vectors_to_origin()
{
    Vector2D v(Dot(Fixed(5), Fixed(5)), Dot(Fixed(1), Fixed(1)));
    
    Vector2D v_origin = v.toOrigin();

    ASSERT_TRUE(v_origin.getTip() == Dot(Fixed(4), Fixed(4)));
    ASSERT_TRUE(v_origin.getTail() == Dot(Fixed(0), Fixed(0)));


    Vector2D w(Dot(Fixed(1), Fixed(1)), Dot(Fixed(0), Fixed(0)));

    Vector2D w_origin = w.toOrigin();

    ASSERT_TRUE(w_origin.getTip() == Dot(Fixed(1), Fixed(1)));
    ASSERT_TRUE(w_origin.getTail() == Dot(Fixed(0), Fixed(0)));
}

void test_should_get_perpendicular_vector_to_a_line()
{
    Dot p1(Fixed(-20), Fixed(0));
    Dot p2(Fixed(0), Fixed(10));

    Vector2D v = Vector2D::getPerpendicularVector(Line(p1, p2));

    ASSERT_TRUE(v.getTip() == Dot(Fixed(-4), Fixed(8)));
    ASSERT_TRUE(v.getTail() == ORIGIN);
}

void test_should_compute_a_dot_product()
{
    Vector2D v(Dot(Fixed(-4), Fixed(8)));
    Vector2D w(Dot(Fixed(20), Fixed(10)));

    Fixed result = v * w;

    ASSERT_EQ(0, result.getRawBits());
}

void RUN_2D_VECTOR_TEST_SUITE()
{
    test_should_create_a_vector_located_at_origin();
    test_should_create_a_vector_that_isnt_located_at_origin();
    test_should_translate_vectors_to_origin();
    test_should_get_perpendicular_vector_to_a_line();
    test_should_compute_a_dot_product();
}
