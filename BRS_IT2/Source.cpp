//Bus Reservation System Source Code by
//Anas Waseem, Hamza Raheel, Taaha Khan, Haider Chaudhry, Husnain Ahmed
//ALL REC FUNCTIONS ARE UNDER CONSTRUCTION AND WILL BE COMPLETED SOON!!!
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;  //Header Files End
					  //and Function Declaration Starts
void bookings();  // Refer T. Manual Page 2-3 for these 4 functions
void records();
void busesinfo();
void mmenu();
//LHE-ISB
void lheisbres(); //For all the res functions, refer page 4-6
				  //void lheisbrec(); Under Construction :(  For all the rec Functions, refer pages after 5 on T. Manual
				  //LHE-FSD
void lhefsdres();
void lhefsdrec(); 
//LHE-MUR
void lhemurres(); //Refer T. Manual
				  //void lhemurrec(); Under Construction
				  //LHE-KHI
void lhekhires(); //Refer T. Manual
				  //void lhekhirec(); //Under Construction
void lheisbrec();

fstream log_isb;
fstream log_fsd;
fstream log_mur;
fstream log_khi;
//Structure for Reservation
struct res { //Reservation Structure
	int seat;
	char fname[15];
	char lname[15];
	int dd, mm, yyyy;
};

int n = 0; //Wrong Pass Variable

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
	if (username == "anas" && password == 5858)
		mmenu();
	else if (username == "hamza"&& password == 6868)
		mmenu();
	else if (username == "taha"&& password == 7878)
		mmenu();
	else if (username == "husnain"&&password == 8888)
		mmenu();
	else if (username == "haider"&&password == 9898)
		mmenu();
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

void mmenu() //Refer Page 1 on T. Manual
{
	system("cls");
	cout << "*********************************************************************************\n"
		<< "*           WELCOME TO BS IT - 2 BUS RESERVATION SYSTEM MAIN MENU               *\n"
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
		<< "1. Lahore to Islamabad (Rs. 800/person)\n"
		<< "2. Lahore to Faisalabad(Rs. 400/person)\n"
		<< "3. Lahore to Murree (Rs.1600/person)\n"
		<< "4. Lahore to Karachi (Rs.3000/person)\n"
		<< "5. Return to Main Menu\n\n"
		<< "Enter Choice: ";
	int option;
	cin >> option;

	if (option == 1)
		lheisbres();
	else if (option == 2)
		lhefsdres();
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
		<< "1. Lahore to Islamabad (Rs. 800/person)\n"
		<< "2. Lahore to Faisalabad(Rs. 400/person)\n"
		<< "3. Lahore to Murree(Rs. 1600/person)\n"
		<< "4. Lahore to Karachi(Rs. 3000/person)\n"
		<< "5. Return to Main Menu\n\n"
		<< "Enter Choice: ";
	int option;
	cin >> option;

	if (option == 1)  //Under Construction all rec functions
		lheisbrec();
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
		<< "BUS-001     Lahore to Islamabad          08:00 \n"
		<< "BUS-002     Lahore to Faisalabad         10:30 \n"
		<< "BUS-003     Lahore to Murree             23:00 \n"
		<< "BUS-004     Lahore to Karachi            19:45 \n"
		<< "\nWe have 1 Bus for each route once in a day! Copyrights (c) 2015 - BS IT_2";
	cout << "Press Any key to Continue.....";
	system("pause"); mmenu();
}
//*****************ALL REC FUNCTIONS ARE DEFINED ON TECHNICAL MANUAL************************************************************
void lheisbres() {
	system("cls");
	cout << "Welcome to the Reservation System for Lahore - Islamabad Route\n\n";

	fstream isb;
	int i = 1;
	cout << "How many Seats you want to reserve (Max 10 at a time)?: ";
	cin >> i;
	res r[10];
	remove("lhe-isb.dat");
	isb.close();
	cout << "\nEnter the following information to complete the booking:\n\n";
	for (int b = 1; b <= i; b++) {
		isb.open("lhe-isb.dat", ios::app);
		log_isb.open("lhe-isb-log.dat", ios::app);
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
		isb << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		log_isb << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		isb.close();
		log_isb.close();
		cout << endl;
		cout << "Reservation # " << i << endl;

	}
	//**********************************************************************************************************************
	system("cls");
	cout << "**************************************************************************\n";
	cout << "Thanks for the Reservation. Following Seats have been booked successfully:\n\n";
	string dispafsales; //Displays Description of Tickets after selling them
	isb.open("lhe-isb.dat");
	cout << "***********************************************************************\n";
	cout << "Confirmed Ticket Lahore - Islamabad (LHE-ISB)\n";
	cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
	cout << "***********************************************************************\n";
	while (getline(isb, dispafsales))
	{
		cout << dispafsales << '\n';
	}
	isb.close();
	int tfare; //Total Fare

	tfare = i * 800;
	cout << "***********************************************************************\n";
	cout << "Total Fare : " << i << " x 800                               =  " << tfare << endl;
	cout << "***********************************************************************\n";
	cout << "Press Any key to Continue.....";
	system("pause"); mmenu();

}

