#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Sphere.h"

using namespace std;

#define PI 3.14159265358979323846

	// Constructor
	Sphere::Sphere(float centerX, float centerY, float centerZ, float radius, int hseg, int vseg) {


		phi = 0.0f;
		theta = 0.0f;
		dphi = 2*PI/(vseg-1);
		dtheta = PI/(hseg-1);

		std::vector<float> vertices[hseg*vseg];
		std::vector<int> indices[hseg*vseg];
		std::vector<float> colors[hseg*vseg];
		std::vector<float> normals[hseg*vseg];
		std::vector<float> texCoords[hseg*vseg];
		
		
		//icoindices = new int[120];
		edge = new Edge[60];
		this->radius = radius;
		this->centerX = centerX;
		this->centerY = centerY;
		this->centerZ = centerZ;
	}

	void Sphere::UVSphere() {

		int i,j;

		dtheta = 2.0 * PI / (vseg - 1);	
		dphi = PI / (hseg - 1);

		for(i=0; i<hseg; i++) {

			theta += dtheta;

			for(j=0;j<vseg;j++) {

				phi += dphi;

				vertices[i*j] = centerX+( sin(phi)*radius * cos(theta)*radius);
				vertices[i*j+1] = centerY+sin(phi)*radius * sin(theta)*radius;
				vertices[i*j+2] = centerZ+cos(phi)*radius;

				cout << "Vertex 1: " << vertices[i*j] << "Vertex 2: "<< vertices[i*j+1] << "Vertex 3: " <<vertices[i*j+2] << "\n";

				indices[i*j] = i*j;
				indices[i*j+1] = i*j+1;
				indices[i*j+2] = i*j+2;

				cout << "Indice 1: " << indices[i*j] << "Indice 2: "<< indices[i*j+1] << "Indice 3: " <<indices[i*j+2] << "\n";


			}



		}

	}

	void Sphere::generateIcosahedron(float size) {

  	float phi = (1.0 + sqrt(5.0)) / 2.0;

	std::vector<float> icovertex{

		-1.0f,  phi,  0.0f,  1.0f,  phi,  0.0f, -1.0f, -phi,  0.0f, 
		 1.0f, -phi,  0.0f,  0.0f, -1.0f,  phi,  0.0f,  1.0f,  phi, 
		 0.0f, -1.0f, -phi,  0.0f,  1.0f , -phi, phi,  0.0f, -1.0f, 
		 phi,  0.0f,  1.0f, -phi,  0.0f, -1.0f, -phi,  0.0f,  1.0f
	
	};

	std::vector<int> icoindices{
		0, 11, 5,  0, 5,  1,  0, 1, 7,  0,  7, 10, 0, 10, 11,
        1, 5,  9,  5, 11, 4,  11,10,2,  10, 7, 6,  7, 1, 8,
        3, 9,  4,  3, 4,  2,  3, 2, 6,  3,  6, 8,  3, 8, 9,
        4, 9,  5,  2, 4,  11, 6, 2, 10, 8,  6, 7,  9, 8, 1
	};


    edge[0].a=0; edge[0].b=1;
	edge[1].a=0; edge[1].b=4;
	edge[2].a=0; edge[2].b=5;
	edge[3].a=0; edge[3].b=8;
	edge[4].a=0; edge[4].b=10;
	edge[5].a=1; edge[5].b=6;
	edge[6].a=1; edge[6].b=7;
	edge[7].a=1; edge[7].b=8;
	edge[8].a=1; edge[8].b=10;
	edge[9].a=2; edge[9].b=3;
	edge[10].a=2; edge[10].b=4;
	edge[11].a=2; edge[11].b=5;
	edge[12].a=2; edge[12].b=9;
	edge[13].a=2; edge[13].b=11;
	edge[14].a=3; edge[14].b=6;
	edge[15].a=3; edge[15].b=7;
	edge[16].a=3; edge[16].b=9;
	edge[17].a=3; edge[17].b=11;
	edge[18].a=4; edge[18].b=5;
	edge[19].a=4; edge[19].b=8;
	edge[20].a=4; edge[20].b=9;
	edge[21].a=5; edge[21].b=10;
	edge[22].a=5; edge[22].b=11;
	edge[23].a=6; edge[23].b=7;
	edge[24].a=6; edge[24].b=8;
	edge[25].a=6; edge[25].b=9;
	edge[26].a=7; edge[26].b=10;
	edge[27].a=7; edge[27].b=11;
	edge[28].a=8; edge[28].b=9;
	edge[29].a=10; edge[29].b=11;
	
	
	}

	float Sphere::getRadius() {
		return radius;
	}
	void Sphere::setRadius(float r) {
		radius = r;
	}

	Sphere::~Sphere() {
		
	}


