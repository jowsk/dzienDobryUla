#include <iostream>
#include <vector>
#include <cmath>

#include "types.hpp"

using namespace std;


Intensite color_int_norm(const Image& image, Intensite& in)												// calcule l'intensité normalisée de chaque pixel//
{
	//Intensite in(image.nbL, vector<double>(image.nbC*3));
	
	//cout << "debut in" << endl;
	for (int i(0); i < image.nbL; ++i) {
		for (int j(0); j < (image.nbC*3); j += 3) {
			int max(255);
			int R(image.pixels_ppm[i][j]);
			int V(image.pixels_ppm[i][j+1]);
			int B(image.pixels_ppm[i][j+2]);
			int c;
			c = j/3;
			in[i][c] =(sqrt(R*R+V*V+B*B))/(sqrt(3)*max);
			//cout << in[i][c] << " " << endl;
		}
	}
	//cout << "fin in" << endl;
	return in;
}



void seuillage(/*Intensite& in,*/ const Image& image, Pixels& ap_seuillage)				// attribue un code couleur aux pixels selon leur intensité//
{
	Intensite in(image.nbL, vector<double>(image.nbC*3));
	
	color_int_norm(image, in);
	
	//cout << "debut du code color" << endl;
	
	//Pixels color_nb(image.nbL, vector<int>(image.nbC));
	
	for (int i(0); i < image.nbL ; ++i) {
		for (int j(0); j < image.nbC ; j+= 1) {
			for (int m(1); m <= (image.nbR); ++m) {
				/*if (in[i][j] == 0 ){
					ap_seuillage[i][j] = 0;
				} else*/ 
				if (m == image.nbR) {
					if ((image.seuils[m-1] <= in[i][j]) and (image.seuils[m] >= in[i][j])){
						ap_seuillage[i][j] = m;
					}
				}else if ((image.seuils[m-1] <= in[i][j]) and (image.seuils[m] > in[i][j])){
					ap_seuillage[i][j] = m;
					//cout << ap_seuillage[i][j] << "	";
				} else {
					continue;
				}
			}
		}
	}
	//cout << "fin du code color" << endl<< endl;
	//return color_nb;
}

/*void seuillage(const Image& image, Pixels& ap_seuillage)
{
	//Pixels ap_seuillage(image.nbL, vector<int>(image.nbC));
	//Pixels color_nb(image.nbL, vector<int>(image.nbC));
	
	//ap_seuillage = code_color(in(image), image);
	//return ap_seuillage;
	//Intensite in(image.nbL, vector<double>(image.nbC*3));
	
	code_color(in, image, ap_seuillage);
	

}*/

