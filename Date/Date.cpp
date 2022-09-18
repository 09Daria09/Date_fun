#include "Date.h"
#include<iostream>
using namespace std;
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int d)
{
	day = d;
	month = 0;
	year = 0;
}
Date::Date(int d, int m) :Date(d)
{
	month = m;
	year = 0;
}
Date::Date(int d, int m, int y) : Date(d, m)
{
	year = y;
}
///
void Date::Print()
{
	cout << "День " << day << endl;
	cout << "Месяц " << month << endl;
	cout << "Год " << year << endl;
}
int Date::Getd()
{
	return day;
}
void Date::Setd(int d)
{
	day = d;
}//Ввод дня
int Date::Getm()
{
	return month;
}
void Date::Setm(int m)
{
	month = m;
}//Ввод месяца
int Date::Gety()
{
	return year;
}
void Date::Sety(int y)
{
	year = y;
}//Ввод года
void Date::Input()
{
	Setd(Getd());
	Print_Month();
	Setm(Getm());
	Sety(Gety());
	//system("cls");//стирание консоли
}
///
bool Date::fouryear() const
{
	return (year % 4 == 0);
}
void Date::Print_Month()
{
	cout << JAN << ".Январь" << endl;
	cout << FEB << ".Февраль" << endl;
	cout << MAR << ".Март" << endl;
	cout << APR << ".Апрель" << endl;
	cout << MAY << ".Май" << endl;
	cout << JUN << ".Июнь" << endl;
	cout << JUL << ".Июль" << endl;
	cout << AUG << ".Август" << endl;
	cout << SEP << ".Сентябрь" << endl;
	cout << OCT << ".Октябрь" << endl;
	cout << NOV << ".Ноябрь" << endl;
	cout << DEC << ".Декабрь" << endl;
}
///
void Date::Febfun()
{
	if (fouryear() == 1)
	{
		if (day == 29)
		{
			day = 1;
			month = MAR;
		}
		else
		{
			day++;
		}
	}
	else
	{
		if (day == 28)
		{
			day = 1;
			month = MAR;
		}
		else
		{
			day++;
		}
	}

}
void Date::Day_30()
{
	if (day == 30)
	{
		Func_Month();
	}
	else
	{
		day++;
	}
}
void Date::Day_31()
{

	if (day == 31)
	{
		Func_Month();
	}
	else
	{
		day++;
	}
}
void Date::Func_Month()
{
	if (day == 31 && month == 12)
	{
		Func_Year();
		return;
	}
	day = 1;
	switch (month)
	{
	case JAN:
		month = FEB;
		break;
	case MAR:
		month = APR;
		break;
	case APR:
		month = MAY;
		break;
	case MAY:
		month = JUN;
		break;
	case JUN:
		month = JUL;
		break;
	case JUL:
		month = AUG;
		break;
	case AUG:
		month = SEP;
		break;
	case SEP:
		month = OCT;
		break;
	case OCT:
		month = NOV;
		break;
	case NOV:
		month = DEC;
		break;
	}
}
void Date::Func_Year()
{
	day = 1;
	year = year + 1;
	month = JAN;
}
///
void Date::Jun_1()
{
	day = 31;
	year--;
	month = DEC;
}
void Date::Mart_1()
{
	if (fouryear() == 1)
	{
		day = 29;
		month--;
	}
	else
	{
		day = 28;
		month--;
	}
}
void Date::Day_Minus()
{
	for (int i = 1; i < 8; i++)
	{
		if (month == JAN)
		{
			Jun_1();
			return;
		}
		if (month == MAR)
		{
			Mart_1();
			return;
		}
		if (i % 2 == 0)
		{
			month--;
			day = 31;
		}
		else if (i % 2 != 0)
		{
			month--;
			day = 30;
		}
	}
	for (int i = 8; i < 12; i++)
	{
		if (i % 2 == 0)
		{
			month--;
			day = 30;
		}
		else
		{
			month--;
			day = 31;
		}
	}
}
///
void Date::Count_month()
{
	switch (month)
	{
	case JAN:
		month = FEB;
		day = 1;
		break;
	case FEB:
		month = MAR;
		day = 1;
		break;
	case MAR:
		month = APR;
		day = 1;
		break;
	case APR:
		month = MAY;
		day = 1;
		break;
	case MAY:
		month = JUN;
		day = 1;
		break;
	case JUN:
		month = JUL;
		day = 1;
		break;
	case JUL:
		month = AUG;
		day = 1;
		break;
	case AUG:
		month = SEP;
		day = 1;
		break;
	case SEP:
		month = OCT;
		day = 1;
		break;
	case OCT:
		month = NOV;
		day = 1;
		break;
	case NOV:
		month = DEC;
		day = 1;
		break;
	}
}
void Date::Count_year()
{
	day = 1;
	year++;
	month = JAN;
}
///
void Date::Count_month_minus()
{
	switch (month)
	{
	case DEC:
		month = NOV;
		day = 30;
		break;
	case NOV:
		month = OCT;
		day = 31;
		break;
	case OCT:
		month = SEP;
		day = 30;
		break;
	case SEP:
		month = AUG;
		day = 31;
		break;
	case AUG:
		month = JUL;
		day = 31;
		break;
	case JUL:
		month = JUN;
		day = 30;
		break;
	case JUN:
		month = MAY;
		day = 31;
		break;
	case MAY:
		month = APR;
		day = 30;
		break;
	case APR:
		month = MAR;
		day = 31;
		break;
	case FEB:
		month = JAN;
		day = 31;
		break;
	}
}
void Date::Year_minus()
{
	year--;
	month = DEC;
	day = 31;
}


