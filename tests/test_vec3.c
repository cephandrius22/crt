// test_vec3.c
#include <stdlib.h>
#include <check.h>
#include "../vec3.h"

// Test setup function
void setup(void) {}

// Test teardown function
void teardown(void) {}

// Unit tests
START_TEST(test_vec3_add) {
    vec3_t a = vec3_new(1.0, 2.0, 3.0);
    vec3_t b = vec3_new(4.0, 5.0, 6.0);

    vec3_t result = vec3_add(a, b);

    ck_assert_float_eq(result.x, 5.0);
    ck_assert_float_eq(result.y, 7.0);
    ck_assert_float_eq(result.z, 9.0);
}
END_TEST

START_TEST(test_vec3_sub) {
    vec3_t a = vec3_new(1.0, 2.0, 3.0);
    vec3_t b = vec3_new(4.0, 5.0, 6.0);

    vec3_t result = vec3_sub(a, b);

    ck_assert_float_eq(result.x, -3.0);
    ck_assert_float_eq(result.y, -3.0);
    ck_assert_float_eq(result.z, -3.0);
}
END_TEST

START_TEST(test_vec3_dot) {
    vec3_t a = vec3_new(1.0, 2.0, 3.0);
    vec3_t b = vec3_new(4.0, 5.0, 6.0);

    float result = vec3_dot(a, b);

    ck_assert_float_eq(result, 32.0);
}
END_TEST

START_TEST(test_vec3_cross) {
    vec3_t a = vec3_new(1.0, 2.0, 3.0);
    vec3_t b = vec3_new(4.0, 5.0, 6.0);

    vec3_t result = vec3_cross(a, b);

    ck_assert_float_eq(result.x, -3.0);
    ck_assert_float_eq(result.y, 6.0);
    ck_assert_float_eq(result.z, -3.0);
}
END_TEST

START_TEST(test_vec3_normalize) {
    vec3_t a = vec3_new(1.0, 2.0, 3.0);

    vec3_t result = vec3_normalize(a);

    ck_assert_float_eq_tol(result.x, 0.267, 0.001);
    ck_assert_float_eq_tol(result.y, 0.535, 0.001);
    ck_assert_float_eq_tol(result.z, 0.802, 0.001);
}
END_TEST

// Define the test suite
Suite *vec3_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("vec3");

    // Core test case
    tc_core = tcase_create("Core");
    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_vec3_add);
    tcase_add_test(tc_core, test_vec3_sub);
    tcase_add_test(tc_core, test_vec3_dot);
    tcase_add_test(tc_core, test_vec3_cross);
    tcase_add_test(tc_core, test_vec3_normalize);
    suite_add_tcase(s, tc_core);

    return s;
}

// Run the tests
int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = vec3_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
