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


class Fourier
{
    public:
        virtual void Compute(ostream& os, istream& is)=0;
        virtual Array<Complex> Compute(const Array<Complex> &)=0;
        virtual ~Fourier(){};
};

class FFT : public Fourier
{
    Complex Compute(size_t,size_t,size_t,int,const Array<Complex>&);

    public:
        virtual Array<Complex> Compute(const Array<Complex>&);
        virtual void Compute(ostream& os, istream& is);
        ~FFT(){};
};

class IFFT : public Fourier
{
    Complex Compute(size_t,size_t,size_t,int,const Array <Complex>&);

    public:
        virtual Array<Complex> Compute(const Array <Complex>& Vector);
        virtual void Compute(ostream& os, istream& is);
        ~IFFT(){};
};

class DFT : public Fourier
{
    public:
    	virtual Array<Complex> Compute(const Array <Complex>& Vector);
        virtual void Compute(ostream& os, istream &is);
        ~DFT(){};
};

class IDFT : public Fourier
{
    public:
        virtual Array<Complex> Compute(const Array <Complex>& Vector);
        virtual void Compute(ostream& os, istream &is);
        ~IDFT(){};
};



#endif
