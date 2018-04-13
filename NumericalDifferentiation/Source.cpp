#include "stdafx.h"
#include<iostream>
 
using namespace std;
 

	const int n = 5;
	double h = 0.1;
	double k = 1.0;
	double first_deriv_coeff[n + 1];
	double second_deriv_coeff[n + 1];
	double d[n + 1][n + 1];

	double firstDerivativeValue = 0;
	double analyticalValueOfFirstDerivatiave = cos(2);

	double secondDerivativeValue = 0;
	double analyticalValueOfSecondDerivative = -sin(2);
	
	double f(int x) {
		return sin(x);
	}

	void calculateCoefficientsOfFirstDerivative() {
		for (int i = 0; i < n; i++)
		{
			first_deriv_coeff[i] = 1 / k;
			second_deriv_coeff[i] = 0;
			k++;
		}
	}

	double calculateCoefficientsOfSecondDerivative(int i, int j) {
		return first_deriv_coeff[i - 1] * first_deriv_coeff[j - 1]+ second_deriv_coeff[i + j - 1];
	}
	void calcucalculateCoefficientsOfSecondDerivative() {

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if ((i + j) < (n + 1))
					second_deriv_coeff[i + j - 1] = calculateCoefficientsOfSecondDerivative(i, j);
				else
					break;
			}
		}
	}


	void calculateTable() {
		for (int i = 0; i <= n; i++)
		{
			d[i][0] = f(2 - i * h);
		}

		for (int j = 1; j <= n; j++)
		{
			for (int i = 0; i <= n; i++)
			{
				d[i][j] = d[i][j - 1] - d[i + 1][j - 1];
			}
		}
	}


	void displayTableValues() {

		for (int i = 0; i <= n; i++)
		{
			cout << d[0][i] << " ";
		}
		cout << endl;
	}

	void calculateFirstDerivative() {

		for (int i = 0; i < n; i++)
		{
			firstDerivativeValue += d[0][i + 1] * first_deriv_coeff[i];
		}
		firstDerivativeValue /= (h);
	}

	void displayInfoAboutFirstDrivative() {

		cout << "First derivative" << endl;
		cout << "Calculated value: " << firstDerivativeValue << endl;
		cout << "cos(2) : " << analyticalValueOfFirstDerivatiave << endl;
		cout << "Absolute Error : " << fabs(analyticalValueOfFirstDerivatiave - firstDerivativeValue) << endl;
		cout << "Relative Error : " << fabs(analyticalValueOfFirstDerivatiave - firstDerivativeValue) / fabs(analyticalValueOfFirstDerivatiave) << endl << endl;
	}

	void calculateSecondDerivative() {

		for (int i = 0; i < n; i++) {
			secondDerivativeValue += d[0][i + 1] * second_deriv_coeff[i];
			if (i == n - 1)
				secondDerivativeValue /= (h*h);
		}
	}

	void displayInfoAboutSecondDrivative() {

		cout << "Second derivative" << endl;
		cout << "Calculated value: " << secondDerivativeValue << endl;
		cout << "-sin(2): " << analyticalValueOfSecondDerivative << endl;
		cout << "absolute Error: " << fabs(analyticalValueOfSecondDerivative - secondDerivativeValue) << endl;
		cout << "relative Error: " << fabs(analyticalValueOfSecondDerivative - secondDerivativeValue) / fabs(analyticalValueOfSecondDerivative) << endl;
	}

	int main()
	{

		calculateCoefficientsOfFirstDerivative();
		calcucalculateCoefficientsOfSecondDerivative();
		calculateTable();
		displayTableValues();
		calculateFirstDerivative();
		displayInfoAboutFirstDrivative();
		calculateSecondDerivative();
		displayInfoAboutSecondDrivative();

		system("PAUSE");

		return 0;
	}