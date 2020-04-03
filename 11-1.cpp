#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <atlstr.h>
#include "NameSp2.h"
#include <iomanip>
#include "vld.h"

using namespace std;

class Point
{
private:
	int X, Y;

public:

	Point(int x = 0, int y = 0) : X(x), Y(y) {}

	void ShowPosition() const
	{
		cout << '[' << X << ',' << Y << ']' << endl;
	}

	friend ostream& operator<<(ostream&, const Point&);

	friend ostream& operator<<(ostream&, const Point*);

	friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& O, const Point& P)
{
	O << '[' << P.X << ',' << P.Y << ']' << endl;
	return O;
}

ostream& operator<<(ostream& O, const Point* P)
{
	O << '[' << P->X << ',' << P->Y << ']' << endl;
	return O;
}

istream& operator>>(istream& O, Point& P)
{
	O >> P.X >> P.Y;
	return O;
}

typedef Point* Point_Ptr;

class BoundCheckPointPtrArray
{
private:
	Point_Ptr* Array;
	int ArrayLen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& Arr) {}
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& Arr) {}

public:
	BoundCheckPointPtrArray(int Len) : ArrayLen(Len)
	{
		Array = new Point_Ptr[Len];
	}

	Point_Ptr& operator[] (int Index)
	{
		if (Index < 0 || Index > ArrayLen)
		{
			cout << "Array Index Out Of Bound Exception" << endl;
			exit(1);
		}

		return Array[Index];
	}

	Point_Ptr& operator[] (int Index) const
	{
		if (Index < 0 || Index > ArrayLen)
		{
			cout << "Array Index Out Of Bound Exception" << endl;
			exit(1);
		}

		return Array[Index];
	}

	int GetArrayLen() { return ArrayLen; }

	~BoundCheckPointPtrArray()
	{
		delete[] Array;
	}
};

int main()
{
	BoundCheckPointPtrArray Array(3);
	Array[0] = new Point(1, 1);
	Array[1] = new Point(2, 2);
	Array[2] = new Point(3, 3);

	for (int i = 0; i < Array.GetArrayLen(); i++)
	{
		cout << Array[i] << endl;
		delete Array[i];
	}
}