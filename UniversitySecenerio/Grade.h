#pragma once


#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"Students.h"
#include"Courses.h"
using namespace std;

class Grade {
	int gradeID;
	int studentID;
	int courseID;
	char grade;
	Courses* course;
	Students* student;
	char checkgrade(char);
public:
	Grade();
	Grade(int c, int a, int b, char g);
	int getGradeID()const;
	char getGrade()const;
	void setGrade(char g);
	void setSId(int g);
	void setCId(int g);
	void setGradeID(int g);

	void setStudent_Course(Courses* C, Students* S);
	int getStuID()const;
	int getCourseID()const;
	int validateGradeID(vector<Grade>);
};

