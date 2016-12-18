//Bus Reservation System Source Code by
//Anas Waseem, Muhammad Jawad Hussain and Muhammad Taha

//Header Files End
//and Function Declaration Starts

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Node.h"	//The File Where Node is defined
#include "Structure.h"	//The File where structure is defined
#include "Time.h"	//The File Where Reservation Time is Defined

using namespace std;  
void bookings(); 
void records();
void busesinfo();
void mmenu();
//DONE
void khiskrres();
void khiskrrec();

//PENDING
void khihydres();
void lhehydrec(); 
//LHE-MUR
void lhemurres(); //Refer T. Manual
				  //void lhemurrec(); Under Construction
				  //LHE-KHI
void lhekhires(); //Refer T. Manual
				  //void lhekhirec(); //Under Construction

fstream log_skr;
fstream log_hyd;
fstream log_mur;
fstream log_khi;
string resdby;		//Shows the Name at the End of the Bill
//Structure for Reservation



int n = 0; //Wrong Pass Variable
node *START = NULL;



void main() {  //Its the Login Function, details on Technical Manual Page 1
	system("cls");
	cout << "*****************************************************\n";
	cout << "*.........Welcome to Bus Reservation System.........*\n";
	cout << "*****************************************************\n\n";
	cout << "Please Enter your username and password!\n\n";
	string username;
	int password;
beg: //Incase of wrong password
	cout << "Username:\t";
	cin >> username;
	cout << "\nPassword:\t";
	cin >> password;
	n++;
	if (username == "anas" && password == 5858) {
		resdby = "Anas Waseem";
		mmenu();
	}
	else if (username == "jawad" && password == 6868) {
		resdby = "Muhammad Jawad";
		mmenu();
	}
	else if (username == "taha" && password == 7878) {
		resdby = "Muhammad Taha";
		mmenu();
	}
	else {
		if (n == 1) {
			cout << "\nWrong Attempt 1, you have 2 Attempts remaining\n\n";
			goto beg;
		}
		else if (n == 2) {
			cout << "\nWrong Attempt 2, you have 1 Attempts remaining\n\n";
			goto beg;
		}
		else if (n == 3) {
			cout << "\nWrong Attempt 3, Software Exiting";
			system("pause");

		}
	}

}

void mmenu()
{
	system("cls");
	cout << "*********************************************************************************\n"
		<< "*           WELCOME TO BS IT - 4 BUS RESERVATION SYSTEM MAIN MENU               *\n"
		<< "**********************************************************************************";
	cout << endl << endl;
	cout << "Please Select your desired Operation:\n"
		<< "1. Bookings\n"
		<< "2. Display Records\n"
		<< "3. View Buses Information\n"
		<< "4. Exit\n\n"
		<< "Enter Choice:\t";
	int init;
	cin >> init;
	if (init == 1)
		bookings();
	else if (init == 2)
		records();
	else if (init == 3)
		busesinfo();
	else {
		cout << "System will now exit";
	}


}

void bookings() {
	cout << "Welcome to Route Selection:\n\n"
		<< "1. Karachi to Sukkur (Rs. 800/person)\n"
		<< "2. Karachi to Hyderabad (Rs. 400/person)\n"
		<< "3. Karachi to Gawadar (Rs. 1600/person)\n"
		<< "4. Karachi to Lahore (Rs. 3000/person)\n"
		<< "5. Return to Main Menu\n\n"
		<< "Enter Choice: ";
	int option;
	cin >> option;

	if (option == 1)
		khiskrres();
	else if (option == 2)
		khihydres();
	else if (option == 3)
		lhemurres();
	else if (option == 4)
		lhekhires();
	else if (option == 5)
		mmenu();
	else
		cout << "System will now exit";
}

void records() {
	cout << "Bookings Information Menu, Please Select your route:\n\n"
		<< "1. Karachi to Sukkur (Rs. 800/person)\n"
		<< "2. Karachi to Hyderabad (Rs. 400/person)\n"
		<< "3. Karachi to Gawadar (Rs. 1600/person)\n"
		<< "4. Karachi to Lahore (Rs. 3000/person)\n"
		<< "5. Return to Main Menu\n\n"
		<< "Enter Choice: ";
	int option;
	cin >> option;

	if (option == 1)
		khiskrrec();
	else if (option == 2)
		cout << "Under Consrtruction";
	else if (option == 3)
		cout << "Under Consrtruction";
	else if (option == 4)
		cout << "Under Consrtruction";
	else if (option == 5)
		mmenu();
	else
		cout << "System will now exit";
	system("pause");
	mmenu();
}

