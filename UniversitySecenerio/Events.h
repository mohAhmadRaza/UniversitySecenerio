#pragma once

#include<iostream>
#include<string>
using namespace std;

class Events {
	int eventID;
	string title;
	string description;
	string date;
	string venue;
public:
	Events();
	Events(string a, string b, string c, string d);
	void setTitle(string a);
	void setDesc(string a);
	void setDate(string a);
	void setVenue(string a);
	string getDate()const;
	string getVenue()const;
	string getDesc()const;
	string getTitle()const;
};