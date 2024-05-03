#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"Students.h"
#include"Faculty.h"
using namespace std;

class Project; class Students; class Faculty;
//ostream& operator << (ostream&, const Project&);

class Project {
	int projectID;
	string title;
	string description;
	vector<Students*> students;
	Faculty* facultySupervised;
public:
	Project();
	Project(int c, string a, string b, Faculty* F);
	void addStudentsForProjects(Students* S);
	
	//Setters
	void setTitle(string a);
	void setDesc(string a);
	void setPID(int a);
	void setFaculty(Faculty* F);
	void setStudents(vector<Students*> S);
	//Getters
	string getDesc() const;
	string getTitle()const;
	const Faculty* getFacultySupervising() const;
	const vector<Students*> getAllStudents()const;
	int getPID()const;
	void displayProjectsAll(vector<Project> PR);
	void displayProjectsSome(vector<Project>, string);
	int validating_ProjectID(vector<Project>, string str1 = "");
};

//ostream& operator<<(ostream& cout, const Project& S) {
//	cout << "ID    : " << S.getPID() << endl;
//	cout << "Title : " << S.getTitle() << endl;
//	cout << "Desc. : " << S.getDesc() << endl;
//	return cout;
//}