void busesinfo() {
	system("cls");
	cout << "***********************************************\n"
		<< "* BUSES INFORMATION CENTRE - AVAILABLE BUSES  *\n"
		<< "***********************************************\n"
		<< "SNo.        Route                       Timings\n"
		<< "***********************************************\n\n"
		<< "BUS-001     Karachi to Sukkur              08:00 \n"
		<< "BUS-002     Karachi to Hyderabad           10:30 \n"
		<< "BUS-003     Karachi to Gawadar             23:00 \n"
		<< "BUS-004     Karachi to Lahore              19:45 \n"
		<< "\nWe have 1 Bus for each route once in a day! Copyrights (c) 2016 - BS IT_4";
	cout << "Press Any key to Continue.....";
	system("pause"); mmenu();
}

void insert(int dd, int mm, int yyyy, int seat) {
	node *temp, *t;

	temp = createNode();
	(*temp).dd = dd;
	(*temp).mm = mm;
	(*temp).yyyy = yyyy;
	(*temp).seat = seat;
	(*temp).next = NULL;

	if (START == NULL) {
		START = temp;
	}

	else {
		t = START;

		while ((*t).next != NULL) {
			(t) = (*t).next;
		}
		(*t).next = temp;
	}
}

void khiskrres() {
	system("cls");
	cout << "Welcome to the Reservation System for Karachi - Sukkur Route\n\n";

	fstream skr;
	int i = 1;
	cout << "How many Seats you want to reserve (Max 10 at a time)?: ";
	cin >> i;
	res r[10];
	remove("khi-skr.dat");
	skr.close();
	cout << "\nEnter the following information to complete the booking:\n\n";
	for (int b = 1; b <= i; b++) {
		skr.open("khi-skr.dat", ios::app);
		log_skr.open("khi-skr-log.dat", ios::app);
		cout << "Please Enter Departure Date (DD MM YYYY): ";
		cin >> r[i].dd >> r[i].mm >> r[i].yyyy;
		if (r[i].dd > 31 || r[i].mm > 12) {
			cout << "Invalid Date/Month, Please try again!\n\n";
			cout << "Please Enter Departure Date (DD MM YYYY): ";
			cin >> r[i].dd >> r[i].mm >> r[i].yyyy;
		}
		cout << "Seat No.: ";
		cin >> r[i].seat;
		if (r[i].seat > 30) {
			cout << "Only 30 Seats Available, please try again!\n\n";
			cout << "Seat No.: ";
			cin >> r[i].seat;
		}
		cout << "Passenger's Name: ";
		cin >> r[i].fname >> r[i].lname;
		skr << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		log_skr << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		skr.close();
		log_skr.close();
		cout << endl;
		cout << "Reservation # " << i << endl;

	}
	//**********************************************************************************************************************
	system("cls");
	cout << "**************************************************************************\n";
	cout << "Thanks for the Reservation. Following Seats have been booked successfully:\n\n";
	string dispafsales; //Displays Description of Tickets after selling them
	skr.open("khi-skr.dat");
	cout << "***********************************************************************\n";
	cout << "Confirmed Ticket Karachi - Sukkur (KHI-SKR)\n";
	cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
	cout << "***********************************************************************\n";
	while (getline(skr, dispafsales))
	{
		cout << dispafsales << '\n';
	}
	skr.close();
	int tfare; //Total Fare

	tfare = i * 800;
	cout << "***********************************************************************\n";
	cout << "Total Fare : " << i << " x 800                               =  " << tfare << endl;
	cout << "***********************************************************************\n";
	cout << "\n\nReserved by "<<resdby <<" at "<<currentDateTime()<<endl<<endl;
	system("pause"); mmenu();

}

