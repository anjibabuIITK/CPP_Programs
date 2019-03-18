/*
-------------------------------------------------------------------------------
This class is a part of  the C++ program for Molecular dynamics (NVE) on harmonic potential = 0.5*k*x^2


 Authour:  Anji Babu Kapakayala
	       C/O Prof. Nisanth N. Nair
	       Dept. of Chemistry
	       IIT Kanpur, India.

-------------------------------------------------------------------------------
*/
#include <iostream>
#include <cmath>		   // Class for basic Mathematics
#include <fstream>         // Class for basic file operations
#include "VERLET.h"

using namespace std;


// Default Constructor
VERLET::VERLET() { 
ifstream inputfile;
inputfile.open("INPUT.dat", ios::in);

	if(inputfile.is_open()){
	 	inputfile >> x;
		inputfile >> v;
		inputfile >> m;
		inputfile >> k;
		inputfile >> dt;
		inputfile >> n;

		cout << "X=" << x<<endl;
		cout << "V=" << v<<endl;
		cout << "m=" << m<<endl;
		cout << "k=" << k<<endl;
		cout << "dt=" <<dt <<endl;
		cout << "n=" << n << endl;

		inputfile.close();

	} else{	
	cout << "Error in opening input file (INPUT.dat).\n";
	}
}

/*==========================================
  Functions Used in Class
  ===========================================*/

// Function to get force
double  VERLET::getForce(double x,double k) 
{
double f;
f=-k*x;
return f;
}
//---------------------
// Get Potential Energy
double VERLET::getPE(double x, double k)
{
	double result;
	result=0.5*k*(x*x);
return result;
}
//-------------------------
// Function to get update positions
double VERLET::getPosition(double x, double dt, double v, double a)
{
double result;
result=x+v*dt+0.5*(dt*dt)*a;
return result;
}
//---------------------------
// Function to update velocities
double VERLET::getVelocity(double a, double dt, double v, double a_t)
{
double result;
result=v+0.5*dt*(a+a_t);
return result;
}
//-----------------------------
// Function to write Data into file
void VERLET::WriteData(int i, double x, double v, double e, double eke, double te) {
ofstream outfile1;
ofstream outfile2;


outfile1.open("POSITIONS.dat", ios::app);
outfile2.open("ENERGIES.dat", ios::app);

		if (outfile1.is_open() && outfile2.is_open())
		{
			outfile1 << i << "  " << x << "  "<< v <<"  "<<endl;
     		outfile2 << i << "  " << e << "  "<< eke <<"  "<< te << endl;
		} else {
			cout << " Error in opening  the file.";
		}
outfile1.close();
outfile2.close();
}
// End of the Class VERLET


/*===========================================================
     Written By Anji Babu Kapakayala
===========================================================*/
