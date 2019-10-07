#ifndef HITABLEH
#define HITABLEH

#include "ray.h"

class material; //forward declaration of a class, to avoid circular includes (class A including class B which includes class A etc.)

struct hitRecord {
	float t; 
	vec3 p;
	vec3 normal;
	material *matPtr;
};

class hitable {
public:
	virtual bool hit(const ray& r, float tmin, float tmax, hitRecord& rec) const = 0;
};

#endif