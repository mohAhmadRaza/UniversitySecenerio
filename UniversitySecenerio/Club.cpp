#include"Club.h"
#include"Persons.h"
#include"Students.h"
#include"Events.h"
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

Club::Club() {
	clubID = 0;
	name = "";
	description = "";
}
Club::Club(int a, string nam, string desc) {
	clubID = a;
	name = nam;
	description = desc;
}

void Club::add_member(Students* S) {
	members.push_back(S);
}
void Club::events_organized(Events& E) {
	eventsOrganized.push_back(E);
}
void Club::setName(string nam) {
	name = nam;
}
void Club::setID(int nam) {
	clubID = nam;
}
void Club::setDecs(string desc) {
	description = desc;
}
string Club::getName()const {
	return name;
}
string Club::getDesc() {
	return description;
}
int Club::getClubID() const {
	return clubID;
}

void Club::display(vector<Club*> S) {
	cout << endl;
	cout << "------------------------------------------" << endl;
	cout << "ID" << right << setw(7) << "Name" << right << setw(29) << "Description" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < S.size(); i++) {
		cout << left << setw(5) << S[i]->getClubID() << left << setw(22) << S[i]->getName() << left << setw(14) << S[i]->getDesc() << endl;
	}
	cout << "------------------------------------------" << endl;
}