#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"Students.h"
#include"Faculty.h"
#include"Project.h"
#include<iomanip>
using namespace std;


Project::Project() {
	projectID = 0;
	title = "";
	description = "";
}
Project::Project(int c,string a, string b, Faculty* F) {
	title = a;
	projectID = c;
	description = b;
	facultySupervised = F;
}
void Project::addStudentsForProjects(Students* S) {
	students.push_back(S);
}

	//Setters
void Project::setTitle(string a) {
	title = a;
}
void Project::setDesc(string a) {
	description = a;
}
void Project::setPID(int a) {
	projectID = a;
}
void Project::setFaculty(Faculty* F) {
	facultySupervised = F;
}
void Project::setStudents(vector<Students*> S) {
	students = S;
}
	//Getters
string Project::getDesc() const {
	return description;
}
string Project::getTitle()const {
	return title;
}
const Faculty* Project::getFacultySupervising() const {
	return facultySupervised;
}
const vector<Students*> Project::getAllStudents()const {
	return students;
}
int Project::getPID()const {
	return projectID;
}
void Project::displayProjectsAll(vector<Project> PR) {
		cout << "Currently Total Projects Are : " << PR.size() << endl;
		cout << "--------------------------------------------" << endl;
		cout << "ID" << right << setw(7) << "Title" << right << setw(43) << "Description" << endl;
		cout << "--------------------------------------------" << endl;

		for (int i = 0; i < PR.size(); i++) {
			cout << left << setw(4) << PR[i].getPID() << left << setw(36) << PR[i].getTitle() << left << setw(18) << PR[i].getDesc() << endl;
		}
		cout << "--------------------------------------------" << endl;
}
void Project::displayProjectsSome(vector<Project> PR, string str1) {
	cout << "Currently, You Are Supervising Projects!!" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "ID" << right << setw(10) << "Title" << right << setw(20) << "Desc." << endl;
	cout << "--------------------------------------------" << endl;
	for (int i = 0; i < PR.size(); i++) {
		if (PR[i].getFacultySupervising()->getName() == str1) {
			cout << left << setw(4) << PR[i].getPID() << left << setw(34) << PR[i].getTitle() << left << setw(15) << PR[i].getDesc() << endl;
		}
	}
	cout << "--------------------------------------------" << endl;
}
int Project::validating_ProjectID(vector<Project> PR,string str1) {
	int id1 = 0; bool again = false;
	do {
		again = false;
		cout << endl;
		cout << "Enter Project ID, To See Enrolled Student : ";
		cin >> id1;
		for (int i = 0; i < PR.size(); i++) {
			if (PR[i].getFacultySupervising()->getName() == str1) {
				if (PR[i].getPID() == id1) {
					again = true;
					break;
				}
			}
		}
		if (!again)
			cout << "Invalid ID Entered" << endl;
	} while (!again);

	return id1;
}
