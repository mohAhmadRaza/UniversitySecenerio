#include<iostream>
#include<string>
#include<vector>
#include"Grade.h"
#include"Persons.h"
#include"Students.h"
#include"Courses.h"
using namespace std;



Grade::Grade() {
	gradeID++;
	studentID = 0, courseID = 0;
}
Grade::Grade(int c, int a, int b, char g) {
	gradeID = c;
	studentID = a;
	courseID = b;
	grade = g;
}
int Grade::getGradeID()const {
	return gradeID;
}
char Grade::getGrade()const {
	return grade;
}
void Grade::setGrade(char g) {
	grade = checkgrade(g);
}
void Grade::setSId(int g) {
	studentID = g;
}
void Grade::setCId(int g) {
	courseID = g;
}
void Grade::setGradeID(int g) {
	gradeID = g;
}

void Grade::setStudent_Course(Courses* C, Students* S) {
	student = S;
	course = C;
	studentID = student->getID();
	courseID = course->getID();
}
int Grade::getStuID()const {
	return studentID;
}
int Grade::getCourseID()const {
	return courseID;
}

char Grade::checkgrade(char g) {
	bool check = true;
	do {
		check = true;
		if (!isalpha(g) || (g != 'A' && g != 'B' && g != 'C' && g != 'D' && g != 'F')) {
			check = false;
		}
		if (check == false) {
			cout << "Can You Please Enter Again: ";
			cin >> g;
		}
	} while (check == false);
	return g;
}
int Grade::validateGradeID(vector<Grade> G) {
	bool again = false; int id = 0;

	do {
		again = true;
		cout << endl;
		cout << "Enter GradeID   : ";
		cin >> id;
		for (int i = 0; i < G.size(); i++) {
			if (G[i].getGradeID() == id) {
				again = false;
				break;
			}
		}
		if (again == false) {
			cout << "GradeID is already Allocated!!" << endl;
		}
	} while (again == false);

	return id;
}