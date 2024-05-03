#include"ReadWritingInFile.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <sstream>
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

void ReadWrite::writing_Courses_To_File(const vector<Courses*> C, string file) {
	fstream File;
	File.open(file + ".txt", ios::out);

	if (File.is_open()) {
		for (int i = 0; i < C.size(); i++) {
			File << C[i]->getID() << endl;
			File << C[i]->getName() << endl;
			File << C[i]->getHours() << endl;
			File << C[i]->getInstructor() << endl;
		}
	}
	File.close();
}
void ReadWrite::writing_Students_To_File(const vector<Students*> C, string file) {
	fstream File;
	File.open(file + ".txt", ios::out);

	if (File.is_open()) {
		for (int i = 0; i < C.size(); i++) {
			File << C[i]->getName() << endl;
			File << C[i]->getEmail() << endl;
			File << C[i]->getPhone() << endl;
			File << C[i]->getID() << endl;
		}
	}
	File.close();
}
vector<Students> ReadWrite::get_Students_From_File(string file) {
	ifstream File(file + ".txt");

	vector<Students> STU; string line; int id1 = 0;

	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		while (!File.eof()) {
			Students S;
			getline(File, line);
			S.setName(line);
			getline(File, line);
			S.setEmail(line);
			getline(File, line);
			S.setPhoneNumber(line);
			getline(File, line);
			istringstream(line) >> id1;
			S.setID(id1);

			STU.push_back(S);
		}
	}
	File.close();

	return STU;
}
vector<Students*> ReadWrite::get_Student_From_File(string file) {
	fstream File;
	File.open(file + ".txt", ios::in);

	vector<Students*> STU; string line;
	if (File.is_open()) {
		while (getline(File,line)) {
			Students* S = new Students;
			S->setName(line);
			getline(File, line);
			S->setEmail(line);
			getline(File, line);
			S->setPhoneNumber(line);
			getline(File, line);
			int id1 = 0;
			istringstream(line) >> id1;
			S->setID(id1);

			STU.push_back(S);
		}
	}
	File.close();

	return STU;
}
vector<Courses*> ReadWrite::get_Courses_From_File(string file) {
	fstream File;
	File.open(file + ".txt", ios::in); // Open in input mode
	vector<Courses*> COU;
	string line;

	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		while (!File.eof()) { // Use getline directly as loop condition
			Courses* S = new Courses;

			getline(File, line);
			int id;
			istringstream(line) >> id;
			S->setID(id);

			getline(File, line);
			S->setName(line);

			getline(File, line);
			int id2;
			istringstream(line) >> id2;
			S->setHours(id2);

			getline(File, line);
			S->setInstructor(line);

			COU.push_back(S);
		}
	}
	else {
		cout << "Failed to open file" << endl;
	}

	File.close();
	return COU;
}
void ReadWrite::addStudentToFile(string file, int a, string b, string c, string d, vector<string> C,const vector<Club*>club, const vector<Assignments*>Assign,const  vector<LiberaryResource*> LR) {
	fstream File;
	File.open(file + ".txt", ios::out);

	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		File << a << endl;
		File << b << endl;
		File << c << endl;
		File << d << endl;

		File << "Courses" << endl;
		for (int i = 0; i < C.size(); i++) {
			File << C[i] << endl;
		}

		for (int i = 0; i < Assign.size(); i++) {
			cout << Assign[i]->getID() << endl;
			cout << Assign[i]->getDesc() << endl;
			cout << Assign[i]->getDate() << endl;
		}

		File << "Assignments" << endl;
		for (int i = 0; i < Assign.size(); i++) {
			File << Assign[i]->getID() << endl;
			File << Assign[i]->getDesc() << endl;
			File << Assign[i]->getDate() << endl;
		}

		File << "Clubs" << endl;
		for (int i = 0; i < club.size(); i++) {
			File << club[i]->getClubID() << endl;
			File << club[i]->getName() << endl;
			File << club[i]->getDesc() << endl;
		}

		File << "Resources" << endl;
		for (int i = 0; i < LR.size(); i++) {
			File << LR[i]->getRID() << endl;
			File << LR[i]->getTitle() << endl;
			File << LR[i]->getAuthor() << endl;
			File << LR[i]->getAvail() << endl;
		}

	}
	File.close();
}
vector<string> ReadWrite::getCoursesOfStudent(string file) {
	vector<string> str;
	fstream File;
	File.open(file + ".txt", ios::in);

	string line;

	if (File.is_open()) {
		while (!File.eof()) {
			getline(File, line);
			if (line == "Courses") {
				while (getline(File, line) && line != "Assignments") {
					str.push_back(line);
				}
			}
		}
	}
	File.close();
	return str;
}
vector<Club*> ReadWrite::getClubOfStudent(string file) {
	vector<Club*> str;
	fstream File;
	File.open(file + ".txt", ios::in);

	string line;

	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		while (!File.eof()) {
			getline(File, line);
			if (line == "Clubs") {
				while (getline(File, line) && line != "Resources") {
					Club* C = new Club;
					int id = 0;
					istringstream(line) >> id;
					C->setID(id);
					getline(File, line);
					C->setName(line);
					getline(File, line);
					C->setDecs(line);

					str.push_back(C);
				}
			}
		}
	}
	File.close();
	return str;
}
vector<LiberaryResource*> ReadWrite::get_Reources_Of_Student(string file) {
	vector<LiberaryResource*> str;
	fstream File;
	File.open(file + ".txt", ios::in);

	string line;

	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		while (!File.eof()) {
			getline(File, line);
			if (line == "Resources") {
				while (getline(File, line) && !File.eof()) {
					LiberaryResource* C = new LiberaryResource;

					int id = 0;
					istringstream(line) >> id;
					C->setRID(id);
					getline(File, line);
					C->setTitle(line);
					getline(File, line);
					C->setAuthor(line);
					getline(File, line);
					int id2 = 0;
					istringstream(line) >> id2;
					C->setAvail(id2);

					str.push_back(C);
				}
			}
		}
	}
	File.close();
	return str;
}
vector<Assignments*> ReadWrite::get_Assignments_From_STUfile(string file) {
	vector<Assignments*> str;
	fstream File;
	File.open(file + ".txt", ios::in);

	string line;
	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		while (!File.eof()) {
			getline(File, line);
			if (line == "Assignments") {
				while (getline(File, line) && line != "Clubs") {
					Assignments* C = new Assignments;

					int id;
					istringstream(line) >> id;
					C->setID(id);
					getline(File, line);
					C->setDescription(line);
					getline(File, line);
					C->setDate(line);
					
					str.push_back(C);
				}
			}
		}
	}
	File.close();
	return str;
}
void ReadWrite::addAssignmentsOfCourse(vector<Assignments*> Assign, string file) {
	fstream File;
	File.open(file + ".txt", ios::out);

	File << "Assignments" << endl;
	for (int i = 0; i < Assign.size(); i++) {
		File << Assign[i]->getID() << endl;
		File << Assign[i]->getCourseID() << endl;
		File << Assign[i]->getDesc() << endl;
		File << Assign[i]->getDate() << endl;
	}
	File.close();
}
vector<Grade> ReadWrite::getGrades(string file) {
	vector<Grade> str;
	fstream File;
	File.open(file + ".txt", ios::in);

	string line;

	if (File.is_open()) {
		while (!File.eof()) {
			Grade G;
			getline(File, line);
			G.setGradeID(stoi(line));
			getline(File, line);
			G.setSId(stoi(line));
			getline(File, line);
			G.setCId(stoi(line));
			getline(File, line);
			G.setGrade(line[0]);

			str.push_back(G);
		}
	}
	File.close();
	return str;
}
void ReadWrite::writeAllClubs(const vector<Club*> club, string file) {
	fstream File;
	File.open(file + ".txt", ios::out);

	File << "Clubs" << endl;
	for (int i = 0; i < club.size(); i++) {
		File << club[i]->getClubID() << endl;
		File << club[i]->getName() << endl;
		File << club[i]->getDesc() << endl;
	}
	File.close();
}
void ReadWrite::Write_FeedBacks(string file, const vector<FeedBack>& F) {
	ofstream File(file + ".txt");

	for (int i = 0; i < F.size(); i++) {
		File << F[i].getFID() << endl;
		File << F[i].getContent() << endl;
		File << F[i].getRating() << endl;
		File << F[i].getSID() << endl;
		File << F[i].getCID() << endl;
	}
	File.close();
}
vector<FeedBack> ReadWrite::getFeedBacks(string file) {
	vector<FeedBack> str;
	fstream File;
	File.open(file + ".txt", ios::in); // Use ifstream for input only
	string line;

	if (File.is_open()) { // Check if file is open
		while (getline(File,line)) {
			FeedBack C;

			int id2 = 0;
			istringstream(line) >> id2;
			C.setFID(id2);
			getline(File, line);
			C.setContent(line);
			getline(File, line);
			C.setRatings(stof(line));
			getline(File, line);
			istringstream(line) >> id2;
			C.setSID(id2);
			getline(File, line);
			istringstream(line) >> id2;
			C.setCID(id2);

			str.push_back(C);
		}
		File.close();
	}
	else {
		cerr << "Error opening file: " << file << ".txt" << endl;
	}
	return str;
}
vector<Project> ReadWrite::get_Projects_From_File(string file) {
	string line;

	vector<Project> P; vector<Students*> S;
	fstream File;
	File.open(file + ".txt", ios::in);

	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		while (!File.eof()) {
			Project PR; S.clear();
			while (getline(File, line) && line != "Students") {
				int id1 = 0;
				istringstream(line) >> id1;
				PR.setPID(id1);
				getline(File, line);
				PR.setTitle(line);
	            getline(File, line);
				PR.setDesc(line);
			}
			while (getline(File, line) && line != "Faculty") {
				Students* STU = new Students;
				int id1 = 0;
				istringstream(line) >> id1;
				STU->setID(id1);
				getline(File, line);
				STU->setName(line);
				getline(File, line);
				STU->setEmail(line);
				getline(File, line);
				STU->setPhoneNumber(line);

				S.push_back(STU);
			}
			PR.setStudents(S);
			string str1, str2, str3;
			int id1 = 0;
			getline(File, line);
			istringstream(line) >> id1;
			getline(File, line);
			str1 = line;
			getline(File, line);
			str2 = line;
			getline(File, line);
			str3 = line;
			Faculty* F = new Faculty(id1, str1, str2, str3);
			PR.setFaculty(F);

			P.push_back(PR);
		}
	}
	return P;
}
vector<Attendence> ReadWrite::getAttendence(string file) {
	int count = 0, i = 0; vector<char> att;
	fstream File1;
	File1.open(file + ".txt", ios::in);

	string line;

	if (File1.is_open()) {
		while (!File1.eof()) {
			getline(File1, line);
			if (line == "Attendence") {
				count++;
			}
		}
	}
	File1.close();

	vector<Attendence> Att(count);
	fstream File;
	File.open(file + ".txt", ios::in);
	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		getline(File, line);
		while (i < count) {
			att.clear();
			getline(File, line);
			int id1 = 0;
			istringstream(line) >> id1;
			Att[i].setAttID(id1);
			getline(File, line);
			istringstream(line) >> id1;
			Att[i].setStudentID(id1);
			getline(File, line);
			istringstream(line) >> id1;
			Att[i].setSessionID(id1);
			while (getline(File, line) && line != "Attendence") {
				att.push_back(line[0]);
			}
			Att[i].currentStatus(att);
			i++;
		}
	}
	File.close();
	return Att;
}
void ReadWrite::write_Projects_To_File(const vector<Project>& projects, string file) {
	ofstream File(file + ".txt"); int i = 0;
	
	if (File.is_open()) {
		for (const Project& PR : projects) {
			// Write project details
			File << PR.getPID() << endl;
			File << PR.getTitle() << endl;
			File << PR.getDesc() << endl;

			// Write students
			File << "Students" << endl;
			vector<Students*> STU = PR.getAllStudents();
			for (int i = 0; i < STU.size(); i++) {
				File << STU[i]->getID() << endl;
				File << STU[i]->getName() << endl;
				File << STU[i]->getEmail() << endl;
				File << STU[i]->getPhone() << endl;
			}

			// Write faculty
			File << "Faculty" << endl;
			const Faculty* F = PR.getFacultySupervising();
			File << F->getID() << endl;
			File << F->getName() << endl;
			File << F->getEmail() << endl;
			File << F->getPhone() << endl;
		}
	}
}
vector<Courses*>  ReadWrite::getCoursesTaught(string file) {
	vector<Courses*> str;
	ifstream File(file + ".txt");

	string line;

	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		while (!File.eof()) {
			getline(File, line);
			if (line == "Courses") {
				while (getline(File, line) && line != "Assignments") {
					Courses* C = new Courses;

					int id = 0;
					istringstream(line) >> id;
					C->setID(id);
					getline(File, line);
					C->setName(line);
					getline(File, line);
					istringstream(line) >> id;
					C->setHours(id);
					getline(File, line);
					C->setInstructor(line);

					str.push_back(C);
				}
			}
		}
	}
	File.close();
	return str;
}
vector<Faculty> ReadWrite::getFaculty(string file) {
	ifstream File(file + ".txt"); int id1 = 0;

	vector<Faculty> STU; string line;
	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		while (!File.eof()) {
			Faculty S;
			getline(File, line);
			S.setName(line);
			getline(File, line);
			S.setEmail(line);
			getline(File, line);
			S.setPhoneNumber(line);
			getline(File, line);
			istringstream(line) >> id1;
			S.setID(id1);

			STU.push_back(S);
		}
	}
	File.close();

	return STU;
}
void ReadWrite::writeAttendence(const vector<Attendence> A, string file) {
	ofstream File(file + ".txt"); int i = 0;
	vector<char> a;

	if (File.is_open()) {
		while (i < A.size()) {
			a.clear();
			File << "Attendence" << endl;
			File << A[i].getAttenID() << endl;
			File << A[i].getStuID() << endl;
			a = A[i].getStatus();
			for (int j = 0; j < a.size();j++ ) {
				File << a[i] << endl;
			}
			i++;
		}
	}
	File.close();
}
void ReadWrite::writeGrades(const vector<Grade> G, string file) {
	ofstream File(file + ".txt"); int i = 0;

	if (File.is_open()) {
		while (i < G.size()) {
			File << G[i].getGradeID() << endl;
			File << G[i].getStuID() << endl;
			File << G[i].getCourseID() << endl;
			File << G[i].getGrade() << endl;
			i++;
		}
	}
	File.close();
}
vector<Assignments*> ReadWrite::getAllAssignments(string file) {
	vector<Assignments*> str;
	fstream File;
	File.open(file + ".txt", ios::in);

	string line;
	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		getline(File, line);
		while (getline(File, line)) {
			Assignments* C = new Assignments;
			
			int id;
			istringstream(line) >> id;
			C->setID(id);
			getline(File, line);
			istringstream(line) >> id;
			C->setCourseID(id);
			getline(File, line);
			C->setDescription(line);
			getline(File, line);
			C->setDate(line);
			str.push_back(C);
		}
	}
	File.close();
	return str;
}
std::vector<Department> ReadWrite::getDepartments(std::string file) {
	std::vector<Department> dep;
	std::fstream File(file + ".txt", std::ios::in);

	if (!File.is_open()) {
		// Handle file open error
		return dep;
	}

	std::string line;
	while (getline(File, line)) {
		if (line == "Department") {
			Department D;
			int id;
			std::getline(File, line); // Read department ID
			std::istringstream(line) >> id;
			D.setID(id);
			std::getline(File, line); // Read department name
			D.setName(line);
			std::getline(File, line); // Read department head
			D.setHead(line);

			getline(File, line);
			while (line != "Faculty") {
				// Read courses
				Courses* C = new Courses;
				std::istringstream(line) >> id;
				C->setID(id);
				std::getline(File, line); // Read course name
				C->setName(line);
				std::getline(File, line); // Read course hours
				std::istringstream(line) >> id;
				C->setHours(id);
				std::getline(File, line); // Read course instructor
				C->setInstructor(line);

				D.addCourse(C);
				getline(File, line);
			}

			getline(File, line);				// Read faculty
			Faculty* F = new Faculty;
			F->setName(line);
			std::getline(File, line); // Read faculty email
			F->setEmail(line);
			std::getline(File, line); // Read faculty phone number
			F->setPhoneNumber(line);
			std::getline(File, line); // Read faculty ID
			std::istringstream(line) >> id;
			F->setID(id);
			D.addFaculty(F);

			dep.push_back(D);
		}
		}
	File.close(); // Don't forget to close the file
	return dep;
}

