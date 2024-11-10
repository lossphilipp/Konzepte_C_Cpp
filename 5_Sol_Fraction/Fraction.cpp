#include "Fraction.h"

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

Fraction::Fraction(int numerator, int denominator)
	: _numerator(numerator), _denominator(denominator)
{
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

string Fraction::toString() const
{
	return "[" + to_string(_numerator) + "/" + to_string(_denominator) + "]";
}

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	int newNumerator = f2._numerator * f1._denominator + f1._numerator * f2._denominator;
	int newDenominator = f2._denominator * f1._denominator;

	Fraction f = Fraction(newNumerator, newDenominator);

	f.reduce();
	return f;
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