#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Courses.h"
#include"Persons.h"
#include"Students.h"
#include"Faculty.h"
using namespace std;

class Courses;
class Faculty;

class Department {
	int departmentID;
	string name;
	string headOfDept;
	vector<Courses*> coursesOffered;
	vector<Faculty*> facultyMembers;
public:
	Department();
	Department(int c,string a, string b);
	void add_Course(Courses* C);
	void add_Faculty(Faculty* F);
	void setName(string a);
	void setHead(string a);
	void setID(int a);
	void setCourses(vector<Courses*> a);
	void setFaculty(vector<Faculty*> a);
	string getName()const;
	string getHead() const;
	int getID()const;
	void display(vector<Department>);
	vector<Courses*> getCourses();
	vector<Faculty*> getFaculties();
	void addCourse(Courses*);
	void addFaculty(Faculty*);
};

