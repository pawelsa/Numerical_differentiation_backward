// NumericalDifferentiation.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Derivative.h"



int main()
{

	//										  x, n,  h, degree
	Derivative *calculations = new Derivative(3, 4, 0.01, 2);
	double value = calculations->calculate();

	std::cout << value;
	
    return 0;
}



