#include"LiberaryResource.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;


LiberaryResource::LiberaryResource() {
	resourseID = 0;
	title = "";
	author = "";
	availaibility = 0;
}
LiberaryResource::LiberaryResource(int r, string t, string a, int avail) {
	title = t;
	author = a;
	availaibility = avail;
	resourseID = r;
}
void LiberaryResource::setTitle(string t) {
	title = t;
}
void LiberaryResource::setAuthor(string a) {
	author = a;
}
void LiberaryResource::setAvail(int a) {
	availaibility = a;
}
	/*void setSID(int a) {
		studentID = a;
	}*/
void LiberaryResource::setRID(int a) {
	resourseID = a;
}

string LiberaryResource::getTitle()const {
	return title;
}
string LiberaryResource::getAuthor()const {
	return author;
}
int LiberaryResource::getAvail()const {
	return availaibility;
}
	/*int getSID()const {
		return studentID;
	}*/
int LiberaryResource::getRID()const {
	return resourseID;
}
