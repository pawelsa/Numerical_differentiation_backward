#pragma once
#include <math.h>
#include <iostream>
#include "Coefficients.h"

class Derivative {

	int level;
	double h;
	int n;
	int x;
	int derivativeDegree;
	double valueWithinBracelets = 0;

	double f(double x) {
		return log(x);
	}

	double calculate(int actualLevel, int height = 0) {

		if (isCalculatingBasicValue(actualLevel)) {
			return f(x - height * h);
		}
		else {
			double result = calculateBranches(actualLevel, height);

			if (lowestPointInTable(actualLevel, height)) {
				updateValueWithinBracelets(actualLevel, result);
			}
			return result;
		}
	}

	bool isCalculatingBasicValue(int actualLevel) {
		return actualLevel < 1;
	}

	double calculateBranches(int actualLevel, int height) {
		double upper = calculate(actualLevel - 1, height + 1);
		double lower = calculate(actualLevel - 1, height);
		return lower - upper;
	}

	bool lowestPointInTable(int actualLevel, int height) {
		return height == 0 && actualLevel != 0;
	}

	void updateValueWithinBracelets(int actualLevel, double result) {
		valueWithinBracelets += calculateDelta(actualLevel)*result;
	}

	double finalValue() {
		return valueWithinBracelets *= (1 / pow(h,derivativeDegree));
	}

	double calculateDelta(int noElement) {
		Coefficients *coefficients = new Coefficients(derivativeDegree, noElement, n);
		coefficients->calculateCoefficient();
		return coefficients->getResult();
	}

public:

	Derivative(int x, int n, float h, int degree) {
		this->x = x;
		this->h = h;
		this->level = n;
		this->n = n;
		this->derivativeDegree = degree;
	}

	double calculate() {
		calculate(level);
		return finalValue();
	}
};
