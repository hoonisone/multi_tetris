#pragma once
#include <vector>
#include <string>
#include <windows.h>
#include "CoordinateSystem.h"

using namespace std;
using Shape = vector<string>;
//enum Color { BLACK, BLUE ,GREEN ,AQUA ,RED ,PURPLE ,YELLOW ,WHITE ,GRAY,
//LIGHT_BLUE ,LIGHT_GREEN ,LIGHT_AQUA ,LIGHT_RED ,LIGHT_PURPLE ,LIGHT_YELLOW ,BRIGHT_WHITE
//};
typedef int Color;

class Pencil;
static Pencil* usingPencil;

class Pencil {
private:
	Color textColor, backgroundColor;
	Shape textShape;
	int settingFlag;
	void setting();
public: 
	Pencil(Color textColor, Color backgroundColor, Shape textShape);
	void press();
};
