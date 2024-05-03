#include<iostream>
#include<string>
#include"Events.h"
using namespace std;


Events::Events() {
		eventID++;
		title = "";
		description = "";
		date = "";
		venue = "";
}
Events::Events(string a, string b, string c, string d) {
	eventID++;
	title = a;
	description = b;
	date = c;
	venue = d;
}
void Events::setTitle(string a) {
	title = a;
}
void Events::setDesc(string a) {
	description = a;
}
void Events::setDate(string a) {
	date = a;
}
void Events::setVenue(string a) {
	venue = a;
}
string Events::getDate()const {
	return date;
}
string Events::getVenue()const {
	return venue;
}
string Events::getDesc()const {
	return description;
}
string Events::getTitle()const {
	return title;
}