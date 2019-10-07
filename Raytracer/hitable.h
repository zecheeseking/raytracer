#ifndef HITABLEH
#define HITABLEH

#include "ray.h"

struct hitRecord {
	float t; 
	vec3 p;
	vec3 normal;
};

class hitable {
public:
	virtual bool hit(const ray& r, float tmin, float tmax, hitRecord& rec) const = 0;
};

#endif