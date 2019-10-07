#ifndef CAMERAH
#define CAMERAH
#define _USE_MATH_DEFINES //for M_PI

#include <math.h> //for M_PI
#include "ray.h"

class camera{
public: 
	camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect) {
		vec3 u, v, w;
		float theta = vfov * M_PI / 180;
		float halfHeight = tan(theta / 2);
		float halfWidth = aspect * halfHeight;
		origin = lookfrom;
		w = unitVector(lookfrom - lookat);
		u = unitVector(cross(vup, w));
		v = cross(w, u);
		lowerLeftCorner = origin - halfWidth*u -halfHeight*v - w;
		horizontal = 2*halfWidth*u;
		vertical = 2*halfHeight*v;
	}

	ray getRay(float s, float t) { return ray(origin, lowerLeftCorner + s * horizontal + t * vertical - origin); }

	vec3 origin;
	vec3 lowerLeftCorner;
	vec3 horizontal;
	vec3 vertical;
};
#endif