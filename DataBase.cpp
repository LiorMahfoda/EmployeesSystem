#include "DataBase.h"
#define _CRT_SECURE_NO_WARNINGS

DataBase::DataBase() 
{
	max = DEF_SIZE;
	current = 0;
	emp = new  Employee* [DEF_SIZE];

}		

DataBase::DataBase(const Employee& other){

	max = DEF_SIZE;
	current = 0;
	emp = new  Employee* [DEF_SIZE];
}

DataBase::~DataBase()
{
	for (int i=0; i < current;i++)
		delete emp[i];
	delete[] emp;
	current = 0;
}


Employee* DataBase::getEmployee(int index){
	if (index >= current || index < 0 )
		return NULL;
	return emp[index];
}

void DataBase::addEmployee(Employee newEmp){
	Employee** temp = NULL;;
	unsigned int i = 0,index = 0;
	if (current == max){ // there aren't enough room
		current++;
		temp = new Employee*[DEF_SIZE * 2];
		assert(temp);
		for (i=0; i < current ; i++)
			temp[i] = emp[i];
		temp[i] = new Employee(newEmp);
		emp = temp;
	} // end if
	else{ // add new employee
		while(emp==NULL) {
			emp++;
			index++;
		}
		emp[index] = new Employee(newEmp);
		current++;
	} // end else
} // end method

Employee* DataBase::removeEmployee(int index){

	if (index >= current || index < 0){	
		current--;
		return NULL;
	}

	Employee* temp = emp[index];
	for(unsigned int i = index; i<current-1 ;i++)
		emp[i] = emp[i+1];

	current--;
	return temp;
}

void DataBase::print(Date today) const{

	for(unsigned int i=0; i<current ;i++){
		emp[i]->print(today);
		cout<<endl;
	}

	if(current == 0)
		cout<<"The database is empty! "<<endl; 
	cout<<endl;

	//DataBase::~DataBase();
}