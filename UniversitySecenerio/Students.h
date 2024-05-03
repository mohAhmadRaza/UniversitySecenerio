#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"ReadWritingInFile.h"
#include"Courses.h"
#include"Assignments.h"
#include"Club.h"
using namespace std;

class ReadWrite;
class Students;
class Courses;
class Assignments;
class Club;
class LiberaryResource;


class Students :public Persons {
	int studentID;
	vector<string> enrolledCourses;
	vector<Assignments*> submittedAssignments;
	vector<Club*> joinedClub;
	vector<LiberaryResource*> resources;
public:
	Students();
	Students(int a, string b, string c, string d);

	//Currently had
	void current_courses(vector<string> a);
	void current_Assignments(vector<Assignments*> assign);
	void current_Joined_Club(vector<Club*> clubs);
	void current_resources(vector<LiberaryResource*> resource);

	//Addition to the current
	void submit_Assignment(Assignments* ASS);
	void join_Club(Club* CL);
	void enroll_In_Courses(string CRS);
	void add_resources(LiberaryResource* LR);

	//Setters
	int getID()const;
	void setID(int a);
	void setName(string a);
	void setEmail(string a);
	void setPhoneNumber(string a);

	//Getters
	string getName()const;
	string getEmail()const;
	string getPhone()const;
	vector<string> getAllCourseIDs();

	void Now_Copy_Data_To_File() const;

	//Will display all the courses enrolled by students
	void displayCoursesFromFile(string nam);

	//Will display all the clubs joined by the student
	vector<Club*> getClubJoinedFromFile(string nam);
	//friend ostream& operator<<(ostream&, const Students&);
	vector<LiberaryResource*> getResources();
	void displayStudents(vector<Students> S = {}, vector<Students*> St = {})const;
	int validating_Student_ID(vector<Students>);
};