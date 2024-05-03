#pragma once 

#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"Students.h"
using namespace std;

class Students; class Attendence;
//ostream& operator << (ostream&, const Attendence&);

class Attendence {
	int attendenceID;
	int studentID;
	int sessionID;
	vector<char> status;
	Students* student;
	char checkStatus(char);
public:
	Attendence();
	Attendence(int a, int b, int c);

	//Setters
	void setStatus(char a);
	void setStatus(vector<char> a);
	void currentStatus(vector<char> a);
	void setStudent(Students* S);
	void setSessionID(int a);
	void setAttID(int a);
	void setStudentID(int a);

	//Getters
	vector<char> getStatus()const;
	int getStuID()const;
	int getSessID()const;
	int getAttenID() const;
	string getStuName();

	//Uttilities Function
	int totalAbsents();
	int totalPresents();

	//friend ostream& operator<<(ostream&, const Attendence&);
};

//ostream& operator<<(ostream& cout, Attendence& S) {
//	cout << "Attendene ID : " << S.getAttenID() << endl;
//	cout << "Student ID   : " << S.getStuID() << endl;
//	cout << "Student Name : " << S.getStuName() << endl;
//	cout << "Session ID   : " << S.getSessID() << endl;
//	cout << "--------------------" << endl;
//	cout << "Total Presents : " << S.totalPresents() << endl;
//	cout << "Total Absents  : " << S.totalAbsents() << endl;
//	cout << "--------------------" << endl;
//	return cout;
//}