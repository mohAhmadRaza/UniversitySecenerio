#include<iostream>
#include<string>
#include<vector>
#include "Enrollment.h"
using namespace std;


Enrollment::Enrollment() {
	enrollmentID++;
	studentID = 0;
	courseID = 0;
	enrollementDate = "";
}
Enrollment::Enrollment(string c, Students* S, Courses* C) {
	enrollmentID++;
	student = S;
	course = C;
	studentID = student->getID();
	courseID = course->getID();
	enrollementDate = c;
}
void Enrollment::setStuID() {
	studentID = student->getID();
}
void Enrollment::Enrollment::setCourseID() {
	courseID = course->getID();
}
void Enrollment::setDate(string a) {
	enrollementDate = a;
}
int Enrollment::getStuID()const {
	return studentID;
}
int Enrollment::getCourseID()const {
	return courseID;
}
string Enrollment::getDate()const {
	return enrollementDate;
}
void Enrollment::setStudent(Students* S) {
	student = S;
}
void Enrollment::setCourse(Courses* C) {
	course = C;
}
Students& Enrollment::getStu()const {
	return *student;
}
Courses& Enrollment::getCourse() const {
	return *course;
}

