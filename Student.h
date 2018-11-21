#ifndef STUDENT_H
#define STUDENT_H
#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

class Student
{
private:
	long long fnum;  // [0,2^50] c [-2^63,2^63-1]
	char fname[257]; // 256 + '\0'
	char lname[257]; // 256 + '\0'
	short grade;  // [2,6] c [-128,127]
public:
	Student();
	Student(const long long&, const char*, const char*, const short&);
	void set_fnum(const long long&);
	void set_fname(const char*);
	void set_lname(const char*);
	void set_grade(const short&);
	long long get_fnum() const;
	const char* get_fname() const;
	const char* get_lname() const;
	short get_grade() const;

	friend istream& operator>>(istream&, Student&);
	friend ifstream& operator>>(ifstream&, Student&);
	friend ostream& operator<<(ostream&, const Student&);
	friend ofstream& operator<<(ofstream&, Student&);
};
#endif // !1