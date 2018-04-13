#pragma once

class Coefficients {

	int derivativeDegree;
	int searchedElement;
	int *countOfLoopsState;
	double coefficient = 0.0;
	int n;

	void calculateCoefficient(int level) {

		if (getCountValue() == searchedElement) {
			coefficient = getDelta() + coefficient;
		}
		else if (level < derivativeDegree) {
			for (countOfLoopsState[level] = 1; countOfLoopsState[level] <= n; countOfLoopsState[level]++) {
				calculateCoefficient(level + 1);
			}
		}
	}

	double getDelta() {

		double delta = 0.0;

		for (int i = 0; i < derivativeDegree; i++) {
			if (countOfLoopsState[i] > n) {
				return 0.0;
			}
			if (countOfLoopsState[i] != 0) {
				if (delta == 0) {
					delta = (1.0 / countOfLoopsState[i]);
				}
				else {
					delta *= (1.0 / countOfLoopsState[i]);
				}
			}
		}
		return delta;
	}

	int getCountValue() {

		int valueOfI = 0;
		for (int i = 0; i < derivativeDegree; i++) {
			valueOfI += countOfLoopsState[i];
		}

		return valueOfI;
	}

public:


	Coefficients(int mLevel, int mSearchedElement, int nn) :derivativeDegree(mLevel), searchedElement(mSearchedElement) {
		countOfLoopsState = new int[mLevel+1];
		n = nn;
	}

	void calculateCoefficient() {
		calculateCoefficient(0);
	}

	double getResult() {
		return coefficient;
	}
};
