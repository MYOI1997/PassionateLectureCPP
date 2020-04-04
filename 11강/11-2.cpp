// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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

class BoundCheckIntPtrArray
{
private:
	int* Array;
	int ArrayLen;

	BoundCheckIntPtrArray(const BoundCheckIntPtrArray& Arr) {}
	BoundCheckIntPtrArray& operator=(const BoundCheckIntPtrArray& Arr) {}

public:
	BoundCheckIntPtrArray(int Len) : ArrayLen(Len)
	{
		Array = new int[Len];
	}

	int& operator[] (int Index)
	{
		if (Index < 0 || Index >= ArrayLen)
		{
			cout << "Array Index Out Of Bound Exception" << endl;
			exit(1);
		}

		return Array[Index];
	}

	int operator[] (int Index) const
	{
		if (Index < 0 || Index >= ArrayLen)
		{
			cout << "Array Index Out Of Bound Exception" << endl;
			exit(1);
		}

		return Array[Index];
	}

	int GetArrayLen() { return ArrayLen; }

	~BoundCheckIntPtrArray()
	{
		delete[] Array;
	}
};

typedef BoundCheckIntPtrArray* IntPtr;

class BoundCheck2DIntArray
{
private:
	BoundCheckIntPtrArray** Array;
	int ArrayLen;

	BoundCheck2DIntArray(const BoundCheck2DIntArray& Arr) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& Arr) {}

public:

	BoundCheck2DIntArray(int Col, int Row) : ArrayLen(Col)
	{
		Array = new IntPtr[Col]; /* Array = new BoundCheckIntPtrArray*[Col]; */

		for (int i = 0; i < Col; i++)
		{
			Array[i] = new BoundCheckIntPtrArray(Row);
		}
	}

	BoundCheckIntPtrArray& operator[] (int Index)
	{
		if (Index < 0 || Index >= ArrayLen)
		{
			cout << "Array Index Out Of Bound Exception" << endl;
			exit(1);
		}

		return *(Array[Index]);
	}

	~BoundCheck2DIntArray()
	{
		for (int i = 0; i < ArrayLen; i++)
		{
			delete Array[i];
		}

		delete[] Array;
	}
};

int main()
{
	BoundCheck2DIntArray Array(3, 4);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Array[i][j] = i + j;
			cout << Array[i][j] << endl;
		}
	}
}