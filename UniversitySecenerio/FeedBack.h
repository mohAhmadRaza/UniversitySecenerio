#pragma once

#include<iostream>
#include<string>
#include"Persons.h"
#include"Students.h"
#include"Courses.h"
using namespace std;

class Students; class Courses; class FeedBack;

//ostream& operator << (ostream&, const FeedBack&);

class FeedBack {
	int feedBackID;
	string content;
	float rating;
	int studentID;
	int courseID;
	Students* student;
	Courses* course;
	float checkRating(float);
public:
	FeedBack();
	FeedBack(int d, int e, int b, float a, string c);
	void setStudent(Students* S);
	void setCourse(Courses* C);
	string getContent()const;
	int getRating()const;
	int getSID()const;
	int getCID()const;
	int getFID()const;
	void setRatings(float a);
	void setFID(int a);
	void setSID(int a);
	void setContent(string c);
	void setCID(int a);
	void display(vector<FeedBack>,int);
	void displays(vector<FeedBack> F);
};

//ostream& operator<<(ostream& cout, FeedBack& S) {
//	cout << "ID         : " << S.getFID() << endl;
//	cout << "Comment    : " << S.getContent() << endl;
//	cout << "Ratings    : " << S.getRating() << endl;
//	cout << "Student ID : " << S.getCID() << endl;
//	cout << "Course ID  : " << S.getCID() << endl;
//	return cout;
//}