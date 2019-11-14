#ifndef __DATE_H__
#define __DATE_H
#define _CRT_SECURE_NO_WARNINGS
#include <ctime> // date/time libary
#include <iostream> // I/O
using namespace std;
class Date 
{
	private: // private members of class
		int day;
		int month;
		int year;

		friend int Get_year(Date other){
			return other.year;
		}		
	
		friend int Get_month(Date other){
			return other.month;
		}
			
		friend int Get_day(Date other){
			return other.day;
		}
	
	public: // public methods

	Date::Date(); //default C'tor with current date

	Date::Date(const Date &other); // Copy C'tor

	Date::Date(int d,int m,int y); // C'tor with date according to input

//	Date::~Date(); // Distructor

	void Date::SetYear(int y);

	void Date::SetMonth(int m);

	void Date::SetDay(int d);

	int Date::GetDays();

	void PrintDate() const; // prints date to screen

	Date CalculateDates(Date other); // calculate the differance of two dates in format dd\mm\yyyy

	int Get_year(); // return the field 'year' 

};

#endif __DATE_H__