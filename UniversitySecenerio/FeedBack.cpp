#include<iostream>
#include<string>
#include"FeedBack.h"
#include"Persons.h"
#include"Students.h"
#include"Courses.h"
#include<iomanip>
using namespace std;

class Students; class Courses; class FeedBack;

FeedBack::FeedBack() {
	feedBackID = 0;
	content = "";
	rating = 0.0;
}
FeedBack::FeedBack(int d, int e, int b, float a, string c) {
	feedBackID = b;
	rating = a;
	content = c;
	studentID = d;
	courseID = e;
}
void FeedBack::setStudent(Students* S) {
	student = S;
}
void FeedBack::setCourse(Courses* C) {
	course = C;
}
string FeedBack::getContent()const {
	return content;
}
int FeedBack::getRating()const {
	return rating;
}
int FeedBack::getSID() const{
	return studentID;
}
int FeedBack::getCID() const{
	return courseID;
}
int FeedBack::getFID()const {
	return feedBackID;
}
void FeedBack::setRatings(float a) {
	rating = a;
}
void FeedBack::setFID(int a) {
	feedBackID = a;
}
void FeedBack::setSID(int a) {
	studentID = a;
}
void FeedBack::setContent(string c) {
	content = c;
}
void FeedBack::setCID(int a) {
	courseID = a;
}

float FeedBack::checkRating(float f) {
	bool check = true;
	do {
		check = true;
		if (f < 0.0 || f>5.0) {
			check = false;
		}
		if (check == false) {
			cout << "Please enter in range [0.0 - 5.0]" << endl;
			cin >> f;
		}
	} while (check == false);
	return f;
}

void FeedBack::display(vector<FeedBack> F,int id) {
	cout << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < F.size(); i++) {
		if (F[i].getFID()==id) {
			cout << "FeedBackID : " << F[i].getFID() << endl;
			cout << "CourseID   : " << F[i].getCID() << endl;
			cout << "StudentID  : " << F[i].getSID() << endl;
			cout << "FeedBack   : " << F[i].getContent() << endl;
			cout << "Rating     : " << F[i].getRating() << endl;
		}
	}
	cout << "---------------------------------" << endl;
}
void FeedBack::displays(vector<FeedBack> F) {
	cout << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < F.size(); i++) {
			cout << "FeedBackID : " << F[i].getFID() << endl;
			cout << "CourseID   : " << F[i].getCID() << endl;
			cout << "StudentID  : " << F[i].getSID() << endl;
			cout << "FeedBack   : " << F[i].getContent() << endl;
			cout << "Rating     : " << F[i].getRating() << endl;
			cout << "--------------------" << endl;
	}
	cout << "---------------------------------" << endl;
}