void khihydres() {
		
	system("cls");
	cout << "Welcome to the Reservation System for Karachi - Hyderabad Route\n\n";

	fstream hyd;
	int i = 1;
	cout << "How many Seats you want to reserve (Max 10 at a time)?: ";
	cin >> i;
	reslist r[10];
	remove("khi-hyd.dat");
	hyd.close();
	cout << "\nEnter the following information to complete the booking:\n\n";
	for (int b = 1; b <= i; b++) {
		hyd.open("khi-hyd.dat", ios::app);
		log_hyd.open("khi-hyd-log.dat", ios::app);
		cout << "Please Enter Departure Date (DD MM YYYY): ";
		cin >> r[i].dd >> r[i].mm >> r[i].yyyy;
		if (r[i].dd > 31 || r[i].mm > 12) {
			cout << "Invalid Date/Month, Please try again!\n\n";
			cout << "Please Enter Departure Date (DD MM YYYY): ";
			cin >> r[i].dd >> r[i].mm >> r[i].yyyy;
		}
		cout << "Seat No.: ";
		cin >> r[i].seat;
		if (r[i].seat > 30) {
			cout << "Only 30 Seats Available, please try again!\n\n";
			cout << "Seat No.: ";
			cin >> r[i].seat;
		}
		cout << "Passenger's Name: ";
		cin >> r[i].fname >> r[i].lname;
		insert(r[i].dd, r[i].mm, r[i].yyyy, r[i].seat);
		hyd << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		log_hyd << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		hyd.close();
		log_hyd.close();
		cout << endl;
		cout << "Reservation # " << i << endl;

	}

	//**********************************************************************************************************************
	system("cls");
	cout << "**************************************************************************\n";
	cout << "Thanks for the Reservation. Following Seats have been booked successfully:\n\n";
	string dispafsales; //Displays Description of Tickets after selling them

	cout << "***********************************************************************\n";
	cout << "Confirmed Ticket Karachi - Hyderabad (KHI-HYD)\n";
	cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
	cout << "***********************************************************************\n";
	node *disp;
	disp = START;
	while ((*disp).next != NULL) {
		cout << (*disp).seat << setw(10)  << (*disp).dd << "/" << (*disp).mm << "/" << (*disp).yyyy << endl;
		disp = (*disp).next;
	}
	cout << (*disp).seat << setw(10)  << (*disp).dd << "/" << (*disp).mm << "/" << (*disp).yyyy << endl;
	int tfare; //Total Fare

	tfare = i * 400;
	cout << "***********************************************************************\n";
	cout << "Total Fare : " << i << " x 400                               =  " << tfare << endl;
	cout << "***********************************************************************\n";
	cout << "\n\nReserved by " << resdby << " at " << currentDateTime() << endl << endl;
	system("pause"); mmenu();

}

void lhekhires() {
	system("cls");
	cout << "Welcome to the Reservation System for Lahore - Karachi Route\n\n";

	fstream khi;
	int i = 1;
	cout << "How many Seats you want to reserve (Max 10 at a time)?: ";
	cin >> i;
	res r[10];
	remove("lhe-khi.dat");
	khi.close();
	cout << "\nEnter the following information to complete the booking:\n\n";
	for (int b = 1; b <= i; b++) {
		khi.open("lhe-khi.dat", ios::app);
		log_khi.open("lhe-khi-log.dat", ios::app);
		cout << "Please Enter Departure Date (DD MM YYYY): ";
		cin >> r[i].dd >> r[i].mm >> r[i].yyyy;
		if (r[i].dd > 31 || r[i].mm > 12) {
			cout << "Invalid Date/Month, Please try again!\n\n";
			cout << "Please Enter Departure Date (DD MM YYYY): ";
			cin >> r[i].dd >> r[i].mm >> r[i].yyyy;
		}
		cout << "Seat No.: ";
		cin >> r[i].seat;
		if (r[i].seat > 30) {
			cout << "Only 30 Seats Available, please try again!\n\n";
			cout << "Seat No.: ";
			cin >> r[i].seat;
		}
		cout << "Passenger's Name: ";
		cin >> r[i].fname >> r[i].lname;
		khi << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		log_khi << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		khi.close();
		log_khi.close();
		cout << endl;
		cout << "Reservation # " << i << endl;

	}
	//**********************************************************************************************************************
	system("cls");
	cout << "**************************************************************************\n";
	cout << "Thanks for the Reservation. Following Seats have been booked successfully:\n\n";
	string dispafsales; //Displays Description of Tickets after selling them
	khi.open("lhe-khi.dat");
	cout << "***********************************************************************\n";
	cout << "Confirmed Ticket Lahore - Karachi (LHE-KHI)\n";
	cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
	cout << "***********************************************************************\n";
	while (getline(khi, dispafsales))
	{
		cout << dispafsales << '\n';
	}
	khi.close();
	int tfare; //Total Fare

	tfare = i * 3000;
	cout << "***********************************************************************\n";
	cout << "Total Fare : " << i << " x 3000                               =  " << tfare << endl;
	cout << "***********************************************************************\n";
	cout << "Press Any key to Continue.....";
	system("pause"); mmenu();

}

