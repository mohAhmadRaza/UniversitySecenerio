#include"Attendence.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

Attendence::Attendence() {
	attendenceID = 0;
	studentID = 0;
	sessionID = 0;
}
Attendence::Attendence(int a, int b,int c){
	attendenceID = a;
	studentID = c;
	sessionID = b;
}

void Attendence::setStatus(vector<char> a) {
	status = a;
}
void Attendence::setStatus(char a) {
	status.push_back(checkStatus(a));
}
void Attendence::currentStatus(vector<char> a) {
	status = a;
}
void Attendence::setStudent(Students* S) {
	student = S;
}
void Attendence::setSessionID(int a) {
	sessionID = a;
}
void Attendence::setAttID(int a) {
	attendenceID = a;
}
void Attendence::setStudentID(int a) {
	studentID = a;
}

//Getters
vector<char> Attendence::getStatus()const {
	return status;
}
int Attendence::getStuID()const {
	return studentID;
}
int Attendence::getSessID()const {
	return sessionID;
}
int Attendence::getAttenID() const {
	return attendenceID;
}
string Attendence::getStuName() {
	return student->getName();
}


//Utility function
int Attendence::totalAbsents() {
	int count = 0;
	for (int i = 0; i < status.size(); i++) {
		if (status[i] == 'A') {
			count++;
		}
	}
	return count;
}
int Attendence::totalPresents() {
	int count = 0;
	for (int i = 0; i < status.size(); i++) {
		if (status[i] == 'P') {
			count++;
		}
	}
	return count;
}

char Attendence::checkStatus(char g) {
	bool check = true;
	do {
		check = true;
		if (!isalpha(g) || (g != 'A' && g != 'P')) {
			check = false;
		}
		if (check == false) {
			cout << "Can You Please Enter Again: ";
			cin >> g;
		}
	} while (check == false);
	return g;
}

