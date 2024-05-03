#pragma once 

#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"Students.h"
#include"Faculty.h"
#include"Courses.h"
using namespace std;

class Students; class Courses; class Faculty;

class Enrollment {
	int enrollmentID;
	int studentID;
	int courseID;
	string enrollementDate;
	Students* student;
	Courses* course;
public:
	Enrollment();
	Enrollment(string c, Students* S, Courses* C);
	void setStuID();
	void setCourseID();
	void setDate(string a);
	int getStuID()const;
	int getCourseID()const;
	string getDate()const;
	void setStudent(Students* S);
	void setCourse(Courses* C);
	Students& getStu()const;
	Courses& getCourse()const;
};