void lhemurres() {
	system("cls");
	cout << "Welcome to the Reservation System for Lahore - Murree Route\n\n";

	fstream mur;
	int i = 1;
	cout << "How many Seats you want to reserve (Max 10 at a time)?: ";
	cin >> i;
	res r[10];
	remove("lhe-mur.dat");
	mur.close();
	cout << "\nEnter the following information to complete the booking:\n\n";
	for (int b = 1; b <= i; b++) {
		mur.open("lhe-mur.dat", ios::app);
		log_mur.open("lhe-mur-log.dat", ios::app);
		cout << "Please Enter Departure Date (DD MM YYYY): ";
		cin >> r[i].dd >> r[i].mm >> r[i].yyyy;
		if (r[i].dd > 31 || r[i].mm > 12) {
			cout << "Invalid Date/Month, Please try again!\n\n";
			cout << "Please Enter Departure Date (DD MM YYYY): ";
			cin >> r[i].dd >> r[i].mm >> r[i].yyyy;
		}
		cout << "Seat No.: ";
		cin >> r[i].seat;
		if (r[i].seat > 30) {
			cout << "Only 30 Seats Available, please try again!\n\n";
			cout << "Seat No.: ";
			cin >> r[i].seat;
		}
		cout << "Passenger's Name: ";
		cin >> r[i].fname >> r[i].lname;
		mur << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		log_mur << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		mur.close();
		log_mur.close();
		cout << endl;
		cout << "Reservation # " << i << endl;
	}
	//**********************************************************************************************************************
	system("cls");
	cout << "**************************************************************************\n";
	cout << "Thanks for the Reservation. Following Seats have been booked successfully:\n\n";
	string dispafsales; //Displays Description of Tickets after selling them
	mur.open("lhe-mur.dat");
	cout << "***********************************************************************\n";
	cout << "Confirmed Ticket Lahore - Murree (LHE-MUR)\n";
	cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
	cout << "***********************************************************************\n";
	while (getline(mur, dispafsales))
	{
		cout << dispafsales << '\n';
	}
	mur.close();
	int tfare; //Total Fare

	tfare = i * 1600;
	cout << "***********************************************************************\n";
	cout << "Total Fare : " << i << " x 1600                               =  " << tfare << endl;
	cout << "***********************************************************************\n";
	cout << "Press Any key to Continue.....";
	system("pause"); mmenu();

}

void khiskrrec() {
system("cls");
cout << "***********************************************************************\n";
cout << "Confirmed Ticket Karachi - Sukkur (KHI-SKR)\n";
cout << "Bookings Information\n";
cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
cout << "***********************************************************************\n";
string recordskr;
ifstream recordfile;
recordfile.open("khi-skr-log.dat");
while (getline(recordfile, recordskr)) 
{
cout << recordskr << '\n';
}
recordfile.close();
cout << "Press Any key to Continue.....";
system("pause"); mmenu();

}

void lhehydrec() {
system("cls");
cout << "***********************************************************************\n";
cout << "Confirmed Ticket Lahore - Faisalabad (khi-hyd)\n";
cout << "Bookings Information\n";
cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
cout << "***********************************************************************\n";
string recordhyd;
ifstream recordfile;
recordfile.open("khi-hyd-log.dat");
while (getline(recordfile, recordhyd))
{
cout << recordhyd << '\n';
}
recordfile.close();
cout << "Press Any key to Continue.....";
system("pause"); mmenu();

}

void lhemurrec() {
system("cls");
cout << "***********************************************************************\n";
cout << "Confirmed Ticket Lahore - Murree (LHE-MUR)\n";
cout << "Bookings Information\n";
cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
cout << "***********************************************************************\n"; 
string recordmur;
ifstream recordfile;
recordfile.open("lhe-mur-log.dat");
while (getline(recordfile, recordmur))
{
cout << recordmur << '\n';
}
recordfile.close();
cout << "Press Any key to Continue.....";
system("pause"); mmenu();

}

void lhekhirec() {
system("cls");
cout << "***********************************************************************\n";
cout << "Confirmed Ticket Lahore - Karachi (LHE-KHI)\n";
cout << "Bookings Information\n";
cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
cout << "***********************************************************************\n";
string recordkhi;
ifstream recordfile;
recordfile.open("lhe-khi-log.dat");
while (getline(recordfile, recordkhi))
{
cout << recordkhi << '\n';
}
recordfile.close();
cout << "Press Any key to Continue.....";
system("pause"); mmenu();

} 