#include "Date.h"
#include <iomanip>

Date::Date()
{
	day = 1;
	month = 1;
	year = 1900;
}

Date::Date(string date)
{
	day = stoi(date.substr(8, 2));
	month = stoi(date.substr(5, 2));
	year = stoi(date.substr(0, 4));
}


Date::Date(unsigned short day, unsigned short month, unsigned year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

/*********************************
 * GET Methods
 ********************************/

unsigned short Date::getDay() const
{
	return day;
}

unsigned short Date::getMonth() const
{
	return month;
}

unsigned Date::getYear() const
{
	return year;
}

/*********************************
 * SET Methods
 ********************************/

void Date::setDay(unsigned short day)
{
	this->day = day;
}

void Date::setMonth(unsigned short month)
{
	this->month = month;
}

void Date::setYear(unsigned year)
{
	this->year = year;
}

/*********************************
 * Show Date
 ********************************/

 // disply a Date in a nice format
ostream& operator<<(ostream& out, const Date & date)
{
	return out << setfill('0') << setw(4) << date.year << "/" << setfill('0') << setw(2) << date.month << "/" << setfill('0') << setw(2) << date.day << endl;
}

bool Date::leapYear(int year) //verifica se o ano é bissexto
{
	if (year % 400 == 0)
		return true;
	else if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}

int Date::daysMonth(int year, int month)  //retorna o número de dias por mês
{
	vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && leapYear(year))
		return 29;

	return months[month];
}