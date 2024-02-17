// vec3.h
#ifndef VEC3_H
#define VEC3_H

typedef struct {
    float x;
    float y;
    float z;
} vec3_t;

vec3_t vec3_new(float x, float y, float z);
vec3_t vec3_add(const vec3_t a, const vec3_t b);
vec3_t vec3_sub(const vec3_t a, const vec3_t b);
float vec3_dot(const vec3_t a, const vec3_t b);
vec3_t vec3_cross(const vec3_t a, const vec3_t b);
vec3_t vec3_normalize(const vec3_t v);
void vec3_print(const vec3_t v);

#endif // VEC3_H
