#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include "Date.h"
#include "String.h"
typedef enum
	{SECRETARY = 1, EMPLOYED = 2, MANAGER = 3, DIRECTOR = 4} 
		Status;
class Employee
{
	private:
		String Firstname; // first name
		String Lastname; // last name
		const Date Birthdate; // date of birth
		const int Id; // id number of worker
		const Date Workdate; // date that worker started
		double Salary; // salary
		Status Worker;

	// method receives index and return enum type status //
	Status Convert(int index){
	if (index == 1)
		return SECRETARY;
	else
		if (index == 2)
			return EMPLOYED;
		else
			if (index ==3)
				return MANAGER;
			else
				return DIRECTOR;
	}

	public:
			// Default Constructor //
	Employee::Employee();

		// C'tor with values //
	Employee::Employee(char* Firstname,char* Lastname,Date Birthdate,const int Id,const Date Workdate,double Salary,int Worker);

	// Distructor //
	//Employee::~Employee(); 

		// output the worker's details //
	void print(Date today);

		//Receieve today's date and retuurn how long the worker is in the company // 
	Date Seniority(Date today);
	
		// same thing like Seniority' but returns worker's age //
	Date Age(Date today);

		// raise each employee in one rank and upgrade his salary //
	void Employee::promotion();
};

#endif //__EMPLOYEE_H__