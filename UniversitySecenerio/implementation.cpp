#include<iostream>
#include<string>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include"Persons.h"
#include"Students.h"
#include"Faculty.h"
#include"FacultyCourseAllocation.h"
#include"Enrollment.h"
#include"Assignments.h"
#include"Attendence.h"
#include"Courses.h"
#include"Club.h"
#include"Events.h"
#include"Grade.h"
#include"Project.h"
#include"LiberaryResource.h"
#include"FeedBack.h"
#include"Department.h"
#include"ReadWritingInFile.h"
using namespace std;

int choicesValidations(int, int, int);
void admin();
void student();
void faculty();
char Toagain();

int main() {
	int status = 0; bool check = false; char again;

	do {
		check = false;
		cout << "Enter Your Status: " << endl;
		cout << "-----------------" << endl;
		cout << "[1] Admin" << endl;
		cout << "[2] Student" << endl;
		cout << "[3] Faculty" << endl;
		cout << "[4] Exit.." << endl;
		cin >> status;
		status = choicesValidations(status, 0, 3);

		if (status == 1) {
			cout << endl;
			cout << "You are an Admin!!" << endl;
			admin();
		}
		else if (status == 2) {
			cout << "You are a student!!" << endl;
			student();
		}
		else if(status == 3){
			cout << "You are a Faculty/ Staff member!!" << endl;
			faculty();
		}
		else if (status == 4) {
			cout << "Exiting!!" << endl;
		}
	} while (status != 4);
	return 0;
}

int choicesValidations(int choice, int from, int to) {
	bool check = true;
	do {
		check = true;
		if (choice<from || choice>to) {
			cout << "Entered choice is not availaible." << endl;
			cin >> choice;
			check = false;
		}
	} while (check = false);
	return choice;
}

