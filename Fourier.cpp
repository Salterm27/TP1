#include <istream>
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
#include <cmath>
#define EMPTY "No Data"
using namespace std;

Array <Complex> DFT (Array <Complex> const &vector){
    double arg;
    size_t len=vector.GetSize();
    Array <Complex> DFTarray(len);
    Complex aux;

    for (size_t k=0; k<len; k++){
        for(size_t n=0; n<len; n++){
            arg=(k*n*2*M_PI)/len;
            aux.SetRe(cos(arg));
            aux.SetIm(-sin(arg));
            DFTarray[k]+=(vector[n]*aux);
        }
    }

    return DFTarray;
}

Array <Complex> IDFT (Array <Complex> const &vector){
    double arg;
    size_t len=vector.GetSize();
    Array <Complex> IDFTarray(len);
    Complex aux;
    Complex len2(len);
    for(size_t n=0 ;n<len; n++){
        for(size_t k=0; k<len; k++){
            arg=(k*n*2*M_PI)/len;
            aux.SetRe(cos(arg));
            aux.SetIm(sin(arg));
            IDFTarray[n]+=(vector[k]*aux)/len;
        }
    }
    return IDFTarray;
}

void DFT(ostream& os, istream& is)
{
    Array <Complex> X;
    Array <Complex> Y;

    while(!is.eof()){
        is>>X;
        if(X.GetSize()== 0){
            os<<EMPTY<<endl;
        }
        else{
            Y=DFT(X);
            os<<Y<<endl;    
        }
    }
}

void IDFT(ostream& os, istream& is)
{
    Array <Complex> X;
    Array <Complex> Y;

    while(!is.eof()){
        is>>X;
        if(X.GetSize()==0){
            os<<EMPTY<<endl;
        }else{
            Y=IDFT(X);
            os<<Y<<endl;   
        }
    }
    X.Resize(0);
    Y.Resize(0);
}