void ReadWrite::writeResources(const vector<LiberaryResource*> club, string file){
fstream File;
	File.open(file + ".txt", ios::out);

	File << "Resources" << endl;
	for (int i = 0; i < club.size(); i++) {
		File << club[i]->getRID() << endl;
		File << club[i]->getTitle() << endl;
		File << club[i]->getAuthor() << endl;
		File << club[i]->getAvail() << endl;
	}
	File.close();
}
void ReadWrite::writeFaculty(const vector<Faculty> F, string file) {
	fstream File;
	File.open(file + ".txt", ios::out);

	if (File.is_open()) {
		for (int i = 0; i < F.size(); i++) {
			File << F[i].getName() << endl;
			File << F[i].getEmail() << endl;
			File << F[i].getPhone() << endl;
			File << F[i].getID() << endl;
		}
	}
	File.close();
}
void ReadWrite::writeDepartments(vector<Department> D, string file) {
	fstream File; int j = 0;
	File.open(file + ".txt", ios::out);


	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		while (j < D.size()) {
			File << "Department" << endl;
			File << D[j].getID() << endl;
			File << D[j].getName() << endl;
			File << D[j].getHead() << endl;

			vector<Courses*> C = D[j].getCourses();
			for (int i = 0; i < C.size(); i++) {
				File << C[i]->getID() << endl;
				File << C[i]->getName() << endl;
				File << C[i]->getHours() << endl;
				File << C[i]->getInstructor() << endl;
			}

			File << "Faculty" << endl;
			vector<Faculty*> F = D[j].getFaculties();
			for (int i = 0; i < F.size(); i++) {
				File << F[i]->getName() << endl;
				File << F[i]->getEmail() << endl;
				File << F[i]->getPhone() << endl;
				File << F[i]->getID() << endl;
			}
			j++;
		}
	}
	File.close();
}
Students ReadWrite::getStudentData(string a) {
	ifstream File(a + ".txt");

	Students S; string line; int id1 = 0;
	vector<string> s; vector<Assignments*> AS; vector<Club*> c; vector<LiberaryResource*> L;

	if (File.is_open() && (File.rdstate() & ios_base::binary) == 0) {
		getline(File, line);
		S.setName(line);
		getline(File, line);
		S.setEmail(line);
		getline(File, line);
		S.setPhoneNumber(line);
		getline(File, line);
		istringstream(line) >> id1;
		S.setID(id1);
		getline(File, line);
		while (getline(File, line) && line != "Assignments") {
			s.push_back(line);
		}
		while (getline(File, line) && line != "Clubs") {
			Assignments* As = new Assignments;
			istringstream(line) >> id1;
			As->setID(id1);
			getline(File, line);
			As->setDescription(line);
			getline(File, line);
			As->setDate(line);
			AS.push_back(As);
		}
		while (getline(File, line) && line != "Resources") {
			Club* As = new Club;
			istringstream(line) >> id1;
			As->setID(id1);
			getline(File, line);
			As->setName(line);
			getline(File, line);
			As->setDecs(line);
			c.push_back(As);
		}
		while (!File.eof()) {
			LiberaryResource* As = new LiberaryResource;
			istringstream(line) >> id1;
			As->setRID(id1);
			getline(File, line);
			As->setTitle(line);
			getline(File, line);
			As->setAuthor(line);
			getline(File, line);
			istringstream(line) >> id1;
			As->setAvail(id1);
			L.push_back(As);
		}
	}
	S.current_Assignments(AS); S.current_courses(s); S.current_Joined_Club(c);
	S.current_resources(L);

	return S;
}