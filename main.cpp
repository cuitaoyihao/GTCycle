/*---------------------------------------------------------------------------*\
   ____ _____               _           |
  / ___|_   _|__ _   _  ___| | ___      | Copyright (C) 2013-2015  AMP Srl
 | |  _  | |/ __| | | |/ __| |/ _ \     |
 | |_| | | | (__| |_| | (__| |  __/     |
  \____| |_|\___|\__, |\___|_|\___|     |
                 |___/                  |
  ---------------------------------------------------------------------------
    This file is part of GTcycle.

    GTcycle is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
\*  along with GTcycle.  If not, see <http://www.gnu.org/licenses/>.          */

#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/stat.h>
#include "include/thermo.h"
#include "include/fluid.h"
#include "include/mixture.h"
#include "include/DryAir.h"
#include "include/humidAir.h"


using namespace std;

int main(int argc, char* argv[])
{
 /*   if (argc < 3) { // Check the value of argc. If not enough parameters have been passed, inform user and exit.
        std::cout << "Usage is " << argv[0] << " <infile>  <outfile>\n"; // Inform the user of how to use the program
        exit(0);
    }
    else { // if we got enough parameters...
        struct stat buffer;
        for (int i=1; i < 3; i++)
        {
            if(stat (argv[i], &buffer) != 0) {
            std::cout << "Error: file " << argv[i] << " does not exist. \n";
            exit(1);
            }
        }

    std::string inputFileName=argv[0];
    std::string outputFileName=argv[1];

    }
*/

    cout << "Hello world!" << endl;

//std::string inputFileNamez("therm.dat");
std::string inputFileNamez("BURCAT.THR");
cout << inputFileNamez << endl;
thermo fileThermo(inputFileNamez);
vector<ThermoData> Species;

Species.push_back(fileThermo.getSpecie("N2"));
Species.push_back(fileThermo.getSpecie("O2"));
Species.push_back(fileThermo.getSpecie("AR"));
Species.push_back(fileThermo.getSpecie("CO2"));
Species.push_back(fileThermo.getSpecie("SO2"));
Species.push_back(fileThermo.getSpecie("H2O"));

vector<fluid> fluids(6);
//cout << fluids.size() << endl;



for (int i=0; i<6; i++) {
fluids[i] = Species[i];
//cout << fluids[i].GetName() << "  " << Species[i].GetName() << endl;
}

vector<real> Frazioni;

Frazioni.push_back(75.55334);
Frazioni.push_back(23.13308);
Frazioni.push_back(1.26344);
Frazioni.push_back(0.05014);
Frazioni.push_back(0.0);
Frazioni.push_back(0.0);

//DryAir aria;

//cout << aria.GetR() << endl;

real presssure=101300.;
real tempe=293.15;
real rhh=0.8;

//humidAir aria_umida(presssure, tempe, rhh);
/*
vector<fluid> vettore1 = aria_umida.GetBaseFluidsVector();
vector<real> vettore2 = aria_umida.GetMassFractionVector();
vector<real> vettore3 = aria.GetMassFractionVector();

/*cout << vettore2[0] << endl;
cout << vettore2[1] << endl;
cout << vettore2[2] << endl;
cout << vettore2[3] << endl;
cout << vettore2[4] << endl;
cout << vettore2[5] << endl;
*/
mixture miscela(fluids,Frazioni);

//for (int i=0;i<8000;i++){
//    miscela.SetT(1+i*1);
//    miscela.SetP(101300);
//    miscela.PT2Properties();
//    cout << miscela.GetT() << "  " << miscela.GetCp() << endl;
//}
for (int i=0;i<6;i++){
cout << Species[i].GetHiT() << endl;
}
miscela.SetT(500);
miscela.SetP(101300);
miscela.PT2Properties();
cout << miscela.GetH() << endl;
vector<fluid> vettore1 = miscela.GetBaseFluidsVector();
cout << miscela.GetHiT() << endl;

fluids[0].SetT(500);
fluids[0].PT2Properties();
cout << "H di Nitrogen = " << fluids[0].GetName() << endl;

    return 0;
}
