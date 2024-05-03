#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class LiberaryResource;
//ostream& operator << (ostream&, const LiberaryResource&);

class LiberaryResource {
	int resourseID;
	string title;
	string author;
	int availaibility;
public:
	LiberaryResource();
	LiberaryResource(int r, string t, string a, int avail);
    void setTitle(string t);
	void setAuthor(string a);
	void setAvail(int a);
	/*void setSID(int a) {
		studentID = a;
	}*/
	void setRID(int a);

	string getTitle()const;
	string getAuthor()const;
	int getAvail()const;
	/*int getSID()const {
		return studentID;
	}*/
	int getRID()const;
	//friend ostream& operator<<(ostream&, const LiberaryResource&);
};

//ostream& operator<<(ostream& cout, const LiberaryResource& L) {
//	cout << "Resource ID   : " << L.getRID() << endl;
//	cout << "Name          : " << L.getTitle() << endl;
//	cout << "Author        : " << L.getAuthor() << endl;
//	cout << "Availaibility : " << L.getAvail() << endl;
//	cout << "--------------------------" << endl;
//	return cout;
//}