void admin() {
	int choice = 0;
	ReadWrite RW;

	//Getting data from student, Faculty & Courses Files
	vector<Courses*> Course = RW.get_Courses_From_File("Courses");
	vector<Faculty> faculty = RW.getFaculty("Faculty");
	vector<Students*> Student = RW.get_Student_From_File("Students");
	vector<LiberaryResource*> resources = RW.get_Reources_Of_Student("LiberaryResources");
	vector<Club*> clubs = RW.getClubOfStudent("Club");

	//Getting data from Departments File
	vector<Department> departments = RW.getDepartments("Departments");

	//Displaying All Departments
	cout << endl;
	cout << "------------" << endl;
	cout << "Dear Admin!!" << endl;
	cout << "Here We Have Departments." << endl;
	cout << "------------" << endl;
	departments[0].display(departments);

	//Asking For Deaprtment From Admin And Validation
	int id = 0, index = 0; string name, hod = ""; bool again = false;
	do {
		again = false;
		cout << endl;
		cout << "Department Name : "; cin >> name;
		cout << "Department's ID : "; cin >> id;
		cout << "Departmen's HOD : "; cin >> hod;
		cout << endl;
		cout << "--------------------" << endl;
		for (int i = 0; i < departments.size(); i++) {
			if (departments[i].getID() == id && departments[i].getHead() == hod && departments[i].getName() == name) {
				cout << "You Want To Deal With " << departments[i].getName() << endl;
				again = true;
				index = i;
				break;
			}
		}
		if (!again)
			cout << "OOPs, Invalid Credentials Provided" << endl;
	} while (again == false);

	do {
		cout << endl;
		cout << "Select your choice from here" << endl;
		cout << "--------------------------" << endl;
		cout << "[1]  Add Course" << endl;
		cout << "[2]  Remove Course" << endl;
		cout << "[3]  Add Student" << endl;
		cout << "[4]  Remove Student" << endl;
		cout << "[5]  Add Faculty" << endl;
		cout << "[6]  Remove Faculty" << endl;
		cout << "[7]  Add Resources In Liberary" << endl;
		cout << "[8]  Remove Resources From Liberary" << endl;
		cout << "[9]  See Enrolled Courses" << endl;
		cout << "[10] See Registered Students" << endl;
		cout << "[11] See Registered Faculties" << endl;
		cout << "[12] Clubs For Students" << endl;
		cout << "[13] See All Projects" << endl;
		cout << "[14] Add Club" << endl;
		cout << "[15] Remove Club" << endl;
		cout << "[16] Check Graded And Non Graded Students" << endl;
		cout << "[17] Check Attendence Of Students" << endl;
		cout << "[18] FeedBack Of Faculties" << endl;
		cout << "[19] Exit.." << endl;
		cin >> choice;
		choice = choicesValidations(choice, 0, 19);
		cout << endl;
		if (choice == 1) {
			string str1 = "", str2 = ""; int inp1 = 0, inp2 = 0;
			bool check = false; vector<Students*> stu; string choise;

			//Taking Course Information
			do {
				check = false;
				cout << "Name       : ";
				cin >> str1;
				cout << "ID         : ";
				cin >> inp1;
				for (int i = 0; i < Course.size(); i++) {
					if (Course[i]->getName() == str1 || Course[i]->getID() == inp1) {
						check = true;
						cout << "Course Is Already Registered" << endl;
						cout << "----------------------------" << endl;
						break;
					}
				}
			} while (check == true);
			cout << "Hours      : ";
			cin >> inp2;
			cout << "Instructor : ";
			cin >> str2;

			//Making New Course Object
			Courses *C=new Courses(inp1, str1, inp2, str2);
			departments[index].add_Course(C);
			Course.push_back(C);
			cout << "-------------------------" << endl;

			//Now Enrolling Atleast Two Students
			//Firstly, Displaying Students
			Student[0]->displayStudents({}, Student);

			string st1 = "", st2 = "", st3 = ""; int in1 = 0, in2 = 0;
			cout << "Enter Two Student IDs To Enroll In Course : ";
			cin >> in1;
			cin >> in2;


			for (int i = 0; i < Student.size(); i++) {
				if (Student[i]->getID() == in1 ) {
					st1 = Student[i]->getName();
					st2 = Student[i]->getEmail();
					st3 = Student[i]->getPhone();
				}
				Students* S1 = new Students(in1, st1, st2, st3);
				stu.push_back(S1);
				if (Student[i]->getID() == in2) {
					st1 = Student[i]->getName();
					st2 = Student[i]->getEmail();
					st3 = Student[i]->getPhone();
				}
				Students* S2 = new Students(in1, st1, st2, st3);
				stu.push_back(S2);
			}
			if (stu.size() == 0)
				cout << "Invalid IDs" << endl;

			RW.writing_Students_To_File(stu, str1);
			cout << endl;
			cout << "Successfully Added " << C->getName() << " in " << departments[index].getName() << endl;
		}
		else if (choice == 2) {
			string str1 = "";bool check = false;

			vector<Courses*> C = departments[index].getCourses();

			//Taking Course Information
			do {
				check = false;
				cout << endl;
				cout << "Name  : ";
				cin >> str1;
				for (int i = 0; i < C.size(); i++) {
					if (C[i]->getName() == str1) {
						C.erase(C.begin() + i);
						cout << "Successfull Removed!!" << endl;
						check = true;
					}
				}
				if (!check) {
					cout << "No Course With Such Name Found!!" << endl;
					cout << endl;
				}
			} while (check == false);

			cout << endl;
			cout << "Now " << departments[index].getName() << " has " << C.size() << " Courses" << endl;
		}
		else if (choice == 3) {
			string st1, st2, st3; int inp = 0; 
			
			cout << endl;
			cout << "PLease, Enter Details " << endl;
			cout << "---------------" << endl;
			cout << "Name  : "; cin >> st1;
			cout << "ID    : "; cin >> inp;
			cout << "Email : "; cin >> st2;
			cout << "Phone : "; cin >> st3;
			cout << endl;
			Students* St = new Students(inp, st1, st2, st3);

			Student.push_back(St);
			cout << "Dear Admin, " << st1 << " is Added, Successfull" << endl;
		}
		else if (choice == 4) {
			string str1 = ""; bool check = false;

			//Taking Course Information
			do {
				check = false;
				cout << endl;
				cout << "Enter Name  : ";
				cin >> str1;
				for (int i = 0; i < Student.size(); i++) {
					if (Student[i]->getName() == str1) {
						Student.erase(Student.begin() + i);
						cout << "Successfull Removed!!" << endl;
						check = true;
					}
				}
				if (!check) {
					cout << "No Student With Such Name, Found!!" << endl;
					cout << endl;
				}
				cout << "----------------" << endl;
			} while (check == false);
		}
		else if (choice == 5) {
			string choise = ""; string st1, st2, st3; int inp = 0;
			vector<Faculty*> ff = departments[index].getFaculties();

			cout << endl;
			cout << "PLease, Enter Details " << endl;
			cout << "---------------" << endl;
			cout << "Name  : "; cin >> st1;
			cout << "ID    : "; cin >> inp;
			cout << "Email : "; cin >> st2;
			cout << "Phone : "; cin >> st3;
			Faculty f(inp, st1, st2, st3); Faculty* F = new Faculty(inp, st1, st2, st3);
			departments[index].add_Faculty(F);
			faculty.push_back(f);

			cout << endl;
			cout << "Now, " << endl;
			cout << "Total Faculties are : " << faculty.size() << endl;
			cout << "From which Faculties in " << departments[index].getName() << " are " << ff.size() + 1 << endl;
			cout << endl;
		}
		else if (choice == 6) {
			string str1 = ""; bool check = false; int ind = 0;

			//Taking Faculty Information
			do {
				check = false;
				cout << endl;
				cout << "Enter Name  :  ";
				cin >> str1;
				for (int i = 0; i < faculty.size(); i++) {
					if (faculty[i].getName() == str1) {
						faculty.erase(faculty.begin() + i);
						cout << "Successfull Removed!!" << endl;
						ind = 1;
						check = true;
					}
				}
				if (!check) {
					cout << "No Faculty With Such Name, Found!!" << endl;
					cout << endl;
				}
			} while (check == false);

			vector<Faculty*> ff = departments[index].getFaculties();
			ff.erase(ff.begin() + ind);

			cout << "Now, " << endl;
			cout << "Total Faculties are : " << faculty.size() << endl;
			cout << "From which Faculties in " << departments[index].getName() << " are " << ff.size()<< endl;
			cout << endl;
		}
		else if (choice == 7) {

			string st1, st2 = ""; int in1 = 0, in2 = 0;

			cout << "Enter Details" << endl;
			cout << "-------------" << endl;
			cout << "Name   : "; cin >> st1;
			cout << "ID     : "; cin >> in1;
			cout << "Author : "; cin >> st2;
			cout << "Avail  : "; cin >> in2;

			LiberaryResource* L = new LiberaryResource(in1, st1, st2, in2);
			resources.push_back(L);
			cout << "Added Successfully!!" << endl;
			cout << "Now the total resources : " << resources.size() << endl;
			cout << endl;
		}
		else if (choice == 8) {
			string str1 = ""; bool check = false;

			//Taking Resource Information
			do {
				check = false;
				cout << endl;
				cout << "Enter Name  :  ";
				cin >> str1;
				for (int i = 0; i < faculty.size(); i++) {
					if (resources[i]->getTitle() == str1) {
						resources.erase(resources.begin() + i);
						cout << "Successfull Removed!!" << endl;
						check = true;
					}
				}
				if (!check)
					cout << "No Resource With Such Name!!" << endl;
			} while (check == false);
			cout << "Now the total resources : " << resources.size() << endl;
			cout << endl;
		}
		else if (choice == 9) {
			vector<Courses*> C1 = departments[0].getCourses();
			vector<Courses*> C2 = departments[1].getCourses();
			cout << "Courses Offered From Department : " << departments[0].getName() << endl;
			cout << "-----------------------------" << endl;
			C1[0]->displayOnScreenAllCourses(C1);
			cout << endl;
			cout << "Courses Offered From Department : " << departments[1].getName() << endl;
			cout << "-----------------------------" << endl;
			C1[1]->displayOnScreenAllCourses(C2);
		}
		else if (choice == 10) {
			Student[0]->displayStudents({}, Student);
		}
		else if (choice == 11) {
			for (int i = 0; i < departments.size(); i++) {
				cout << "Department : " << departments[i].getName() << endl;
				vector<Faculty*> F1 = departments[i].getFaculties();
				F1[0]->display(F1);
			}
		}
		else if (choice == 12) {
			clubs[0]->display(clubs);
		}
		else if (choice == 14) {
			string choise = ""; string st1, st2, st3; int inp = 0;

			cout << "Club Details : " << endl;
			cout << "------------------" << endl;
			cout << "Name  : "; cin >> st1;
			cout << "ID    : "; cin >> inp;
			cout << "Desc. : "; cin >> st2;
			Club* f = new Club(inp, st1, st2);

			clubs.push_back(f);
			cout << "Now Total Clubs Are : " << clubs.size() << endl;
		}
		else if (choice == 13) {
			vector<Project> P = RW.get_Projects_From_File("Projects");
			P[0].displayProjectsAll(P);

			for (int i = 0; i < P.size(); i++) {
				cout << "For " << P[i].getTitle() << " Project" << endl;
				cout << endl;
				const Faculty* F = new Faculty;
				F = P[i].getFacultySupervising();
				cout << "Faculty Supervising"<< endl;
				cout << endl;
				cout << "---------------" << endl;
				cout << "Name  : " << F->getName() << endl;
				cout << "Email : " << F->getEmail() << endl;
				cout << "Phone : " << F->getPhone() << endl;
				cout << "---------------" << endl;
				cout << endl;

				cout << "Students Enrolled "<< endl;
				vector<Students*> S = P[i].getAllStudents();
				S[0]->displayStudents({}, S);
				cout << endl;
			}
			
		}
		else if (choice == 15) {
			string name; int id = 0; string ok = "";
			cout << endl;
			cout << "Warning!!" << endl;
			cout << "No Student Will Join Removed Club In Future!" << endl;
			cout << "And, Already Joined Students Will Be Thrown Out" << endl;
			cout << endl;
			cout << "Enter OK, if you agree!!" << endl;
			cout << "Enter cancel, if you not!!" << endl;
			cout << "------------------------" << endl;
			cin >> ok;
			if (ok == "OK") {
				cout << "Enter Details Of That Club!!" << endl;
				cout << "Name :  "; cin >> name;
				cout << "ID   :  "; cin >> id;
				for (int i = 0; i < clubs.size(); i++) {
					if (clubs[i]->getName() == name && clubs[i]->getClubID() == id) {
						clubs.erase(clubs.begin() + i);
						cout << "Now, No Student Will Enroll In " << name << endl;
						break;
					}
				}
			}
			else
				cout << "Regain Your Choice!" << endl;
			cout << endl;
		}
		else if (choice == 16) {
			int count1 = 0; vector<Students*> SS; bool aga = false;
			vector<Grade> G = RW.getGrades("Grades");

			cout << "Graded Students are : " << endl;
			cout << left<<setw(3) << "NO." << left<<setw(15) << "    Name" << left << setw(10) << "Grade" << left << setw(10) << "Course" << endl;
			cout << "----------------------------------------" << endl;
			for (int i = 0; i < Student.size(); i++) {
				aga = false;
				for (int j = 0; j < G.size(); j++) {
					if (G[j].getStuID() == Student[i]->getID()) {
						count1++;
						cout << left << setw(5)<<i + 1 <<left<< setw(15) << Student[i]->getName() << left << setw(10) << G[j].getGrade() << left << setw(10) << G[j].getCourseID() << endl;
						aga = true;
					}
				}
				if (!aga)
					SS.push_back(Student[i]);
			}

			cout << "----------------------------------------" << endl;
			cout << endl;
			cout << "Non-Graded Students!!" << endl;
			for (int i = 0; i < SS.size(); i++) {
				cout << left << setw(3) << "NO." << left << setw(15) << "    Name" << endl;
				cout << left << setw(3) << i + 1 << left << setw(5) << SS[i]->getName() << endl;
			}

			cout << endl;
			cout << "--------------------" << endl;
			cout << "Graded Student : " << count1 << endl;
			cout << "Non-Graded Are : " << SS.size() << endl;
			cout << "--------------------" << endl;
			cout << endl;

		}
		else if (choice == 18) {
			vector<FeedBack> FB = RW.getFeedBacks("FeedBacks");
			cout << "Displaying FeedBacks Of  Faculties" << endl;
			cout << FB.size() << endl;
			FB[0].displays(FB);
		}
		else if (choice == 17) {
			vector<Attendence> att = RW.getAttendence("Attendence");
			cout << "-----------------------------------" << endl;
			cout << "No." << "     Name      " << "  Absents  " << "  Presents  " << "   %  " << endl;
			cout << "-----------------------------------" << endl;
			for (int i = 0; i < att.size(); i++) {
				double c = (att[i].totalPresents() / 18.0);
				double a = c * 100;
				cout << left << setw(8) << i + 1 << left << setw(15) << Student[i]->getName() << left << setw(10) << att[i].totalAbsents() << left << setw(10) << att[i].totalPresents() <<a << "%" << endl;
			}
			cout << "-----------------------------------" << endl;
			cout << endl;
		}
		else if (choice == 19) {
			RW.writing_Students_To_File(Student, "students");
			RW.writeAllClubs(clubs, "clubs");
			RW.writeResources(resources, "LiberaryResources");
			RW.writeFaculty(faculty, "Faculty");
			RW.writing_Courses_To_File(Course, "Courses");
			RW.writeDepartments(departments, "Departments");
		}
	} while (choice != 19);
}

