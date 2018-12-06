#ifndef SEUILLAGE_H
#define SEUILLAGE_H

//#include <iostream>

#include "types.hpp"

//Pixels seuillage(const Image& image);	
//Pixels seuillage(const Image& image, Pixels& ap_seuillage)
void seuillage(const Image& image, Pixels& ap_seuillage);							//fonction séparée en deux sous fonctions: in (intensité) des pixels et code-color pour leur code couleur//
//Intensite in(const Image& image);
Intensite color_int_norm(const Image& image, Intensite& in);
//void code_color(Intensite& in, const Image& image, Pixels& ap_seuillage);
//Pixels code_color(const Intensite& in, const Image& image);

#endif // SEUILLAGE_H
