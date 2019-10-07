// Raytracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "sphere.h"
#include "hitable_list.h"
#include "float.h"
#include "camera.h"
#include "material.h"

#include <iostream>
#include <fstream>

using namespace std;


vec3 colour(const ray& r, hitable *world, int depth) {
	hitRecord rec;
	if (world->hit(r, 0.001f, FLT_MAX, rec)) { //if hit detected, reflect randomly
		ray scattered;
		vec3 attenuation;
		if (depth < 50 && rec.matPtr->scatter(r, rec, attenuation, scattered)) {
			return attenuation * colour(scattered, world, depth + 1);
		}
		else
			return vec3(0, 0, 0);
	}
	else {
		vec3 unitDir = unitVector(r.direction());
		float t = 0.5*(unitDir.y() + 1.0f);
		return (1.0f - t)*vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f,0.7f,1.0f);
	}
}

int main()
{
	ofstream fs("firstRender.ppm");
	int nx = 200;
	int ny = 100;
	int ns = 100;
	fs << "P3\n" << nx << " " << ny << "\n255\n";
	hitable *list[5];
	list[0] = new sphere(vec3(0,0,-1), 0.5, new lambertian(vec3(0.8f, 0.3f, 0.3f)));
	list[1] = new sphere(vec3(0,-100.5,-1),100, new lambertian(vec3(0.8f, 0.8f, 0.0f)));
	list[2] = new sphere(vec3(1,0,-1), 0.5, new metal(vec3(0.8f, 0.6f, 0.2f)));
	list[3] = new sphere(vec3(-1, 0, -1), 0.5, new dielectric(1.5f));
	list[4] = new sphere(vec3(-1, 0, -1), -0.45, new dielectric(1.5f));
	hitable *world = new hitable_list(list,5);
	camera cam;
	for (int j = ny - 1; j >= 0; j--) { // for each row of pixels
		for (int i = 0; i < nx; i++) { // for each column of pixels
			vec3 col(0, 0, 0);
			for (int s = 0; s < ns; s++) { //samples per pixel
				float u = float(i + ((double)rand() / RAND_MAX)) / float(nx);
				float v = float(j + ((double)rand() / RAND_MAX)) / float(ny);
				ray r = cam.getRay(u, v);
				vec3 p = r.pointAtParameter(2.0);
				col += colour(r, world, 0);
			}
			col /= float(ns);
			col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);
			fs << ir << " " << ig << " " << ib << "\n";
		}
	}

	fs.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
