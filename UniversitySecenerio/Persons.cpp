#include<iostream>
#include<string>
#include<vector>
#include"Persons.h"
using namespace std;


Persons::Persons() {
	name = "";
	email = "";
	phoneNumber = "";
}
Persons::Persons(string a, string b, string c) :name(a), email(b), phoneNumber(c) {};

void Persons::setName(string a) {
	name = a;// checkName(a);
}
void Persons::setEmail(string a) {
	email = a;
}
void Persons::setPhoneNumber(string a) {
	phoneNumber = a;// checkPhoneNumber(a);
}
string Persons::getName()const {
	return name;
}
string Persons::getEmail()const {
	return email;
}
string Persons::getPhone()const {
	return phoneNumber;
}
string Persons::checkPhoneNumber(string phone) {
	if (phone.length() != 11) {
		do {
			cout << "PLease can you Enter Phone Number Again: ";
			cin >> phone;
		} while (phone.length() != 11);
	}
	return phone;
}


string Persons::checkName(string nam) {
	bool check = false;
	do {
		check = false;
		for (int i = 0; i < nam.length(); i++) {
			if (!isalpha(nam[i])) {
				check = true;
				break;
			}
		}
		if (check == true) {
			cout << "Can You Please Enter Name Again: ";
			cin >> nam;
		}
	} while (check == true);
	return nam;
}