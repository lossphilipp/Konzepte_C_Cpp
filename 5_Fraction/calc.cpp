#include "calc.h"
#include <iostream>
#include <string>
using namespace std;

Fraction::Fraction(int numerator, int denominator)
	: _numerator(numerator), _denominator(denominator)
{
	cout << "Fraction: regular ctor" << endl;

	if (denominator == 0)
	{
		throw;
	}
}

Fraction::Fraction(const Fraction& other)
	: _numerator(other._numerator), _denominator(other._denominator)
{
	cout << "Fraction: copy ctor" << endl;
}

Fraction::Fraction(double value)
{
	int nrOfDigits = getNumberOfFractionDigits(value);

	_denominator = 1;
	for (int i = 0; i < nrOfDigits; i++)
	{
		_denominator *= 10;
	}
	_numerator = (int)(value * _denominator);
}

Fraction& Fraction::operator=(const Fraction& other)
{
	cout << "Fraction: Zuweisungsoperator" << endl;

	if (this == &other)
	{
		return *this;
	}

	_numerator = other._numerator;
	_denominator = other._denominator;

	return *this;
}

Fraction::~Fraction()
{
	cout << "Fraction: dector" << endl;
}

string Fraction::toString() const
{
	return "[" + to_string(_numerator) + "/" + to_string(_denominator) + "]";
}

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	cout << "Fraction: + Operator" << endl;

	int new_numerator;
	int new_denominator;

	if (f1._denominator == f2._denominator)
	{
		new_numerator = f1._numerator + f2._numerator;
		new_denominator = f1._denominator;
	}
	else
	{
		new_numerator = (f1._numerator * f2._denominator) + (f2._numerator * f1._denominator);
		new_denominator = f1._denominator * f2._denominator;
	}

	// ToDo: Check if fraction can be simplyfied

	Fraction result(new_numerator, new_denominator);
	return result;
}

Fraction operator+(const Fraction& f, double d)
{
	Fraction f2 = Fraction(d);
	return f + f2;
}

Fraction operator+(double d, const Fraction& f)
{
	return f + d;
}

ostream& operator<<(ostream& os, const Fraction& f)
{
	os << f.toString();
	return os;
}

static int getNumberOfFractionDigits(double value)
{
	int nrOfDigits = 0;
	while (value != (int)value)
	{
		value *= 10;
		nrOfDigits++;
	}
	return nrOfDigits;
}

void Fraction::reduce() {
	int gcd = 1;
	int smaller = _numerator < _denominator ? _numerator : _denominator;
	for (int i = 2; i <= smaller; i++)
	{
		if (_numerator % i == 0 && _denominator % i == 0)
		{
			gcd = i;
		}
	}
	_numerator /= gcd;
	_denominator /= gcd;
}

// ++fraction
Fraction& Fraction::operator++()
{
	_numerator += _denominator;
	return *this;
}

// fraction++
Fraction Fraction::operator++(int)
{
	Fraction f = *this;
	_numerator += _denominator;
	return f;
}