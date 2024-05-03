#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"Students.h"
#include"Assignments.h"
#include"ReadWritingInFile.h"
using namespace std;

class Students;
class Assignments;
class ReadWrite;

class Courses {
	int courseID;
	string name;
	int creditHours;
	string instructor;
	vector<Students*> enrolled_students;
	vector<Assignments> totalAssignments;
	string checkName(string);
public:
	Courses();
	Courses(int d, string a, int b, string c);

	//Currently
	void totalStudents(vector<Students*> S);
	void setTotalAssignments(vector<Assignments> assign);


	//Addition in the current
	void add_students(Students* ST);
	void add_Assignments(Assignments& AST);

	//setters
	void setName(string a);
	void setInstructor(string a);
	void setHours(int a);
	void setID(int a);

	//getters
	string getName() const;
	string getInstructor()const;
	int getHours()const;
	int getID()const;

	//Inserting data into file
	void Students_Enr_In_Each_Course() const;

	//Getting data from the file
	vector<Students> get_STU_from_file();
	vector<Assignments*> get_ASSIGNS_from_file() const;

	void displayOnScreenAllCourses(vector<Courses*> S);
	string validate_Course_Name(vector<Courses*>);
};
