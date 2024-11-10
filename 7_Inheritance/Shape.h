#pragma once

#include <iostream>
using namespace std;

class Shape
{
public:
	// void draw() = 0; // = 0 ist equivalent zu C# "abstract"
	virtual void draw(); // Keyword virtual macht dynamische Bindung
	virtual ~Shape() = default; // statische Bindung im Dekonstruktor ist immer gefaehrlich
};