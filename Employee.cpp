#include "Employee.h" // which includes "Date.h"

	// Default Constructor //
Employee::Employee()
	:Birthdate(Date(24,2,1990)),
	Id(0),
	Workdate(Date(27,3,2012)),
	Firstname("Lior"),
	Lastname("Mahfoda")
{
	Salary = 0;
	Worker = Convert(1);
}

	// constructor makes an object from class Employee //
Employee::Employee(char* firstname,char* lastname,Date birthdate,const int id,const Date workdate,double salary,int worker)

	:Birthdate(Date(birthdate)), //const date
	 Id(id),					// const
     Workdate(Date(workdate)),		// const date
	 Firstname(String()),
	 Lastname(String())
{
	Firstname.UpdateString(firstname); 
	Lastname.UpdateString(lastname);
	Salary = salary;
	Worker = Convert(worker);		// Enum
}

 // Prints employee's details //
void Employee::print(Date today){

	cout<<"Worker's first name: "; 
	Firstname.PrintString();
	cout<<"Worker's last name: "; 
	Lastname.PrintString();
	cout<<"Salary = "<<Salary<<endl;
	cout<<"Id = "<<Id<<endl;

	switch (Worker){

	case SECRETARY: cout<<"Status = secratary"<<endl;
						break;
	case EMPLOYED:	cout<<"Status = employed"<<endl;;
						break;
	case MANAGER:	cout<<"Status = manager"<<endl;;
						break;
	case DIRECTOR:	cout<<"Status = director"<<endl;;
						break;

			default:	
				break;
	};
	Date vetek,age; // today dates
	age = vetek.CalculateDates(Birthdate);
	
	cout<< "The worker's age is: "<<Get_year(age)<<" years,"<<Get_month(age)<<" months, "<<Get_day(age)<<" days "<<endl;;
	
	cout<<endl;	 
	vetek = today.CalculateDates(Workdate); 
	cout<< "The worker's seniority is: "<<Get_year(vetek)<<" years,"<<Get_month(vetek)<<" months, "<<Get_day(vetek)<<" days "<<endl;
}

Date Employee::Seniority(Date today){

	return today.CalculateDates(Workdate); 
}

Date Employee::Age(Date today){
		
	return today.CalculateDates(Birthdate); 
}

	// raise employee's rank by conditions //
void Employee::promotion(){
	if (Worker == SECRETARY){
		Salary += Salary * 0.1;
		Worker = EMPLOYED;
	}
	else
		if (Worker == EMPLOYED){
			Salary += Salary * 0.1;
			Worker = MANAGER;
			}
		else
			if (Worker == MANAGER){
				Worker = DIRECTOR;
				Salary += Salary * 0.1;
			}
			else // Worker = DIRECTOR// can't raise in rank
				Salary*=2;		// double the salary
}