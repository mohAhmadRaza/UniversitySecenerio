#include<iostream>
#include<string>
#include<vector>
#include"Courses.h"
#include"Assignments.h"
#include<iomanip>
using namespace std;

Assignments::Assignments() {
    assignmentID = 0;
    courseID = 0;
    date = "";
    description = "";
}
Assignments::Assignments(int d, int a, string b, string c) {
    assignmentID = d;
    courseID = a;
    date = b;
    description = c;
}
void Assignments::setID(int a) {
    assignmentID = a;
}
void Assignments::setCourseID(int a) {
    courseID = a;
}
void Assignments::setDate(string a) {
    date = a;
}
void Assignments::setDescription(string a) {
    description = a;
}
int Assignments::getID()const {
    return assignmentID;
}
int Assignments::getCourseID()const {
    return courseID;
}
string Assignments::getDate()const {
    return date;
}
string Assignments::getDesc()const {
    return description;
}
void Assignments::submittedAssignments(vector<Assignments> sub) {
    cout << "Total Assignments : " << sub.size() << endl;
    for (int i = 0; i < sub.size(); i++) {
        cout << "ID : " << sub[i].getID() << endl;
        cout << "Course ID : " << sub[i].getCourseID() << endl;
        cout << "Description : " << sub[i].getDesc() << endl;
        cout << "Date : " << sub[i].getDate() << endl;
        cout << "--------------------------" << endl;
    }
}
void Assignments::display(vector<Assignments*>A) {
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "ID" << right << setw(7) << "Name" << right << setw(30) << "CourseID" << right << setw(17) << "Date" << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < A.size(); i++) {
        cout << left << setw(5) << A[i]->getID() << left << setw(30) << A[i]->getDesc() << left << setw(14) << A[i]->getCourseID() << A[i]->getDate() << endl;
    }
    cout << "----------------------------------------------------" << endl;
}