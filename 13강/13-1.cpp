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

class Point
{
private:
	int X, Y;

public:
	Point(int x, int y) : X(x), Y(y)
	{

	}

	void ShowPosition() const
	{
		cout << "X Pos : " << X << " Y Pos : " << Y << endl;
	}
};

template<typename T>
void SwapValue(T* Value1, T* Value2)
{
	T Temp = *Value1;
	*Value1 = *Value2;
	*Value2 = Temp;
}

template<class T>
T SumArray(T Array[], int Len)
{
	T Sum = 0;

	for (int i = 0; i < Len; i++)
	{
		Sum += Array[i];
	}

	return Sum;
}

int main()
{
	Point P1(3, 5);
	Point P2(4, 4);

	P1.ShowPosition();
	P2.ShowPosition();

	SwapValue(&P1, &P2);

	P1.ShowPosition();
	P2.ShowPosition();

	int Array1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	cout << SumArray(Array1, 10) << endl;

	double Array2[10] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10 };

	cout << SumArray(Array2, 10) << endl;
}