char Toagain() {
	char again;
	do {
		cout << "Want to do again!!" << endl;
		cin >> again;
		again = tolower(again);
	} while (!isalpha(again) || (again != 'y' && again != 'n'));

	return again;
}

void student() {

	//Declaring the variables
	int choice = 0; int id = 0; string str1 = "", str3 = "", str2 = ""; bool check = false;
	ReadWrite RW; vector<Students> s = RW.get_Students_From_File("Students");

	//Taking Information From The Current Student
	do {
		check = false;
		cout << "Name  :  ";
		cin >> str1;
		cout << "ID    :  ";
		cin >> id;
		cout << "Email :  ";
		cin >> str2;
		cout << "Phone :  ";
		cin >> str3;
		cout << "----------------------" << endl;
		for (int i = 0; i < s.size(); i++) {
			if (s[i].getID() == id && s[i].getName() == str1 && s[i].getEmail() == str2 && s[i].getPhone() == str3) {
				check = true;
				cout << str1 << " !! You Are Registered" << endl;
				break;
			}
		}
		if (check == false) {
			cout << "Any Of The Entered Cendentials Is Wrong!!" << endl;
			cout << endl;
		}
	} while (check == false);

	//Creating objects
	Students* S = new Students(id, str1, str2, str3);
	
	//Creating Furthur Objects
	Courses C;
	vector<string> enrolled;
	vector<Assignments*> submitted;
	vector<Club*> joined;
	vector<Courses*> courses = RW.get_Courses_From_File("Courses");
	vector<Grade> grades;
	vector<LiberaryResource*> LR;
	vector<Project> PR;
	vector<FeedBack> F;

	//Taking All The Data From File To Instances
	enrolled = RW.getCoursesOfStudent(S->getName());
	submitted = RW.get_Assignments_From_STUfile(S->getName());
	joined = RW.getClubOfStudent(S->getName());
	LR = RW.get_Reources_Of_Student(S->getName());
	PR = RW.get_Projects_From_File("Projects");

	//Now, Providing Menu To User And Validation
	do {
		cout << endl;
		cout << "----------------------" << endl;
		cout << "[1]  Enroll In New Course" << endl;
		cout << "[2]  All the availaible courses" << endl;
		cout << "[3]  Enrolled Courses" << endl;
		cout << "[4]  Submit New Assignment" << endl;
		cout << "[5]  Submitted Assignments" << endl;
		cout << "[6]  Your Grade" << endl;
		cout << "[7]  Join New Club" << endl;
		cout << "[8]  Joined Clubs" << endl;
		cout << "[9]  Left Any joined club" << endl;
		cout << "[10] Your Liberary Resources" << endl;
		cout << "[11] Add New Liberary Resource" << endl;
		cout << "[12] Give FeedBack" << endl;
		cout << "[13] Enroll In Projects" << endl;
		cout << "[14] View Attendence" << endl;
		cout << "[15] Exit.." << endl;
		cout << "---------------------" << endl;
		cin >> choice;
		choice = choicesValidations(choice, 0, 15);

		if (choice == 1) {

			//Declaration Of Variables
			string str1, str2, str3; int id = 0; bool again = false;

			//Getting All The Courses From File
			C.displayOnScreenAllCourses(courses);

			//Taking Input From User
			str1 = C.validate_Course_Name(courses);

			//Taking All Students Enrolled
			vector<Students*> inthis = RW.get_Student_From_File(str1);

			//PushingBack
			inthis.push_back(S);

			//Coping Data
			RW.writing_Students_To_File(inthis, str1);
			
			//Adding The Name Of The Course To The Student Courses
			enrolled.push_back(str1);
			cout << "You have Successfully Enrolled In " << str1 << endl;
		}

		else if (choice == 2) {

			//Getting All The Courses From File
			courses = RW.get_Courses_From_File("Courses");

			//Displaying the Courses Names
			C.displayOnScreenAllCourses(courses);
		}

		else if (choice == 3) {
			//Displaying All The Courses, User Enrolled
			S->displayCoursesFromFile(S->getName());
		}

		else if (choice == 4) {

			vector<Assignments*> ASSI = RW.getAllAssignments("Assignments");
			ASSI[0]->display(ASSI);
			//Declaration
			string str1, str2; int id = 0, id2 = 0;

			//Demanding Data From The User
			cout << "Enter Assignment ID : ";
			cin >> id;
			for (int i = 0; i < ASSI.size(); i++) {
				if (ASSI[i]->getID() == id) {
					id2=ASSI[i]->getCourseID();
					str1 = ASSI[i]->getDesc();
					str2 = ASSI[i]->getDate();
				}
			}
			
			//Creating An Instance Of Assignments On Heap 
			Assignments *A = new Assignments(id, id2, str1, str2);

			//Adding That Assignment To Submitted Assignments
			submitted.push_back(A);

			cout << S->getName()<<"!! Your Assignment Has Been Submitted" << endl;
		}

		else if (choice == 5) {
			cout << "Total Assignments : " << submitted.size() << endl;
			submitted[0]->display(submitted);
		}

		else if (choice == 6) {

			//Taking Data From File Of Grades
			grades = RW.getGrades("Grades"); bool again = false;

			//Displaying Grades To User
			cout << S->getName() << " Your Details" << endl;
			for (int i = 0; i < grades.size(); i++) {
                //Checking If Grades Are Of Particular Student Or Not
				if (grades[i].getStuID() == S->getID()) {
					cout << "----------------" << endl;
					cout << "Grade ID   : " << grades[i].getGradeID() << endl;
					cout << "Student ID : " << grades[i].getStuID() << endl;
					cout << "CourseID   : " << grades[i].getCourseID() << endl;
					cout << "Grade      : " << grades[i].getGrade() << endl;
					cout << "----------------" << endl;
					again = true;
				}
			}
			if (!again)
				cout << "OOPs!! " << S->getName() << ", You Have No Grade Uploaded Yet.." << endl;
		}

		else if (choice == 7) {

			//Declarattions
			vector<Club*> clubs; int input = 0; string nam, desc;

			//Taking Data From File, Storing In vector
			clubs = RW.getClubOfStudent("Club");

			//Displaying Clubs Data to user
			cout << "Currently, we have " << clubs.size() << " clubs" << endl;
			clubs[0]->display(clubs);
			cout << endl;

			//Taking input of ID
			cout << "Enter ID of Club, To Join : ";
			cin >> input;

			//Checking  if the ID matches than storing respective result
			for (int i = 0; i < clubs.size(); i++) {
				if (clubs[i]->getClubID() == input) {
					nam = clubs[i]->getName();
					desc = clubs[i]->getDesc();
				}
			}

			//Creating a new object of club
			Club* C = new Club(input, nam, desc);

			//Pushing that object to the vector
			joined.push_back(C);
			cout << joined.size() << endl;

			cout << "You Have Successfully Joined " << nam << endl;
			cout << endl;
		}

		else if (choice == 8) {
			cout << "Currently, you joined " << joined.size() << " clubs" << endl;
			joined[0]->display(joined);
		}

		else if (choice == 9) {
			int input = 0; bool check = false;

			//Displaying Joined Clubs
			cout << "Currently, you have joined " << joined.size() << " clubs" << endl;
			joined[0]->display(joined);

			//Checking If The Entered Club ID, Exists Or Not
			do {
				check = false;
				cout << "Enter Correct ID Of Club, You Want To Left : ";
				cin >> input;
				for (int i = 0; i < joined.size(); i++) {
					if (joined[i]->getClubID() == input) {
						//Finding And Then Erasing Club
						joined.erase(joined.begin() + i);
						check = true;
						break;
					}
				}
			} while (check == false);

			cout << "You Successfully Left club" << endl;
		}

		else if (choice == 10) {
			cout << endl;
			cout << "ID" << right << setw(13) << "Title" << right << setw(25) << "Author" << endl;
			cout << "----------------------------------" << endl;
			for (int i = 0; i < LR.size(); i++) {
				if (LR[i]->getAvail() == 1) {
					cout << left << setw(10) << LR[i]->getRID() << left << setw(25) << LR[i]->getTitle() << left << setw(20) << LR[i]->getAuthor() << endl;
				}
			}
			cout << "----------------------------------" << endl;
		}

		else if (choice == 11) {

			//Declarations
			vector<LiberaryResource*> Lib; int input = 0, input2 = 0; string str1, str2;
			Lib = RW.get_Reources_Of_Student("LiberaryResources");

			//Displaying All The Availaible Resources
			cout << endl;
			cout << "Total Resources Are " << Lib.size()<< endl;
			cout << "But We Are Displaying Only Availaible Resources" << endl;
			cout << "--------------------------------------------" << endl;
			cout <<"ID" <<right<<setw(13) << "Title" << right<<setw(26) << "Author" << endl;
			cout << "--------------------------------------------" << endl;

			for (int i = 0; i < Lib.size(); i++) {
				if (Lib[i]->getAvail() == 1) {
					cout <<left<<setw(10)<<Lib[i]->getRID() << left << setw(25) << Lib[i]->getTitle() << left << setw(20) << Lib[i]->getAuthor() << endl;
				}
			}
			cout << "--------------------------------------------" << endl;
			cout << endl;

			//Taking User's Choice
			cout << "Enter ResourceID To Issue : ";
			cin >> input;
			
			//Getting Data Based On User's Choice
			for (int i = 0; i < Lib.size(); i++) {
				if (Lib[i]->getRID() == input) {
					input2 = Lib[i]->getAvail();
					str1 = Lib[i]->getTitle();
					str2 = Lib[i]->getAuthor();
					break;
				}
			}

			//Creating A New Object Based On Information
			LiberaryResource* L = new LiberaryResource(input, str1, str2, input2);

			//Adding This To Issued Resources
			LR.push_back(L);
			cout << "Successfully Issued!!" << endl;
		}

		else if (choice == 12) {

			//Declarations
			int input1 = 0, input3 = 0; float input2 = 0; 
			string str = "";

			//getting FeedBacks From The File
			F = RW.getFeedBacks("FeedBacks");
			cout << F.size() << endl;

			//Getting Data For Next FeedBack
			cout << "FeedBackID : ";
			cin >> input1;
			cout << "Comment    : ";
			cin >> str1;
			cout << "Ratings    : ";
			cin >> input2;
			cout << "Course ID  : ";
			cin >> input3;

			//Craeting An Object Based On Above Information
			FeedBack F1(id, input3, input1, input2, str1);
			F1.setStudent(S);

			//Adding To The Previous FeedBacks
			F.push_back(F1);

			//Finishing Remarks
			cout << "Thanks For the FeedBack, " << S->getName() << "!" << endl;
		}

		else if (choice == 13) {

			//Declarations
			int input = 0;

			//Displaying All Projects
			Project P;
			P.displayProjectsAll(PR);
			
			//Taking Input From User
			cout << "Enter Project ID, You Want To Enroll : ";
			cin >> input;

			//Matching With The Project, And Then Enrolling In Project
			for (int i = 0; i < PR.size(); i++) {
				if (PR[i].getPID() == input) {
					PR[i].addStudentsForProjects(S);
				}
			}

			//Finishing Statement
			cout << "YouHave Successfully, Enrolled!!" << endl;
			cout << "----------------------" << endl;
		}

		else if (choice == 14) {

			//Declaration
			vector<Attendence> att;

			//Getting Data From File
			att = RW.getAttendence("Attendence");

			//Showing Attendence
			cout << endl;
			cout << "Here Is The Details Of Your Attendence!!" << endl;
			cout << endl;
			for (int i = 0; i < att.size(); i++) {
				if (att[i].getStuID() == S->getID()) {
					cout << "Attendene ID : " << att[i].getAttenID() << endl;
					cout << "Student ID   : " << att[i].getStuID() << endl;
					cout << "Student Name : " << S->getName() << endl;
					cout << "Session ID   : " << att[i].getSessID() << endl;
					cout << "--------------------" << endl;
					cout << "Total Presents : " << att[i].totalPresents() << endl;
					cout << "Total Absents  : " << att[i].totalAbsents() << endl;
					cout << "--------------------" << endl;
				}
			}

			//Finishing Statement
			cout << "---------------------" << endl;
		}

		else if (choice == 15) {

			cout << "---- Saved And Exited ----" << endl;

			//Storing the current Data of the User into Class's Attributes
			S->current_courses(enrolled);
			S->current_Assignments(submitted);
			S->current_Joined_Club(joined);
			S->current_resources(LR);
			
			//Now Copy The Entered Data To File
			S->Now_Copy_Data_To_File();
			RW.Write_FeedBacks("FeedBacks", F);
			RW.write_Projects_To_File(PR,"Projects");
		}

	} while (choice != 15);
}

