#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

class Exam {
	friend bool operator == (const Exam& first, const Exam& second);
	friend ostream& operator<<(ostream& out, const Exam& exam);
	friend istream& operator>>(istream& in, Exam& exam);
private:
	int course;
	int codeOfGroupe;
	string studentSurname;
	int recordBookNumber;
	string subject;
	int mark;
public:
	Exam();
	Exam(const Exam& exam);

	bool operator==(Exam& otherExam);
	Exam& operator=(Exam const& exam);

	void fill();
	void change();

	void setCodeOfGroupe(int num);
	void setCourse(int num);
	void setRecordBookNumber(int num);
	void setStudentSurname(string str);
	void setMark(int num);

	int getCodeOfGroupe();
	int getCourse();
	int getRecordBookNumber();
	string getStudentSurname();
	string getSubject();
	int getMark();

	int static inputInRange(int left, int right);
	int static inputInt();
};