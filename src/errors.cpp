#include <iostream>

using namespace std;



void error_nbR(int nbR)
{
	cout << "Invalid number of colors: " << nbR << endl;
}

void error_color(int id)
{
	cout << "Invalid color value " << id << endl;
}

void error_threshold(double invalid_val)
{
	cout << "Invalid threshold value: " << invalid_val << endl;
}

void error_nb_filter(int nb_filter)
{
	cout << "Invalid number of filter: " << nb_filter << endl;
}
