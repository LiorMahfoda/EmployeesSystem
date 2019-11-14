#include "String.h"

String::String(char* str){ // default constructor
	str  = NULL;
}
String::String(const char* st){ // C'tor
	this->str = NULL;
 	str = new char [strlen(st)+1]; // allocating memory
	assert(str);
	strcpy(str,st); // copy // puts '\0' at the end of str
}
	 
String::String(const String &st){ // copy C'tor
	str = new char [strlen(st.str)+1]; // allocating memory
	assert(str);
	strcpy(str,st.str); // copy // puts '\0' at the end of str
}

String::~String(){ // Distructor which erase the  string and puts NULL
	delete str; // delete string
}

void String::PrintString(){ // prints entire string
	unsigned int i = 0;
	while (str[i]!=NULL)
	{
		cout<<str[i];
		i++;
	}	
	cout<<endl;
}

void String::UpdateString(char* st){ // method need to update the string by input
	delete[] str;
	str = NULL;
	str = new char [strlen(st)+1];
	assert(str);
	strcpy(str,st);
}
