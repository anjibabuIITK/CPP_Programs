/*
-------------------------------------------------------------------------------
A C++ program for Modecular dynamics (NVE) on harmonic potential = 0.5*k*x^2

 Authour:  Anji Babu Kapakayala
	   C/O Prof. Nisanth N. Nair
	   Dept. of Chemistry
	   IIT Kanpur, India.

 USAGE:    Compile:  g++ MD.cpp
           Execute:  ./a.out
-------------------------------------------------------------------------------
*/
#include <iostream>
#include <cmath>		   // Class for basic Mathematics
#include <fstream>         // Class for basic file operations

using namespace std;

// Function Definitions
double getForce(double x, double k);
double getPE(double x, double k);
double getPosition(double x, double dt, double v, double a);
double getVelocity(double a, double dt, double v, double a_t);

// Main program starts
int main() {
	
double x,v,m,k,dt,a_t,te,a;
double eke, e, f, v2, a2;
int i, n;
/*
// Initilizations
x=1.0; v=1.0; m=1.0; k=1.0;
dt=0.01;n=10000;
*/
//Opening file to read data
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
	cout << "Error in opening file.";
}

//Opening a file to wrte data
ofstream outfile1;
ofstream outfile2;

outfile1.open("POSITIONS.dat", ios::out);
outfile2.open("ENERGIES.dat", ios::out);

//getForce(double x)
f=getForce(x,k);
e=getPE(x,k);
a=f/m;

te=0.0;eke=0.0;
	for(int i=1; i<= n; i++){
		x=getPosition(x,dt,v,a);
		a_t=a;
		f=getForce(x,k);
		e=getPE(x,k);
		a=f/m;
		v=getVelocity(a,dt,v,a_t);
		eke=0.5*m*(v*v);
		te=eke+e;
		// Print the Value
		//cout << i <<" "<< x << " " << v <<endl;
		//cout << i <<" "<< e << " "<< eke << " "<<te<<endl;

		//Writing data to files
		if (outfile1.is_open() && outfile2.is_open())
		{
			outfile1 << i << "  " << x << "  "<< v <<"  "<<endl;
     		outfile2 << i << "  " << e << "  "<< eke <<"  "<< te << endl;
		} else {
			cout << " Error in opening  the file.";
		}
		
	}	
outfile1.close();
outfile2.close();
return 0;
}

/*==========================================
  Functions Used
  ===========================================*/
double getForce(double x,double k) 
{
double f;
f=-k*x;
return f;
}
// Get Potential Energy
double getPE(double x, double k)
{
	double pe;
	pe=0.5*k*(x*x);
return pe;
}
// Function to get update positions
double getPosition(double x, double dt, double v, double a)
{
double x1;
x1=x+v*dt+0.5*(dt*dt)*a;
return x1;
}
// Function to update velocities
double getVelocity(double a, double dt, double v, double a_t)
{
double v1;
v1=v+0.5*dt*(a+a_t);
return v1;
}
/*===========================================================
     Written By Anji Babu Kapakayala
===========================================================*/
