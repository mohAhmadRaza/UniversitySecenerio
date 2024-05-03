#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
#include"Students.h"
#include"Events.h"
using namespace std;

class Club;
//ostream& operator << (ostream& cout, const Club&);

class Club {
	int clubID;
	string name;
	string description;
	vector<Students*> members;
	vector<Events> eventsOrganized;

	//Some utility functions for vallidations
	string checkName(string nam);
public:
	Club();
	Club(int a, string nam, string desc);
	void add_member(Students* S);
	void events_organized(Events& E);
	void setName(string nam);
	void setID(int nam);
	void setDecs(string desc);
	string getName()const;
	string getDesc();
	int getClubID() const;
	void display(vector<Club*>);

	//friend ostream& operator << (ostream&, Club&);
};

//ostream& operator<<(ostream& cout, Club& clubs) {
//	cout << "ID    : " << clubs.getClubID() << endl;
//	cout << "Name  : " << clubs.getName() << endl;
//	cout << "Desc. : " << clubs.getDesc() << endl;
//	cout << "--------------------------" << endl;
//	return cout;
//}