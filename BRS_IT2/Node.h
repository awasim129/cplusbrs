//Reservation Node
#pragma once
#include <iostream>

using namespace std;

struct node {
	int seat;
	string fname;
	string lname;
	int dd, mm, yyyy;
	node *next;
};

node *createNode() {
	node *temp;
	temp = (node*)malloc(sizeof(node));
	return temp;
}

