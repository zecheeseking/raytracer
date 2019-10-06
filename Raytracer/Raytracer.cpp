// Raytracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "vec3.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fs("firstRender.ppm");
	int nx = 200;
	int ny = 100;
	fs << "P3\n" << nx << " " << ny << " 255\n";
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			vec3 col(float(i)/float(nx), float(j)/float(ny), 0.2);
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
