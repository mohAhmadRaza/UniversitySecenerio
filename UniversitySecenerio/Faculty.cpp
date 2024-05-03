#include<iostream>
#include<string>
#include"Faculty.h"
#include<vector>
#include "Courses.h" 
#include<iomanip>
#include "Students.h" 
using namespace std;

Faculty::Faculty() {
	facultyID = 0;
	name = "";
	email = "";
	phoneNumber = "";
};
Faculty::Faculty(int d, string a, string b, string c) :Persons(a, b, c) {
	facultyID = d;
}
void Faculty::teach_Course(Courses* C) {
	coursesTaught.push_back(C);
}
void Faculty::addStudents(Students* S) {
	supervisedStudents.push_back(S);
}
int Faculty::getID()const {
	return facultyID;
}
void Faculty::setID(int a) {
	facultyID = a;
}
void Faculty::setCourses(vector<Courses*> S) {
	coursesTaught = S;
}
void Faculty::setCourses(vector<Students*>S) {
	supervisedStudents = S;
}
void Faculty::display(vector<Faculty*> F1) {
	cout << "----------------------------------------------------" << endl;
	cout << "ID" << right << setw(7) << "Name" << right << setw(18) << "Email" << right << setw(20) << "Phone" << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < F1.size(); i++) {
		cout << left << setw(5) << F1[i]->getID() << left << setw(17) << F1[i]->getName() << left << setw(21) << F1[i]->getEmail() << F1[i]->getPhone() << endl;
	}
	cout << "----------------------------------------------------" << endl;
	cout << endl;
}