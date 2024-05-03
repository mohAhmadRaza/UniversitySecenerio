#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"Faculty.h"
#include"Courses.h"
using namespace std;

class Courses;
class Faculty;

class FacultyCourseAllocation {
    int allocationID;
	int facultyID;;
	int courseID;
	string semester;
	Faculty* faculty;
	Courses* course;
public:
	FacultyCourseAllocation();
	FacultyCourseAllocation(int a, int b, int c, string str);
	void setCourse_Faculty(Courses* C, Faculty* F);
	string getSemester()const;
	int getID()const;
};