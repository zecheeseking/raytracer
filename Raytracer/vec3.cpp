#include "vec3.h"

using namespace std;

inline istream& vec3::operator>>(istream &is, vec3 &t) {
	is >> t[0] >> t[1] >> t[2];
	return is;
}

inline ostream& vec3::operator<<(ostream &os, const vec3 &t) {
	os << t[0] << " " << t[1] << " " << t[2];
	return os;
}

inline vec3 vec3::operator+(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 vec3::operator-(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 vec3::operator*(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 vec3::operator/(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline vec3 vec3::operator*(float t, const vec3 &v) {
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 vec3::operator/(float t, const vec3 &v) {
	return vec3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

inline vec3 vec3::operator*(vec3 v, float t) {
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 vec3::dot(const vec3 &v1, const vec3 &v2) {
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 vec3::cross(const vec3 &v1, const vec3 &v2) {
	return vec3((v1.e[1]*v2.e[2] - v1.e[2]*v2.e[1]),
				(v1.e[0]*v2.e[2] - v1.e[2]*v2.e[0]),
				(v1.e[0]*v2.e[1] - v1.e[1]*v2.e[0]) );
}

inline void vec3::makeUnitVector() {
	float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline vec3& vec3::operator+=(const vec3 &v2){
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	
	return *this;
}

inline vec3& vec3::operator-=(const vec3 &v2){
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];

	return *this;
}

inline vec3& vec3::operator*=(const vec3 &v2){
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];

	return *this;
}

inline vec3& vec3::operator/=(const vec3 &v2){
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];

	return *this;
}

inline vec3& vec3::operator*=(const float t){
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;

	return *this;
}

inline vec3& vec3::operator/=(const float t){
	e[0] /= t;
	e[1] /= t;
	e[2] /= t;

	return *this;
}

inline void vec3::unitVector(vec3 v){
	return v / v.length();
}