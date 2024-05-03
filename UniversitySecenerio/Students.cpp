#include"Students.h"
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

Students::Students() {
	studentID = 0;
}
Students::Students(int a, string b, string c, string d): Persons(b, c, d) {
	studentID = a;
}

//Currently had
void Students::current_courses(vector<string> a) {
	enrolledCourses = a;
}
void Students::current_Assignments(vector<Assignments*> assign) {
	submittedAssignments = assign;
}
void Students::current_Joined_Club(vector<Club*> clubs) {
	joinedClub = clubs;
}
void Students::current_resources(vector<LiberaryResource*> resource) {
	resources = resource;
}

//Addition to the current
void Students::submit_Assignment(Assignments* ASS) {
	submittedAssignments.push_back(ASS);
}
void Students::join_Club(Club* CL) {
	joinedClub.push_back(CL);
}
void Students::enroll_In_Courses(string CRS) {
	enrolledCourses.push_back(CRS);
}
void Students::add_resources(LiberaryResource* LR) {
	resources.push_back(LR);
}

//Setters
int Students::getID()const {
	return studentID;
}
void Students::setID(int a) {
	studentID = a;
}
void Students::setName(string a) {
	name = (a);
}
void Students::setEmail(string a) {
	email = a;
}
void Students::setPhoneNumber(string a) {
	phoneNumber = (a);
}

//Getters
string Students::getName()const {
	return name;
}
string Students::getEmail()const {
	return email;
}
string Students::getPhone()const {
	return phoneNumber;
}
vector<string> Students::getAllCourseIDs() {
	return enrolledCourses;
}

void Students::Now_Copy_Data_To_File() const {
	ReadWrite RW;

	RW.addStudentToFile(getName(), getID(), getName(), getEmail(), getPhone(),
		enrolledCourses, joinedClub, submittedAssignments, resources);
}

//Will display all the courses enrolled by students
void Students::displayCoursesFromFile(string nam) {
	ReadWrite RW; vector<string> C;
	C = RW.getCoursesOfStudent(nam);
	cout << C[0] << endl;

	vector<Courses*> courses;
	courses = RW.get_Courses_From_File("Courses");
	vector<Courses*> abc;

	for (int i = 0; i < C.size(); i++) {
		for (int j = 0; j < courses.size(); j++) {
			if (courses[j]->getName() == C[i]) {
				abc.push_back(courses[j]);
				break;
			}
		}
	}

	abc[0]->displayOnScreenAllCourses(abc);
}
vector<Club*> Students::getClubJoinedFromFile(string nam) {
	vector<Club*> clubs;
	ReadWrite RW;
	clubs = RW.getClubOfStudent(nam);

	for (int i = 0; i < clubs.size(); i++) {
		cout << "Club : " << i + 1 << endl;
		cout << "Club Name: " << clubs[i]->getName() << endl;
		cout << "Club ID: " << clubs[i]->getClubID() << endl;
		cout << "Club Description: " << clubs[i]->getDesc() << endl;
		cout << endl;
		cout << "----------------------------" << endl;
	}

	return clubs;
}
vector<LiberaryResource*> Students::getResources() {
	return resources;
}
void Students::displayStudents(vector<Students> S, vector<Students*> St )const{
	if (!S.empty()) {
		cout << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "ID" << right << setw(7) << "Name" << right << setw(18) << "Email" << right << setw(20)<< "Phone" << endl;
		cout << "----------------------------------------------------" << endl;
		for (int i = 0; i < S.size(); i++) {
			cout << left << setw(5) << S[i].getID() << left << setw(17) << S[i].getName() << left << setw(25) << S[i].getEmail() << S[i].getPhone() << endl;
		}
		cout << "----------------------------------------------------" << endl;
		cout << endl;
	}
	else {
		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "ID" << right << setw(7) << "Name" << right << setw(20) << "Phone" << endl;
		cout << "-------------------------------" << endl;
		for (int i = 0; i < St.size(); i++) {
			cout << left << setw(5) << St[i]->getID() << left << setw(17) << St[i]->getName() << St[i]->getPhone() << endl;
		}
		cout << "-------------------------------" << endl;
		cout << endl;
	}
}
int Students::validating_Student_ID(vector<Students> S) {
	int id = 0; bool check = false;
	do {
		check = false;
		cout << "Enter StudentID  : ";
		cin >> id;
		for (int i = 0; i < S.size(); i++) {
			if (S[i].getID() == id) {
				check = true;
			}
		}
		if (!check)
			cout << "Invalid ID Entered!!" << endl;
	} while (!check);

	return id;
}