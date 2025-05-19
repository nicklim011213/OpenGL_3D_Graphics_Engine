#include "CommonDataStructs.h"


Point::Point(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
	C1 = 0;
	C2 = 0;
	C3 = 0;
	T1 = 0;
	T2 = 0;
};

Point::Point()
{
	X = 0;
	Y = 0;
	Z = 0;
	C1 = 0;
	C2 = 0;
	C3 = 0;
	T1 = 0;
	T2 = 0;
}