#include<iostream>
#include<string>
#include<vector>
#include"Courses.h"
#include"Department.h"
#include"Persons.h"
#include"Students.h"
#include"Faculty.h"
#include<iomanip>
using namespace std;

Department::Department() {
	departmentID = 0;
	name = "";
	headOfDept = "";
}
Department::Department(int c,string a, string b) {
	name = a;
	headOfDept = b;
	departmentID = c;
}
void Department::add_Course(Courses* C) {
	coursesOffered.push_back(C);
}
void Department::add_Faculty(Faculty* F) {
	facultyMembers.push_back(F);
}
void Department::setName(string a) {
	name = a;
}
void Department::setHead(string a) {
	headOfDept = a;
}
string Department::getName()const {
	return name;
}
string Department::getHead() const {
	return headOfDept;
}
int Department::getID()const {
	return departmentID;
}
void Department::setID(int a) {
	departmentID = a;
}
void Department::setCourses(vector<Courses*> a) {
	coursesOffered = a;
}
void Department::setFaculty(vector<Faculty*> a) {
	facultyMembers = a;
}
void Department::display(vector<Department> S) {
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << "ID" << right << setw(7) << "Name" << right << setw(20) << "  HOD" << endl;
	cout << "---------------------------------------" << endl;
	for (int i = 0; i < S.size(); i++) {
		cout << left << setw(5) << S[i].getID() << left << setw(22) << S[i].getName() << left << setw(30) << S[i].getHead() << endl;
	}
	cout << "---------------------------------------" << endl;
	cout << endl;
}
vector<Courses*> Department::getCourses() {
	return coursesOffered;
}
vector<Faculty*> Department::getFaculties() {
	return facultyMembers;
}
void Department::addCourse(Courses* a ) {
	coursesOffered.push_back(a);
}
void Department::addFaculty(Faculty* a ) {
	facultyMembers.push_back(a);
}