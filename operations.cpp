#include "stdafx.h"
#include "operations.h"
#include "Student.h"

const char* const OURFILE = "StudentsGrades.db";

void create(Student st) {
	ofstream outfile(OURFILE, ios::out | ios::app | ios::binary);
	outfile.write((const char*)&st, sizeof(Student));
	outfile.close();
}

Student sequentialSearch(long long fnum) {
	ifstream infile(OURFILE, ios::in | ios::binary);
	infile.seekg(0, infile.end);
	int numStudents = infile.tellg() / sizeof(Student);
	infile.seekg(0);
	long long* facNumbers = new long long[numStudents]; // array to store all facNumbers in the file
	for (int i = 0; i < numStudents; ++i)
	{
		infile.seekg(i * sizeof(Student));
		infile.read((char*)&(facNumbers[i]), sizeof(long long));
	}
	int index = seekIndex(facNumbers, numStudents, fnum);
	Student st;
	if (index != -1) // if value is valid
	{
		infile.seekg((index) * sizeof(Student));
		infile.read((char*)&st, sizeof(Student));
		delete facNumbers;
		infile.close();
	}
	return st;
}

int seekIndex(long long* list, int size, long long fnum) // seeks facNumber's index; returns the first occurence if more than one
{
	for (int i = 0; i < size; ++i)
	{
		if (list[i] == fnum) return i;
	}
	return -1; // invalid value in case "Record not found!"
}