void faculty() {
	//Declaring the variables
	int choice = 0; int id = 0; string str1 = "", str3 = "", str2 = "", str4 = "";
	ReadWrite RW; bool check = false;

	//Taking All the Registered Faculty
	vector<Faculty> faculty = RW.getFaculty("Faculty");
	
	//Taking Information From The Faculty And Validating
	do {
		check = false;
		cout << "Enter..." << endl;
		cout << "Name     : ";
		cin >> str1;
		cout << "ID       : ";
		cin >> id;
		cout << "Email    : ";
		cin >> str2;
		cout << "PhoneNo. : ";
		cin >> str3;
		cout << "----------------------" << endl;
		for (int i = 0; i < faculty.size(); i++) {
			if (faculty[i].getID() == id && faculty[i].getName() == str1 && faculty[i].getEmail() == str2 && faculty[i].getPhone() == str3) {
				check = true;
				cout << str1 << " !! You Are Registered" << endl;
				break;
			}
		}
		if (check == false) {
			cout << "Any Of The Entered Cendentials Is Wrong!!" << endl;
			cout << endl;
		}
	} while (check == false);

	//Taking Course From File, Creating Faculty Object
	//Setting that result to Faculty Courses
	vector<Courses*> taughtCourses = RW.getCoursesTaught(str1);
	Faculty* F = new Faculty(id, str1, str2, str3);
	F->setCourses(taughtCourses);

	//Declaration
	Courses C;
	Students students;

	//Declarations And Getting Data From Files
	vector<Attendence> att = RW.getAttendence("Attendence");
	vector<Assignments*> totalAssignments = RW.getAllAssignments("Assignments");
	vector<Courses*> totalcourses = RW.get_Courses_From_File("Courses");
	vector<Grade> grades = RW.getGrades("Grades");
	vector<Project> PR = RW.get_Projects_From_File("Projects");
	vector<Students> STU = RW.get_Students_From_File("Students");
	vector<FeedBack> Feed = RW.getFeedBacks("FeedBacks");

	do {
		cout << endl; choice = 0;
		cout << "-------------------------------" << endl;
		cout << "[1] Attendence OF Students" << endl;
		cout << "[2] Courses Teaching" << endl;
		cout << "[3] Mark Grade For Students" << endl;
		cout << "[4] Students Enrolled In Your Course" << endl;
		cout << "[5] Students In Your Project, Supervised" << endl;
		cout << "[6] Lanch New Project" << endl;
		cout << "[7] Add Assignment In Course" << endl;
		cout << "[8] Assigned Assignments" << endl;
		cout << "[9] Your FeedBack" << endl;
		cout << "[10] Exit..." << endl;
		cin >> choice;
		choice = choicesValidations(choice, 0, 10);

		if (choice == 1) {

			//Firstly, Displaying Courses Taught By Faculty
			C.displayOnScreenAllCourses(taughtCourses); int input = 0; char At; bool again = false;

			//Then Asking Course Name, nd Validation
			string n;
			n = C.validate_Course_Name(taughtCourses);

			//Getting All The Students Enrolled In That Course
			vector<Students> S = RW.get_Students_From_File(n);

			//Displaying Students
			students.displayStudents(S, {});
			vector<char> status;

			//Asking To Enter Student ID To Mark Attendence, And Validating
			cout << endl;
			input = students.validating_Student_ID(S);
				
			//Asking For Attendence
			for (int i = 0; i < att.size(); i++) {
				if (att[i].getStuID() == input) {
					status = att[i].getStatus();
					cout << "Enter Attendence (A/P) : ";
					cin >> At;
					if (status.size()+1 > 18) {
						cout << "You Cannot Add Furthur Attendence!!" << endl;
						cout << "Because, Student Has To Attend Only 18 Lectures" << endl;
					}
					else
						status.push_back(At);
					att[i].setStatus(status);
					break;
				}
			}
			
			//Finishing Line
			cout << "SuccessFull Marked!!" << endl;
		}

		else if (choice == 3) {
			Grade G; bool again = false;
			C.displayOnScreenAllCourses(taughtCourses); int input = 0, input2 = 0, input3 = 0; char At;

			string n = C.validate_Course_Name(taughtCourses);

			vector<Students> S = RW.get_Students_From_File(n);
			students.displayStudents(S, {});

			//Taking Data And Validating
			do {
				again = true;
				input = students.validating_Student_ID(S);
				input2 = G.validateGradeID(grades);
				cout << "Enter CourseID : ";
				cin >> input3;
				cout << "Enter Grade    : ";
				cin >> At;

				for (int i = 0; i < grades.size(); i++) {
					int inp = 0;
					if (grades[i].getCourseID() == input3 && grades[i].getStuID() == input) {
						again = false;
						cout << endl;
						cout << "You Have Already Graded ";
						for (int j = 0; j < STU.size(); j++) {
							if (STU[i].getID() == input) {
								cout << STU[i].getName() << " !!" << endl;
								cout << "----------------" << endl;
								cout << endl;
								cout << "Now Either Mark Grade For Other Student For Same Course" << endl;
								cout << "                        OR                             " << endl;
								cout << "Mark Grade For Same Student For Any Other Course" << endl;
								cin >> inp;
								cout << endl;
								cout << "----------------" << endl;
								cout << endl;
								break;
							}
						}
					}
				}
			} while (again == false);

			G.setGradeID(input2); G.setCId(input3); G.setSId(input); G.setGrade(At);

			grades.push_back(G);

			cout << "You Have SuccessFully Graded!!" << endl;
		}

		else if (choice == 2) {
			C.displayOnScreenAllCourses(taughtCourses);
		}

		else if (choice == 4) {

			//Displaying Courses
			C.displayOnScreenAllCourses(taughtCourses); string st;
			
			//Validation
			st = C.validate_Course_Name(taughtCourses);

			vector<Students> S = RW.get_Students_From_File(st);
			students.displayStudents(S);
		}

		else if (choice == 5) {
			int id1 = 0; bool again = false;
			
			//Displayoing Projects, Faculty Supervised
			Project P;
			P.displayProjectsSome(PR, str1);

			//Asking For Project ID And Validating
			id1 = P.validating_ProjectID(PR, str1);

			//Displaying Currently Enrolled Students
			vector<Students*> St;
			cout << "Currently Students Enrolled Are : " << endl;
			for (int i = 0; i < PR.size(); i++) {
				if (PR[i].getPID() == id1) {
					St = PR[i].getAllStudents();
					students.displayStudents({},St);
					break;
				}
			}
		}

		else if (choice == 6) {
			string desc = "", title = ""; int id = 0;

			cout << "Enter ProjectID : ";
			cin >> id;
			cout << "Enter Title     : ";
			cin >> title;
			cout << "Enter Desc.     : ";
			cin >> desc;

			Project P(id, title, desc, F);
			PR.push_back(P);
		}

		else if (choice == 7) {
			C.displayOnScreenAllCourses(taughtCourses); int st = 0; string s = ""; bool again = false;
			string st1, st2; int aid;

			s = C.validate_Course_Name(taughtCourses);
			for (int i = 0; i < taughtCourses.size(); i++) {
				if (taughtCourses[i]->getName() == s) {
					st = taughtCourses[i]->getID();
					break;
				}
			}

			//Demanding Data From The User
			cout << "Assignment Description : ";
			cin >> st1;
			cout << "Assignment Date : ";
			cin >> st2;
			do {
				again = false;
				cout << "Enter Assignment ID : ";
				cin >> aid;
				for (int i = 0; i < totalAssignments.size(); i++) {
					if (totalAssignments[i]->getID() == aid) {
						cout << "Assignment ID is Already Allocated !!" << endl;
						cout << "-------------" << endl;
						again = true;
						cout << endl;
					}
				}
			} while (again == true);

			Assignments* A = new Assignments(aid, st, st2, st1);
			totalAssignments.push_back(A);

			cout << "Successfully Added !!" << endl;
			cout << endl;
		}

		else if (choice == 8) {
			vector<Assignments*> ass;
			cout<<totalAssignments.size();
			C.displayOnScreenAllCourses(taughtCourses); int in = 0;
			cout << "Enter Course ID, To See Assignments : ";
			cin >> in;

			for (int i = 0; i < totalAssignments.size(); i++) {
				if (totalAssignments[i]->getCourseID() == in) {
					ass.push_back(totalAssignments[i]);
				}
			}
			totalAssignments[0]->display(ass);
		}

		else if (choice == 9) {
			FeedBack fee;

			cout << "We Are Displaying Your FeedBack" << endl;
			fee.display(Feed,id);
		}

		else if (choice == 10) {
			//Writing Data InTo File Again
			RW.addAssignmentsOfCourse(totalAssignments, "Assignments");
			RW.writeAttendence(att, "Attendence");
			RW.writeGrades(grades, "Grades");
			RW.write_Projects_To_File(PR, "Projects");
		}

	} while (choice != 10);
}