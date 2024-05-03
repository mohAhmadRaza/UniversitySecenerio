#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Persons {
protected:
	string name;
	string email;
	string phoneNumber;

	//Some utility functions for validations
	string checkPhoneNumber(string phone);
	string checkName(string nam);
public:
	Persons();
	Persons(string a, string b, string c);

	void setName(string a);
	void setEmail(string a);
	void setPhoneNumber(string a);
	string getName()const;
	string getEmail()const;
	string getPhone()const;
};


