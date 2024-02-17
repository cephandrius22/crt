#include <stdio.h>
#include "vec3.h"

int
main(int argc, char *argv[])
{
	vec3_t v = {1, 1, 1};
	printf("%f %f %f\n", v.x, v.y, v.z);
	return 0;
}
