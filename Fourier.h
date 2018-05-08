#ifndef FOURIER__H
#define FOURIER__H

using namespace std;

#include <istream>
#include <string.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include "Complex.h"
#include "Array.h"
#include <math.h>

Array <Complex> DFT (Array <Complex> const &vector);
Array <Complex> IDFT (Array <Complex> const &vector);
void DFT(ostream& os, istream& is);
void IDFT(ostream& os, istream& is);


#endif
