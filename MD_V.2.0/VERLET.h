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

// Function members
VERLET();
double getForce(double x,double k); 
double getPE(double x, double k);
double getPosition(double x, double dt, double v, double a);
double getVelocity(double a, double dt, double v, double a_t);
void WriteData(int i, double x, double v, double e, double eke, double te);

};

/*===========================================================
     Written By Anji Babu Kapakayala
===========================================================*/
