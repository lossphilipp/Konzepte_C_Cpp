#pragma once

class Fraction
{
	friend Fraction operator+(const Fraction& f1, const Fraction& f2);

private:
	int _numerator;
	int _denominator;

public:
	Fraction(int numerator = 0, int denominator = 1);
	Fraction(double value);
	Fraction(const Fraction& other);

	~Fraction();

	Fraction& operator=(const Fraction& other);
	Fraction& operator++();
	Fraction operator++(int);

	void reduce();
	string toString() const;
};

Fraction operator+(const Fraction& f1, const Fraction& f2);