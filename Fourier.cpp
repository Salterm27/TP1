#include <ctime>
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
#include "Fourier.h"
#include <math.h>


using namespace std;

Array <Complex> DFT::Compute (const Array <Complex>& Vector){
    double arg;
    size_t len=Vector.GetSize();
    Array <Complex> DFTarray(len);
    Complex aux;

    for (size_t k=0; k<len; k++){
        for(size_t n=0; n<len; n++){
            arg=(k*n*2*M_PI)/len;
            aux.SetRe(cos(arg));
            aux.SetIm(-sin(arg));
            DFTarray[k]+=(Vector[n]*aux);
        }
    }

    return DFTarray;
}

Array <Complex> IDFT::Compute (const Array <Complex>& Vector){
    double arg;
    size_t len=Vector.GetSize();
    Array <Complex> IDFTarray(len);
    Complex aux;
    Complex len2(len);
    for(size_t n=0 ;n<len; n++){
        for(size_t k=0; k<len; k++){
            arg=(k*n*2*M_PI)/len;
            aux.SetRe(cos(arg));
            aux.SetIm(sin(arg));
            IDFTarray[n]+=(Vector[k]*aux)/len;
        }
    }
    return IDFTarray;
}

Array<Complex> FFT::Compute(const Array <Complex>& Vector){
    size_t size=Vector.GetSize();
    Array <Complex>* FFTVector;
    FFTVector=new Array<Complex>(size);

    for(size_t i=0; i<size; i++)
    {
        (*FFTVector)[i]=Compute(0,1,size,i,Vector);
    }

    return *FFTVector;
}


Complex FFT::Compute(size_t init_pos,size_t step, size_t len, int k,const Array <Complex>& Vector)
{
    if(len==1)
    {
        return Vector[init_pos];
    }

    double arg=(2*M_PI*k)/len;
    Complex aux(cos(arg),-sin(arg));

    return Compute(init_pos,step*2,len/2,k,Vector) + (Compute(init_pos+step,step*2,len/2,k,Vector) * aux);
}

Array<Complex> IFFT::Compute(const Array <Complex>& Vector){
    size_t size=Vector.GetSize();
    Array <Complex>* FFTVector;
    FFTVector=new Array<Complex>(size);

    for(size_t i=0; i<size; i++)
    {
        (*FFTVector)[i]=Compute(0,1,size,i,Vector);
    }
    *FFTVector=(*FFTVector)/size;

    return *FFTVector;
}


Complex IFFT::Compute(size_t init_pos,size_t step, size_t len, int k,const Array <Complex>& Vector){
    if(len==1)
    {
        return Vector[init_pos];
    }

    double arg=(2*M_PI*k)/len;
    Complex aux(cos(arg),sin(arg));

    return Compute(init_pos,step*2,len/2,k,Vector) + (Compute(init_pos+step,step*2,len/2,k,Vector) * aux);
}

void DFT::Compute(ostream& os, istream& is){
    Array <Complex> X;
    Array <Complex> Y;

    while(!is.eof()){
        is>>X;
        Y=Compute(X);
        os<<Y<<endl;
    }
}

void IDFT::Compute(ostream& os, istream& is){
    Array <Complex> X;
    Array <Complex> Y;

    while(!is.eof()){
        is>>X;
        Y=Compute(X);
        os<<Y<<endl;
    }
}

void FFT::Compute(ostream& os, istream& is)
{
    Array <Complex> X;
    Array <Complex> Y;

    while(!is.eof()){
        is>>X;
        Y=Compute(X);
        os<<Y<<endl;
    }
}

void IFFT::Compute(ostream& os, istream& is)
{
    Array <Complex> X;
    Array <Complex> Y;

    while(!is.eof()){
        is>>X;
        Y=Compute(X);
        os<<Y<<endl;
    }
}

