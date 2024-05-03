#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Courses.h"
using namespace std;

class Assignments {
    int assignmentID;
    int courseID;
    string date;
    string description;
public:
    Assignments();
    Assignments(int d, int a, string b, string c);
    void setID(int a);
    void setCourseID(int a);
    void setDate(string a);
    void setDescription(string a);
    int getID()const;
    int getCourseID()const;
    string getDate()const;
    string getDesc()const;

    void submittedAssignments(vector<Assignments> sub);
    void display(vector<Assignments*>);
};
