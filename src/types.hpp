#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > Pixels;
typedef std::vector<std::vector<double> > Intensite;

class Image						// structure entrée par l'utilisateur //
{
	public:
	
	Image(){nbR=nbF=nbC=nbL=MAX=0;}
	~Image(){};
	
	int nbR;							//nombre de couleurs après filtrage de l'image//
	Pixels pixel_tab;					//tableau des intensités des pixels de filtrage //
	std::vector<double> seuils;				
	int nbF;							//nombre de filtrage//
	std::string format;						
	int nbC;							//nombre de colonnes de l'image de départ//
	int nbL;							//nombre de lignes de l'image de départ//
	int MAX;							//nombre maximum de l'intensité d'un pixel//
	Pixels pixels_ppm;					//pixels de l'image de départ//
};

#endif // TYPES_H
