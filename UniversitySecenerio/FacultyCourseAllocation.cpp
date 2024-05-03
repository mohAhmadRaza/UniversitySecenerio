#include<iostream>
#include<string>
#include<vector>
#include"FacultyCourseAllocation.h"
#include"Persons.h"
#include"Faculty.h"
#include"Courses.h"
using namespace std;

class Courses;
class Faculty;

FacultyCourseAllocation::FacultyCourseAllocation() {
	allocationID = 0;
	facultyID = 0;
	courseID = 0;
	semester = "";
}
FacultyCourseAllocation::FacultyCourseAllocation(int a, int b, int c, string str) {
	allocationID = a;
	facultyID = b;
	courseID = c;
	semester = str;
}
void FacultyCourseAllocation::setCourse_Faculty(Courses* C, Faculty* F) {
	course = C;
	faculty = F;
}
string FacultyCourseAllocation::getSemester()const {
	return semester;
}
int FacultyCourseAllocation::getID()const {
	return allocationID;
}