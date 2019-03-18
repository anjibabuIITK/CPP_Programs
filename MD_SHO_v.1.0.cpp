/*
-------------------------------------------------------------------------------
A C++ program for Modecular dynamics (NVE) on harmonic potential = 0.5*k*x^2
using VERLET as a class.

 Authour:  Anji Babu Kapakayala
	       C/O Prof. Nisanth N. Nair
	       Dept. of Chemistry
	       IIT Kanpur, India.

 USAGE:    Compile:  g++ MD_SHO_v_1.0.cpp
           Execute:  ./a.out
-------------------------------------------------------------------------------
*/
#include <iostream>
#include <cmath>		   // Class for basic Mathematics
#include <fstream>         // Class for basic file operations

using namespace std;


class VERLET {      //Defining a Class
public:
double x,v,m,k,dt,a_t,te,a;
double eke, e, f, v2, a2;
int i,n;


// Default Constructor
VERLET() { 
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
	cout << "Error in opening input file (INPUT.dat).";
	}
}

/*==========================================
  Functions Used in Class
  ===========================================*/

// Function to get force
double getForce(double x,double k) 
{
double f;
f=-k*x;
return f;
}
//---------------------
// Get Potential Energy
double getPE(double x, double k)
{
	double result;
	result=0.5*k*(x*x);
return result;
}
//-------------------------
// Function to get update positions
double getPosition(double x, double dt, double v, double a)
{
double result;
result=x+v*dt+0.5*(dt*dt)*a;
return result;
}
//---------------------------
// Function to update velocities
double getVelocity(double a, double dt, double v, double a_t)
{
double result;
result=v+0.5*dt*(a+a_t);
return result;
}
//-----------------------------
// Function to write Data into file
void WriteData(int i, double x, double v, double e, double eke, double te) {
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
};
/*--------------------------------------------------------------------
						Main program starts
---------------------------------------------------------------------*/
int main() {
	
double x,v,m,k,dt,a_t,te,a;
double eke, e, f, v2, a2;
int i, n;

VERLET md;

// Initilizations
x=md.x; v=md.v; m=md.m; k=md.k;
dt=md.dt;n=md.n;

// Calculating Initial Force
f=md.getForce(x,k);
e=md.getPE(x,k);
a=f/m;

te=0.0;eke=0.0;
	for(int i=1; i<= n; i++){
		md.WriteData(i, x, v, e, eke, te);
		x=md.getPosition(x,dt,v,a);
		a_t=a;
		f=md.getForce(x,k);
		e=md.getPE(x,k);
		a=f/m;
		v=md.getVelocity(a,dt,v,a_t);
		eke=0.5*m*(v*v);
		te=eke+e;
 		}
return 0;
}

/*===========================================================
     Written By Anji Babu Kapakayala
===========================================================*/
