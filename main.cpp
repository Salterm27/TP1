#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "Complex.h"
#include "Array.h"
#include "Fourier.h"
#include "Cmdline.h"

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_method(string const &);
static void opt_help(string const &);


static option_t options[] = {
    {1, "i", "input", "-", opt_input, OPT_MANDATORY},
    {1, "o", "output", "-", opt_output, OPT_DEFAULT},
    {1, "m", "method", "-", opt_method, OPT_DEFAULT},
    {0 ,"h", "help" , NULL, opt_help, OPT_DEFAULT},
    {0,0,0,0,0,0},
};

static bool is_dft;
static istream *iss = 0;
static ostream *oss = 0;
static fstream ifs;
static fstream ofs;


static void
opt_input(string const &arg)
{
    if (arg == "-") {
        iss = &cin;
    } else {
        ifs.open(arg.c_str(), ios::in);
        iss = &ifs;
    }

    if (!iss->good()) {
        cerr << "Error. Cannot open " << arg << "." << endl;
        exit(1);
    }
}

static void
opt_method(string const &arg)
{
    if (arg == "-" || arg=="DFT") {
        is_dft=true;
    }
    else if (arg=="IDFT")
    {
        is_dft=false;
    }
    else
    {
        cout << "Error. Invalid method invoked: " << arg << endl;
        exit(1);
    }
}


static void
opt_output(string const &arg)
{
    if (arg == "-") {
        oss = &cout;
    } else {
        ofs.open(arg.c_str(), ios::out);
        oss = &ofs;
    }

    if (!oss->good()) {
        cerr << "Error. Cannot open " << arg << "." << endl;
        exit(1);
    }
}

static void
opt_help(string const &arg)
{
    cout << "Program must be invoked: ./TP0 -i <input file> -o <output file> -m <method>" << endl;
    exit(0);
}

int main(int argc, char* const argv[])
{
    cmdline cmdl(options);
    cmdl.parse(argc,argv);


	if(is_dft==true)
		DFT(*oss,*iss);
	else
		IDFT(*oss,*iss);

	ifs.close();
	ofs.close();

	return 0;
}
