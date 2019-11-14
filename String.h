#ifndef __STRING_H__
#define __STRING_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // strndard I/O libary
#include <string.h> // strcpy/strlen functions 
#include <assert.h> // for allocation check 
using namespace std;
#define SIZE 120  // max characthers of a string
class String {
	private:

		char* str; // pointer to char. we use to make a string by dynamic allocation


	public:

	String(char* str = NULL); // Default Constructor

    String(const char* st); // another C'tor

	String(const String &st); // copy C'tor

	~String(); // D'tor

	void PrintString() ;

	void UpdateString(char* st);

};

#endif __STRING_H__