#include <iostream>
#include <vector>
#include <cmath>

//#include "types.hpp"
#include "filtrage.hpp"
#include "seuillage.hpp"

using namespace std;


int color6(/*const*/ Pixels& ap_seuillage, const Image& image, int l, int c)  // l le numéro de ligne du pixel, c le numéro de colonne du pixel// // ne prend que des pixels, qui ne sont pas sur le bord //
{
	vector<int> color(image.nbR);
	
	/*for (int i(0); i< image.nbL; ++i) {
		for (int j(0); j< image.nbC; ++j) {
			cout << ap_seuillage[i][j] << "	" << endl;
		}
	}*/
	
	for (int colRed(0); colRed < image.nbR; ++colRed) {				//dans un vecteur color on met les couleurs qui apparaissent autour du pixel// 
		for (int i(l-1); i <= (l+1); ++i) {
			for (int j(c-1); j <= (c+1); ++j) {
					//cout << ap_seuillage.at(i).at(j) << endl;
					if (ap_seuillage[i][j] == colRed){
						color.at(colRed)+= 1;	
						//cout << "done1" << endl;				// on compte le nombre de fois que la couleur apparait//
					}
				}
				
			}
		//cout << "done2" << endl;
	}
	
	
	for (size_t i(0); i < color.size(); ++i){
		if (color[i] >= 6) {
			return color[i];								// si une coleur est trouvée au moins 6 fois alors le la couleur du pixel est convertie//
		}
	}
	
	return ap_seuillage[l][c];
}
	
void filtre(/*const*/ Pixels& ap_seuillage, const Image& image /*, Pixels& ppm_f*/)
{
	//cout << "done" ;															// le filtre ne s'applique pas pour les pixels du bord car moins de 6pixels autour//
	//ppm_f = ap_seuillage;
	
	for (int i(1); i < image.nbL; ++i) {
		for (int j(1); j < image.nbC; ++j) {
			//cout << "ici" << endl; 
			if ( (i != 0) and ( i != (image.nbL-1)) and (j!= 0) and (j!= (image.nbC-1))){
				//ppm_f[i][j] = color6(ap_seuillage, image, i, j);
				ap_seuillage[i][j] = color6(ap_seuillage, image, i, j);
			}
		}
	}
}



void filtrage(Pixels& /*const& */ ap_seuillage, Image const& image, Pixels& filteredPxl)
{
	//Pixels ppm_f(image.nbL, vector<int>(image.nbC));
	
	if (image.nbF !=0) {	 											//création d'une image de destination //
		for (int i(0); i < image.nbF; ++ i) {
			filtre(ap_seuillage, image /*, ppm_f*/);
		}
	
		if ( image.nbF > 0) {
			for (int i(0); i< image.nbL ; ++i) {
				for (int j(0); j < image.nbC ; ++j) {
					if (( i==0 ) or (i== image.nbL-1)){
						//ppm_f[i][j] = 0;
						ap_seuillage[i][j] = 0;
					} else if ((j==0) or (j== image.nbC-1)) {
						//ppm_f[i][j] = 0;
						ap_seuillage[i][j] =0;
					}
				}
			}
		}
	}
	
	color_nb_to_color(/*ppm_f*/ ap_seuillage, image, filteredPxl);
	
	//cout << "donefiltrage" << endl;
 }
 

void color_nb_to_color(const Pixels& /*ppm_f*/ ap_seuillage, const Image& image, Pixels& ppm_color)
 {
	 //Pixels ppm_color(image.nbL, vector<int>((image.nbC)*3));
	 
	 int c(0), nb(0);
	 for (int i(0); i < image.nbL; ++i)
	 {
		 
		 /*for (int m(0); m <= image.nbR ;++m){
			 for (int j(0); j < 3; ++j) {
				 cout << image.pixel_tab[m][j] << " ";
				}
		 }*/
		 
		 c = 0;
		 for (int j(0); j < image.nbC; ++j)
		 {
			 //nb = ppm_f[i][j];
			 nb = ap_seuillage[i][j] ;
			 //cout << nb << endl;
			 ppm_color[i][c] = image.pixel_tab[nb][0];
			 ppm_color[i][c+1] = image.pixel_tab[nb][1];
			 ppm_color[i][c+2] = image.pixel_tab[nb][2];
			 c += 3;
		}
	}
	//cout << "done" << endl;
	
	/*for (int i(0); i < image.nbL; ++i) {
		for (int j(0); j < (image.nbC*3); ++j) {
			cout << ppm_color[i][j];
		}
	}*/
 }
