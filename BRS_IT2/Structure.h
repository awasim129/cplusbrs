//Reservation Structure
#pragma once
#include <iostream>

using namespace std;

struct res { 
	int seat;
	char fname[15];
	char lname[15];
	int dd, mm, yyyy;
};

struct reslist {
	int seat;
	string fname;
	string lname;
	int dd, mm, yyyy;
};