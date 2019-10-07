#ifndef MATERIALH
#define MATERIALH

#include "ray.h"
#include "hitable.h"

vec3 randomInUnitSphere() {
	vec3 p;
	do {
		p = 2.0f * vec3((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX) - vec3(1, 1, 1);
	} while (p.squaredLength() >= 1.0f);
	return p;
}

vec3 reflect(const vec3& v, const vec3& n) {
	return v - 2 * dot(v, n)*n;
}

class material {
public:
	virtual bool scatter(const ray& rIn, const hitRecord& rec, vec3& attenuation, ray& scattered) const = 0;
};

class lambertian : public material {
public:
	lambertian(const vec3& a) : albedo(a){}
	virtual bool scatter(const ray& rIn, const hitRecord& rec, vec3& attenuation, ray& scattered) const {
		vec3 target = rec.p + rec.normal + randomInUnitSphere();
		scattered = ray(rec.p, target - rec.p);
		attenuation = albedo;
		return true;
	}

	vec3 albedo;
};

class metal : public material {
public:
	metal(const vec3& a) : albedo(a) {}
	virtual bool scatter(const ray& rIn, const hitRecord& rec, vec3& attenuation, ray& scattered) const {
		vec3 reflected = reflect(unitVector(rIn.direction()), rec.normal);
		scattered = ray(rec.p, reflected);
		attenuation = albedo;
		return (dot(scattered.direction(), rec.normal) > 0);
	}

	vec3 albedo;
};
#endif