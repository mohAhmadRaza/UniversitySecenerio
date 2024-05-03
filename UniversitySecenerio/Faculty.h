#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"Courses.h"
using namespace std;

class Courses; class Students;

class Faculty :public Persons {
	int facultyID;
	vector<Courses*> coursesTaught;
	vector<Students*> supervisedStudents;
public:
	Faculty();
	Faculty(int d, string a, string b, string c);
	void teach_Course(Courses* C);
	void addStudents(Students* S);
	int getID()const;
	void setID(int a);
	void setCourses(vector<Courses*>);
	void setCourses(vector<Students*>);
	void display(vector<Faculty*> F1);
};