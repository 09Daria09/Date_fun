#pragma once
class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	Date(int d);
	Date(int d, int m);
	Date(int d, int m, int y);
	///
	void Print();
	void Input();
	int Getd();
	void Setd(int d);
	int Getm();
	void Setm(int m);
	int Gety();
	void Sety(int y);
	///
	enum { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
	bool fouryear() const;
	void Print_Month();
	void Febfun();
	void Day_30();
	void Day_31();
	void Func_Month();
	void Func_Year();
	void Jun_1();
	void Mart_1();
	void Day_Minus();
	void Count_month();
	void Count_year();
	void Count_month_minus();
	void Year_minus();
};