void lhefsdres() {
	system("cls");
	cout << "Welcome to the Reservation System for Lahore - Faisalabad Route\n\n";

	fstream fsd;
	int i = 1;
	cout << "How many Seats you want to reserve (Max 10 at a time)?: ";
	cin >> i;
	res r[10];
	remove("lhe-fsd.dat");
	fsd.close();
	cout << "\nEnter the following information to complete the booking:\n\n";
	for (int b = 1; b <= i; b++) {
		fsd.open("lhe-fsd.dat", ios::app);
		log_fsd.open("lhe-fsd-log.dat", ios::app);
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
		fsd << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		log_fsd << r[i].seat << setw(25) << r[i].fname << " " << r[i].lname << setw(25) << r[i].dd << "/" << r[i].mm << "/" << r[i].yyyy << endl;
		fsd.close();
		log_fsd.close();
		cout << endl;
		cout << "Reservation # " << i << endl;

	}
	//**********************************************************************************************************************
	system("cls");
	cout << "**************************************************************************\n";
	cout << "Thanks for the Reservation. Following Seats have been booked successfully:\n\n";
	string dispafsales; //Displays Description of Tickets after selling them
	fsd.open("lhe-fsd.dat");
	cout << "***********************************************************************\n";
	cout << "Confirmed Ticket Lahore - Faisalabad (LHE-FSD)\n";
	cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
	cout << "***********************************************************************\n";
	while (getline(fsd, dispafsales))
	{
		cout << dispafsales << '\n';
	}
	fsd.close();
	int tfare; //Total Fare

	tfare = i * 400;
	cout << "***********************************************************************\n";
	cout << "Total Fare : " << i << " x 400                               =  " << tfare << endl;
	cout << "***********************************************************************\n";
	cout << "Press Any key to Continue.....";
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

void lheisbrec() {
system("cls");
cout << "***********************************************************************\n";
cout << "Confirmed Ticket Lahore - Islamabad (LHE-ISB)\n";
cout << "Bookings Information\n";
cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
cout << "***********************************************************************\n";
string recordisb;
ifstream recordfile;
recordfile.open("lhe-isb-log.dat");
while (getline(recordfile, recordisb)) 
{
cout << recordisb << '\n';
}
recordfile.close();
cout << "Press Any key to Continue.....";
system("pause"); mmenu();

}

void lhefsdrec() {
system("cls");
cout << "***********************************************************************\n";
cout << "Confirmed Ticket Lahore - Faisalabad (LHE-FSD)\n";
cout << "Bookings Information\n";
cout << "Seat No." << "          " << "Passengers' Name(s)" << "               " << "Departure Date" << endl;
cout << "***********************************************************************\n";
string recordfsd;
ifstream recordfile;
recordfile.open("lhe-fsd-log.dat");
while (getline(recordfile, recordfsd))
{
cout << recordfsd << '\n';
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