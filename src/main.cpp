#include <iostream>
#include <vector>
#include <string>
#include <cmath>

//#include "types.h"
//#include "seuillage.h"
#include "filtrage.hpp"
#include "errors.hpp"

using namespace std;


void demande_infos(Image& image);


int main()
{
	Image image;
	
	demande_infos(image);
	
	
	Pixels ap_seuillage(image.nbL, vector<int>(image.nbC));
	seuillage(image, ap_seuillage);
	
	/*for(int i(0); i < image.nbL; ++i) {
		for(int j(0); j< image.nbC*3; ++j) {
			cout << image.pixels_ppm[i][j] << "	";
		}
		cout << endl;
	}*/
	
	Pixels ap_filtre(image.nbL, vector<int>(image.nbC*3));
	filtrage(ap_seuillage, image, ap_filtre);
	
	cout << image.format << endl
		 << image.nbC << " " << image.nbL << endl
		 << image.MAX << endl;
		 
	for (int i(0); i < image.nbL ; ++i) {
		for (int j(0); j < image.nbC*3; ++j) {
			cout << ap_filtre[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void demande_infos(Image& image)							
{
	
	int nbR;																	
	cin >> nbR;
	if ((nbR < 2) or ( nbR > 255)) {
		error_nbR(nbR);
	}
	image.nbR = nbR;
	
	Pixels pixel_tab (nbR+1 , vector<int> (3));
	pixel_tab[0][0] = 0;
	pixel_tab[0][1] = 0;
	pixel_tab[0][2] = 0;
	
	int id(1);
	for (size_t i(1); i < pixel_tab.size(); ++i){
		for (size_t j(0); j < 3; ++j){
			cin >> pixel_tab[i][j];
			if ((pixel_tab[i][j] < 0) or (pixel_tab[i][j] > 255)){
				error_color(id);
			}
		}
		++id;
	}
	image.pixel_tab = pixel_tab;
	
	
	vector<double> seuils(nbR);
	seuils[0]=0;
	double delta_seuil;
	for (size_t i(1); i < seuils.size(); ++i){
		cin >> seuils[i];
		delta_seuil = (seuils[i]+seuils[i-1])/2.0;
		if ((seuils[i] <= 0) or (seuils[i] >= 1) or (seuils[i] < seuils[i-1]) or (delta_seuil < 0.001)){
			error_threshold(seuils[i]);
		}
	}
	seuils.push_back(1);
	image.seuils = seuils;
	
	int nbF;
	cin >> nbF;
	if (nbF < 0){
		error_nb_filter(nbF);
	}
	image.nbF = nbF;

	string format;
	cin>> format;
	image.format = format;
	
	int nbC;
	cin >> nbC;
	image.nbC = nbC;
	
	int nbL;
	cin >> nbL;
	image.nbL = nbL;
	
	int MAX;
	cin >> MAX;
	image.MAX = MAX;
	
	
	Pixels pixels_ppm(nbL, vector<int>(nbC*3));
	for (int i(0); i < nbL; ++i) {
		for (int j(0); j < nbC*3; ++j) {
			cin >> pixels_ppm[i][j];
		}
	}
	image.pixels_ppm = pixels_ppm;
	
}
			
