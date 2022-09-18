#include<iostream>
#include"Date.h"
using namespace std;
enum { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
Date operator+(Date& obj, int a)
{
	for (int i = 0; i < a; i++)
	{
		if (obj.Getm() == APR || obj.Getm() == JUN || obj.Getm() == SEP || obj.Getm() == NOV)
		{
			if (obj.Getd() == 30)
			{
				obj.Count_month();
				continue;
			}
			obj.Setd(obj.Getd() + 1);
			continue;
		}
		if (obj.Getm() == FEB)
		{
			if (obj.fouryear() == 1)
			{
				if (obj.Getd() == 29)
				{
					obj.Count_month();
					continue;
				}
				obj.Setd(obj.Getd() + 1);
				continue;
			}
			if (obj.Getd() == 28)
			{
				obj.Count_month();
				continue;
			}
			obj.Setd(obj.Getd() + 1);
			continue;
		}
		if (obj.Getm() == DEC)
		{
			if (obj.Getd() == 31)
			{
				obj.Count_year();
				continue;
			}
			obj.Setd(obj.Getd() + 1);
			continue;
		}
		if (obj.Getm() == JAN || obj.Getm() == MAR || obj.Getm() == MAY || obj.Getm() == JUL || obj.Getm() == AUG || obj.Getm() == OCT)
		{
			if (obj.Getd() == 31)
			{
				obj.Count_month();
				continue;
			}
			obj.Setd(obj.Getd() + 1);
			continue;
		}
	}
	return obj;
}
Date operator-(Date& obj, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (obj.Getm() == MAR)
		{
			if (obj.Getd() == 1)
			{
				if (obj.fouryear() == 1)
				{
					obj.Setd(29);
					obj.Setm(FEB);
					continue;
				}
				obj.Setm(FEB);
				obj.Setd(28);
				continue;
			}
			obj.Setd(obj.Getd() - 1);
			continue;
		}
		else if (obj.Getm() == JAN)
		{
			if (obj.Getd() == 1)
			{
				obj.Year_minus();
				continue;
			}
			obj.Setd(obj.Getd() - 1);
			continue;
		}
		else
		{
			if (obj.Getd() == 1)
			{
				obj.Count_month_minus();
				continue;
			}
			obj.Setd(obj.Getd() - 1);
			continue;
		}
	}
	return obj;
}
Date operator-(Date& obj, Date& obj1)
{
	int allday = 0;
	int countmonth = 0;
	int countmonth1 = 0;
	double y, y1;
	double res, res1;
	float highY = (float)obj.Gety() / 4;
	float highY1 = (float)obj1.Gety() / 4;
	y = (double)highY + (obj.Gety() * 365);
	y1 = (double)highY1 + (obj1.Gety() * 365);
	int sim_month = obj.Getm();
	int sim_month1 = obj1.Getm();
	for (int i = 0; i < sim_month; i++)
	{
		if (obj.Getm() == APR || obj.Getm() == JUN || obj.Getm() == SEP || obj.Getm() == NOV)
		{
			allday = 30;
			obj.Setm(obj.Getm() - 1);
		}
		else if (obj.Getm() == FEB)
		{
			if (obj.fouryear() == 1)
			{
				allday = 29;
				obj.Setm(obj.Getm() - 1);
			}
			else
			{
				allday = 28;
				obj.Setm(obj.Getm() - 1);
			}
		}
		else
		{
			allday = 31;
			obj.Setm(obj.Getm() - 1);
		}
		countmonth += allday;
	}
	for (int i = 0; i < sim_month1; i++)
	{
		if (obj1.Getm() == APR || obj1.Getm() == JUN || obj1.Getm() == SEP || obj1.Getm() == NOV)
		{
			allday = 30;
			obj1.Setm(obj1.Getm() - 1);
		}
		else if (obj1.Getm() == FEB)
		{
			if (obj1.fouryear() == 1)
			{
				allday = 29;
				obj1.Setm(obj1.Getm() - 1);
			}
			else
			{
				allday = 28;
				obj1.Setm(obj1.Getm() - 1);
			}
		}
		else
		{
			allday = 31;
			obj1.Setm(obj1.Getm() - 1);
		}
		countmonth1 += allday;
	}
	res = obj.Getd() + countmonth + y;
	res1 = obj1.Getd() + countmonth1 + y1;
	double allRes;
	allRes = res - res1;
	return allRes;
}
Date& operator++(Date& obj)
{
	if (obj.Getm() == APR || obj.Getm() == JUN || obj.Getm() == SEP || obj.Getm() == NOV)
	{
		obj.Day_30();
		return obj;
	}
	else if (obj.Getm() == FEB)
	{
		obj.Febfun();
		return obj;
	}
	else
	{
		obj.Day_31();
		return obj;
	}
}
Date operator++(Date& obj, int)
{
	Date def;
	def.Setd(obj.Getd());
	def.Setm(obj.Getm());
	def.Sety(obj.Gety());
	if (def.Getm() == APR || def.Getm() == JUN || def.Getm() == SEP || def.Getm() == NOV)
	{
		def.Day_30();
		return def;
	}
	else if (def.Getm() == FEB)
	{
		def.Febfun();
		return def;
	}
	else
	{
		def.Day_31();
		return def;
	}
}
Date& operator--(Date& obj)
{
	if (obj.Getd() == 1)
	{
		obj.Day_Minus();
		return obj;
	}
	else
	{
		obj.Setd(obj.Getd() - 1);
		return obj;
	}
}
Date operator--(Date& obj, int)
{
	Date def;
	def.Setd(obj.Getd());
	def.Setm(obj.Getm());
	def.Sety(obj.Gety());
	if (def.Getd() == 1)
	{
		def.Day_Minus();
		return def;
	}
	else
	{
		def.Setd(def.Getd() - 1);
		return def;
	}
}
Date operator-=(Date& obj, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (obj.Getm() == MAR)
		{
			if (obj.Getd() == 1)
			{
				if (obj.fouryear() == 1)
				{
					obj.Setd(29);
					obj.Setm(FEB);
					continue;
				}
				obj.Setd(28);
				obj.Setm(FEB);
				continue;
			}
			obj.Setd(obj.Getd() - 1);
			continue;
		}
		else if (obj.Getm() == JAN)
		{
			if (obj.Getd() == 1)
			{
				obj.Year_minus();
				continue;
			}
			obj.Setd(obj.Getd() - 1);
			continue;
		}
		else
		{
			if (obj.Getd() == 1)
			{
				obj.Count_month_minus();
				continue;
			}
			obj.Setd(obj.Getd() - 1);
			continue;
		}
	}
	return obj;
}
Date operator+=(Date& obj, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (obj.Getm() == APR || obj.Getm() == JUN || obj.Getm() == SEP || obj.Getm() == NOV)
		{
			if (obj.Getd() == 30)
			{
				obj.Count_month();
				continue;
			}
			obj.Setd(obj.Getd() + 1);
			continue;
		}
		if (obj.Getm() == FEB)
		{
			if (obj.fouryear() == 1)
			{
				if (obj.Getd() == 29)
				{
					obj.Count_month();
					continue;
				}
				obj.Setd(obj.Getd() + 1);
				continue;
			}
			if (obj.Getd() == 28)
			{
				obj.Count_month();
				continue;
			}
			obj.Setd(obj.Getd() + 1);
			continue;
		}
		if (obj.Getm() == DEC)
		{
			if (obj.Getd() == 31)
			{
				obj.Count_year();
				continue;
			}
			obj.Setd(obj.Getd() + 1);
			continue;
		}
		if (obj.Getm() == JAN || obj.Getm() == MAR || obj.Getm() == MAY || obj.Getm() == JUL || obj.Getm() == AUG || obj.Getm() == OCT)
		{
			if (obj.Getd() == 31)
			{
				obj.Count_month();
				continue;
			}
			obj.Setd(obj.Getd() + 1);
			continue;
		}
	}
	return obj;
}
const bool operator<(Date& obj1, Date& obj2)
{
	if (obj1.Gety() < obj2.Gety())
	{
		return true;
	}
	else if (obj1.Gety() == obj2.Gety())
	{
		if (obj1.Getm() < obj2.Gety())
		{
			return true;
		}
		else if (obj1.Getm() == obj2.Gety())
		{
			if (obj1.Getd() < obj2.Gety())
			{
				return true;
			}
		}
	}
	return false;
}
const bool operator>(Date& obj1, Date& obj2)
{
	if (obj1.Gety() > obj2.Gety())
	{
		return true;
	}
	else if (obj1.Gety() == obj2.Gety())
	{
		if (obj1.Getm() > obj2.Gety())
		{
			return true;
		}
		else if (obj1.Getm() == obj2.Gety())
		{
			if (obj1.Getd() > obj2.Gety())
			{
				return true;
			}
		}
	}
	return false;
}
const bool operator>=(Date& obj1, Date& obj2)
{
	if (obj1.Gety() == obj2.Gety() && obj1.Getm() == obj2.Getm() && obj1.Getd() == obj2.Getd())
	{
		return true;
	}
	if (obj1.Gety() > obj2.Gety())
	{
		return true;
	}
	if (obj1.Gety() == obj2.Gety() && obj1.Getm() > obj2.Getm())
	{
		return true;
	}
	if (obj1.Gety() == obj2.Gety() && obj1.Getm() == obj2.Getm() && obj1.Getd() > obj2.Getd())
	{
		return true;
	}
	return false;
}
const bool operator<=(Date& obj1, Date& obj2)
{
	if (obj1.Gety() == obj2.Gety() && obj1.Getm() == obj2.Getm() && obj1.Getd() == obj2.Getd())
	{
		return true;
	}
	if (obj1.Gety() < obj2.Gety())
	{
		return true;
	}
	if (obj1.Gety() == obj2.Gety() && obj1.Getm() < obj2.Getm())
	{
		return true;
	}
	if (obj1.Gety() == obj2.Gety() && obj1.Getm() == obj2.Getm() && obj1.Getd() < obj2.Getd())
	{
		return true;
	}
	return false;
}
const bool operator==(Date& obj1, Date& obj2)
{
	if (obj1.Gety() == obj2.Gety() && obj1.Getm() == obj2.Getm() && obj1.Getd() == obj2.Getd())
	{
		return true;
	}
	return false;
}
const bool operator!=(Date& obj1, Date& obj2)
{
	if (obj1.Gety() == obj2.Gety() && obj1.Getm() == obj2.Getm() && obj1.Getd() == obj2.Getd())
	{
		return false;
	}
	return true;
}
int main()
{
	setlocale(LC_ALL, "ru");
	Date firstDate(14, 8, 1930);
	Date secondDate(12, 3, 2001);
	Date thirdDate = firstDate + 120;
	thirdDate.Print();
	cout << "********************" << endl;
	Date fourthDate = secondDate - 123;
	fourthDate.Print();
	cout << "*******************" << endl;
	Date differenceDays = thirdDate - fourthDate;
	differenceDays.Print();
	cout << "******************" << endl;
	++firstDate;
	firstDate.Print();
	cout << "******************" << endl;
	secondDate++.Print();
	cout << "********************" << endl;
	secondDate.Print();
	--firstDate;
	firstDate.Print();
	cout << "********************" << endl;
	secondDate--.Print();
	cout << "********************" << endl;
	secondDate.Print();
	cout << "*******************" << endl;
	firstDate -= 365;
	firstDate.Print();
	cout << "*******************" << endl;
	firstDate += 365;
	firstDate.Print();
	cout << "******************" << endl;
	bool a = firstDate < secondDate;
	cout << a << endl;
	cout << "******************" << endl;
	bool b = firstDate > secondDate;
	cout << b << endl;
	cout << "******************" << endl;
	bool c = firstDate <= secondDate;
	cout << c << endl;
	cout << "******************" << endl;
	bool d = firstDate >= secondDate;
	cout << d << endl;
	cout << "******************" << endl;
	bool e = firstDate == secondDate;
	cout << e << endl;
	cout << "******************" << endl;
	bool x = firstDate != secondDate;
	cout << x << endl;
}