#pragma once 

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"Project.h"
#include"FeedBack.h"
#include"Events.h"
#include"Attendence.h"
#include"FacultyCourseAllocation.h"
#include"Enrollment.h"
#include"Club.h"
#include"Persons.h"
#include"Students.h"
#include"Faculty.h"
#include"Assignments.h"
#include"Courses.h"
#include"Grade.h"
#include"Department.h"
#include"LiberaryResource.h"
#include"Persons.h"
using namespace std;

class Courses;
class Students;
class Grade;
class FeedBack;
class Attendence;
class Club;
class Projects;

class ReadWrite { 
public:
	ReadWrite() {};

	//Wrting
	void writing_Courses_To_File(const vector<Courses*> C, string file);
	void writing_Students_To_File(const vector<Students*> C, string file);
	void addStudentToFile(string file, int a, string b, string c, string d,const vector<string> C, const vector<Club*>club, const vector<Assignments*>Assign, const vector<LiberaryResource*> LR);
	void addAssignmentsOfCourse(const vector<Assignments*> Assign, string file);
	void writeAllClubs(const vector<Club*> club, string file);
	void Write_FeedBacks(string file, const vector<FeedBack>& F);
	void writeAttendence(const vector<Attendence>, string);
	void write_Projects_To_File(const vector<Project>& projects, string file);
	void writeGrades(const vector<Grade>, string);
	void writeResources(const vector<LiberaryResource*> club, string file);
	void writeFaculty(const vector<Faculty> F, string file);
	void writeDepartments(vector<Department> D, string file);

	//Reading
	vector<Students*> get_Student_From_File(string file);
	vector<Students> get_Students_From_File(string file);
	vector<Courses*> get_Courses_From_File(string file);
	vector<string> getCoursesOfStudent(string file);
	vector<Club*> getClubOfStudent(string file);
	vector<LiberaryResource*> get_Reources_Of_Student(string file);
	vector<Assignments*> get_Assignments_From_STUfile(string file);
	vector<Grade> getGrades(string file);
	vector<FeedBack> getFeedBacks(string file);
	vector<Courses*> getCoursesTaught(string);
	vector<Faculty> getFaculty(string File);
	vector<Project> get_Projects_From_File(string file);
	vector<Attendence> getAttendence(string file);
	vector<Assignments*> getAllAssignments(string);
	vector<Department> getDepartments(string);
	Students getStudentData(string a);
};


