// vec3.c
#include "vec3.h"
#include <stdio.h>
#include <math.h>

vec3_t vec3_new(float x, float y, float z) {
    vec3_t v = {.x = x, .y = y, .z = z};
    return v;
}

vec3_t vec3_add(const vec3_t a, const vec3_t b) {
    return vec3_new(a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3_t vec3_sub(const vec3_t a, const vec3_t b) {
    return vec3_new(a.x - b.x, a.y - b.y, a.z - b.z);
}

float vec3_dot(const vec3_t a, const vec3_t b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3_t vec3_cross(const vec3_t a, const vec3_t b) {
    return vec3_new(a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x);
}

vec3_t vec3_normalize(const vec3_t v) {
    float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return vec3_new(v.x / length, v.y / length, v.z / length);
}

void vec3_print(const vec3_t v) {
    printf("(%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}
