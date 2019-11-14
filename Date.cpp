#include "Date.h"

Date::Date() // current date
{
		time_t rawtime;
		struct tm * timeinfo;

		time ( &rawtime );
		timeinfo = localtime ( &rawtime );

 		day=timeinfo->tm_mday;
		month=timeinfo->tm_mon+1;
		year=timeinfo->tm_year+1900;
}

Date::Date(const Date &other){ // Copy Constructor
	day = other.day;
	month = other.month;
	year = other.year;
}

/*Date::~Date(){ // Distructor
	
	this->day = 1;
	this->month = 1;
	this->year = 1;
}*/

Date::Date(int d,int m,int y) // Constructor with input date
{
	SetYear(y);
    SetMonth(m);
    SetDay(d);
}

void Date::SetYear(int y)
{
	year =( y > 0 )? y : 00 ;
}
void Date::SetMonth(int m)
{
	month = ( m >= 1 && m <= 12)? m : 1 ;
}
void Date::SetDay(int d)
{
	day=( d >= 1 && d <= GetDays() )? d : 1;
}
////////////////////////

int Date::GetDays()
{
	if(month==2) // month = February
	{
		if( year%400==0||((year%4==0)&&(year%100!=0))) // if year is leap
				 return 29;
			 else
				 return 28;
	}
	else if(month==4 || month ==6 || month == 9 || month == 11)
		return 30;
	else
		return 31;

}

void Date::PrintDate() const{
	if(day<10)
      cout<<'0'<<day<<'/';
	else
	  cout<<day<<'/';
	if(month<10)
      cout<<'0'<<month<<'/'<<year<<endl;
	else
	  cout<<month<<'/'<<year<<endl;
}

Date Date::CalculateDates(Date other){
	int d=0,m=0,y=0; // default initallazation
	// this pointer refers to current year. other to next to compare with //

	if (this->year == other.year && this->month == other.month   && this->day == other.day)
		return Date(d,m,y);
	else


	if (this->year > other.year)
		y = this->year - other.year;
	else
		if (this->year < other.year)
			y = (other.year - this->year) * (-1);

	if (this->month > other.month)	
		m = this-> month - other.month;
	else
		if (this->month < other.month)
		{
			y--;
			m = this-> month - other.month + 12;
		}
	if (this->day > other.day)
		d = this->day - other.day;		
	else
		if (this->day > other.day)
		{
		d = d + other.GetDays();
		m--;
		}
		Date temp(d,m,y);
		return temp;

} // end method
