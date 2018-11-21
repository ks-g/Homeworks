#include "stdafx.h"
#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	set_fnum(-1);
	set_fname("default_first");
	set_lname("default_last");
	set_grade(-1);
}

Student::Student(const long long& fnum, const char* fname, const char* lname, const short& grade)
{
	set_fnum(fnum);
	set_fname(fname);
	set_lname(lname);
	set_grade(grade);
}

void Student::set_fnum(const long long& fnum)
{
	this->fnum = fnum;
}

void Student::set_fname(const char* fname)
{
	int len = strlen(fname);
	strcpy_s(this->fname, ++len, fname);
}

void Student::set_lname(const char* lname)
{
	int len = strlen(lname);
	strcpy_s(this->lname, ++len, lname);
}

void Student::set_grade(const short& grade)
{
	this->grade = grade;
}

long long Student::get_fnum() const
{
	return fnum;
}

const char* Student::get_fname() const
{
	return fname;
}

const char* Student::get_lname() const
{
	return lname;
}

short Student::get_grade() const
{
	return grade;
}

istream& operator>>(istream& is, Student& st)
{
	is >> st.fnum;
	is >> st.fname;
	is >> st.lname;
	is >> st.grade;
	return is;
}

ostream& operator<<(ostream& os, const Student& st)
{
	os << st.fnum << " " << st.fname << " " << st.lname << " " << st.grade << "\n";
	return os;
}

ifstream& operator>>(ifstream& is, Student& st) {
	is.read((char*)&st, sizeof(Student));
	return is;
}

ofstream& operator<<(ofstream& os, Student& st) {
	os.write((char*)&st, sizeof(Student));
	return os;
}