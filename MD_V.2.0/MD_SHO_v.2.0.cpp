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
#include "VERLET.h"

using namespace std;

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
