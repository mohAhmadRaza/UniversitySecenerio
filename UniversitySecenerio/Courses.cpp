#include"Courses.h"
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

Courses::Courses() {
	courseID = 0;
	name = "";
	creditHours = 0;
	instructor = "";
}
Courses::Courses(int d, string a, int b, string c) {
	name = a;
	creditHours = b;
	courseID = d;
	instructor = checkName(c);
};

void Courses::totalStudents(vector<Students*> S) {
	enrolled_students = S;
}
void Courses::setTotalAssignments(vector<Assignments> assign) {
	totalAssignments = assign;
}

void Courses::add_students(Students* ST) {
	enrolled_students.push_back(ST);
}
void Courses::add_Assignments(Assignments& AST) {
	totalAssignments.push_back(AST);
}

void Courses::setName(string a) {
	name = a;
}
void Courses::setInstructor(string a) {
	instructor = (a);
}
void Courses::setHours(int a) {
	creditHours = a;
}
void Courses::setID(int a) {
	courseID = a;
}

string Courses::getName() const {
	return name;
}
string Courses::getInstructor()const {
	return instructor;
}
int Courses::getHours()const {
	return creditHours;
}
int Courses::getID()const {
	return courseID;
}

//Inserting data into file
void Courses::Students_Enr_In_Each_Course() const {
	ReadWrite RW;
	RW.writing_Students_To_File(enrolled_students, getName());
}

//Getting data from the file
vector<Students> Courses::get_STU_from_file() {
	ReadWrite RW;
	vector<Students> S;
	S = RW.get_Students_From_File(getName());

	cout << "Total Students are : " << S.size();
	for (int i = 0; i < S.size(); i++) {
		cout << "Student's Name   : " << S[i].getName() << endl;
		cout << "Student's Email  : " << S[i].getEmail() << endl;
		cout << "Student's ID     : " << S[i].getID() << endl;
		cout << "Student's Phone  : " << S[i].getPhone() << endl;
		cout << "__________________________" << endl;
	}
	return S;
}

vector<Assignments*> Courses::get_ASSIGNS_from_file() const {
	ReadWrite RW;
	vector<Assignments*> S;
	S = RW.get_Assignments_From_STUfile(getName());

	cout << "Total Assignments are : " << S.size();
	for (int i = 0; i < S.size(); i++) {
		cout << "ID          : " << S[i]->getID() << endl;
		cout << "Course ID   : " << S[i]->getCourseID() << endl;
		cout << "Description : " << S[i]->getDesc() << endl;
		cout << "Date        : " << S[i]->getDate() << endl;
		cout << endl;
		cout << "__________________________" << endl;
	}
	return S;
}

void Courses::displayOnScreenAllCourses(vector<Courses*> S) {
	cout << "----------------------------------------------------" << endl;
	cout << "ID" << right << setw(7) << "Name" << right << setw(24) << "CreditHours" << right << setw(17) << "instructor" << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < S.size(); i++) {
		cout << left << setw(5) << S[i]->getID() << left << setw(22) << S[i]->getName() << left << setw(13) << S[i]->getHours() << S[i]->getInstructor() << endl;
	}
	cout << "----------------------------------------------------" << endl;
}

string Courses::checkName(string nam) {
	bool check = true;
	do {
		check = true;
		for (int i = 0; i < nam.length(); i++) {
			if (!isalpha(nam[i])) {
				check = false;
				break;  // Exit the loop if a non-alphabetic character is found
			}
		}
		if (!check) {
			cout << "Can You Please Enter Again: ";
			cin >> nam;
		}
	} while (!check);  // Continue looping until a valid input is obtained
	return nam;  // Return the valid input
}

string Courses::validate_Course_Name(vector<Courses*> C) {
	bool again = false; string name = "";

	do {
		again = false;
		cout << endl;
		cout << "Enter The Course Name : ";
		cin >> name;
		for (int i = 0; i < C.size(); i++) {
			if (C[i]->getName() == name) {
				again = true;
				break;
			}
		}
		if (again == false) {
			cout << "You Are not Allocated, " << name << endl;
			cout << "Please, Enter Course You Are Teaching!!" << endl;
		}
	} while (again == false);

	return name;
}