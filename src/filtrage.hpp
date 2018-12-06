#ifndef FILTRAGE_H
#define FILTRAGE_H

//#include <iostream>

#include "types.hpp"
#include "seuillage.hpp"

void filtrage(/*const*/ Pixels& ap_seuillage, const Image& image, Pixels& filteredPxl);
int color6(/*const*/ Pixels& ap_seuillage, const Image& image, int l, int c);
//Pixels filtre(/*const*/ Pixels& ap_seuillage, const Image& image);
void filtre(/*const*/ Pixels& ap_seuillage, const Image& image /*, Pixels& ppm_f*/);
//void chgmt_color(const Pixels& ppm_f, const Image& image, Pixels& ppm_color);
void color_nb_to_color(const Pixels& /*ppm_f*/ ap_seuillage, const Image& image, Pixels& ppm_color);

#endif // FILTRAGE_H
