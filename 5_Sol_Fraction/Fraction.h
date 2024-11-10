#pragma once
#include <string>
#include <iostream>

using namespace std;
class Fraction
{
	friend Fraction operator+(const Fraction& f1, const Fraction& f2);

private:
	int _numerator;
	int _denominator;

public:
	Fraction(int numerator = 0, int denominator = 1);
	Fraction(double value);

	void reduce();

	string toString() const;

};

Fraction operator+(const Fraction& f1, const Fraction& f2);
Fraction operator+(const Fraction& f, double d);
Fraction operator+(double d, const Fraction& f);

ostream& operator<<(ostream& os, const Fraction& f);