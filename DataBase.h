#ifndef __DataBase_H__
#define __DataBase_H__
#include "Employee.h" // includes string.h & date.h
#define DEF_SIZE 5

class DataBase
{
	private:
		Employee** emp; // double pointer to object class Employee //
		int current;  // current of number employees //
		int max;    // maximum of number employees in the database //

	public:
		// constructor // builds database with 5 workers //
	DataBase();
	
		// distructor //
	~DataBase();

	   // copy constructor //
	DataBase::DataBase(const Employee& other);
	
	
	
	// function receive index of employee and returns a pointer/ if index doesn't exist returns NULL //
	Employee* DataBase::getEmployee(int index);

	//add a new employee to the database by condition //
	void DataBase::addEmployee(Employee newEmp);

	//input the index and remove the Employee from the database//
	Employee* removeEmployee(int index);
	
	//print the entire database//
	void DataBase::print(Date today) const;
};

#endif //__DataBase_H__