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

class MyString
{
private:
	int Len;
	char* TargetString;

public:
	MyString() 
	{
		Len = 0;
		TargetString = NULL;
	}

	MyString(const char* String)
	{
		Len = strlen(String) + 1;

		TargetString = new char[Len];
		strcpy(TargetString, String);
	}
	
	MyString(const MyString& String)
	{
		Len = String.Len;

		TargetString = new char[Len];
		strcpy(TargetString, String.TargetString);
	}

	~MyString()
	{
		if (TargetString != NULL)
		{
			delete[] TargetString;
		}
	}

	/*MyString& operator=(const MyString& String)
	{
		Len = String.Len;

		TargetString = new char[Len];
		strcpy(TargetString, String.TargetString);

		return *this;
	}*/

	MyString& operator=(const MyString& String)
	{
		if (TargetString != NULL)
		{
			delete[] TargetString;
		}

		Len = String.Len;

		TargetString = new char[Len];
		strcpy(TargetString, String.TargetString);

		return *this;
	}

	/*MyString& operator+=(const MyString& String)
	{
		Len = Len + String.Len;

		TargetString = new char[Len];
		strcat(TargetString, String.TargetString);

		return *this;
	}*/

	MyString& operator+=(const MyString& String)
	{
		Len += String.Len - 1;

		char* TempString = new char[Len];
		strcpy(TempString, TargetString);
		strcat(TempString, String.TargetString);

		if (TargetString != NULL)
		{
			delete[] TargetString;
		}

		/*TargetString = new char[Len];
		strcpy(TargetString, TempString);*/

		TargetString = TempString;

		return *this;
	}

	/*bool operator==(const MyString& String)
	{
		return TargetString == String.TargetString;
	}*/

	bool operator==(const MyString& String)
	{
		return strcmp(TargetString, String.TargetString) ? false : true;
	}

	/*MyString operator+(const MyString& String)
	{
		Len = Len + String.Len;

		TargetString = new char[Len];
		strcat(TargetString, String.TargetString);

		return *this;
	}*/

	MyString operator+(const MyString& String)
	{
		char* TempString = new char[Len + String.Len - 1];
		strcpy(TempString, TargetString);
		strcat(TempString, String.TargetString);

		MyString Temp(TempString);
		delete[] TempString;
		return Temp;
	}

	friend ostream& operator<<(ostream& os, const MyString& String);
	friend istream& operator>>(istream& is, MyString& String);
};

ostream & operator<<(ostream & os, const MyString & String)
{
	os << String.TargetString;

	return os;
}

istream& operator>>(istream & is, MyString & String)
{
	char Str[100];
	is >> Str;
	String = MyString(Str);

	return is;
}


int main()
{
	MyString Str1 = "I Like ";
	MyString Str2 = "String Class";
	MyString Str3 = Str1 + Str2;

	cout << Str1 << endl;
	cout << Str2 << endl;
	cout << Str3 << endl;

	Str1 += Str2;

	if (Str1 == Str3)
	{
		cout << "Same" << endl;
	}
	else
	{
		cout << "Diff" << endl;
	}

	MyString Str4;
	cout << "Input String" << endl;
	cin >> Str4;
	cout << "Your String is " << Str4 << endl;
}

