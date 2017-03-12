//------------------------------
//		Name	Daniel Berumen
//		id		891954653
//------------------------------
#include<iostream>
#include<string>
#include"Date.h"
#include"PatientInfo.h"

using namespace std;

int main()
{
	int patientcount = 0;
	Patient CheckedInPatients[100] = {};//array for patients currently checked in
	int checkedIn = 0;//counter for how many patients are checked in
	Patient Allpatients[100] = {};
	char f[100], l[100];
	const char *fname, *thatfname;
	const char *lname, *thatlname;
	int id, doc = 0, x = 0, y = 0, thatid, thatdoc;
	int month = 1, day = 1, year = 1900;
	char MenuOption, confirmquit;
	Date bday(month, day, year), thatbday;
	Patient alpha(id = 0, fname = "John", lname = "Doe", bday, doc);
	ofstream myfile;
	ifstream myfiler;
	myfiler.open("Current_Patients.txt", ios::binary| ios:: in);
	myfiler.read((char *)&patientcount, 4);
	if(patientcount > 0)
	{
	for(int i=0; i < patientcount; i++)
		{
			myfiler >> f;
			Allpatients[i].setID(i);
			Allpatients[i].setfirstname(f);
			myfiler >> l;
			Allpatients[i].setlastname(l);
			myfiler.read((char *)&month, 4);
			myfiler.read((char *)&day,4);
			myfiler.read((char *)&year,sizeof(year));
			Date bday(month,day,year);
			Allpatients[i].setbirthdate(bday);
			myfiler.read((char *)&doc, 4);
			Allpatients[i].setprimarydocID(doc);
		}
	}
	cout << "Todays Date (##/##/####): ";
	cin >> month; cin.ignore();
	cin >> day; cin.ignore();
	cin >> year; cin.ignore();
	Date todaysdate(month, day, year);
	alpha.displaymenu();
	cin >> MenuOption;
	myfile.open("Current_Patients.txt",ios::binary|ios::out);
	do
	{
		switch (MenuOption)
		{
				case 'n':case'N':
			{
				doc = (rand() % 5) + 1;
				id = patientcount;
				Allpatients[id].setID(id);
				cout<<"Enter first name: ";
				cin >> f;
				x = strlen(f);
				if (x > 14)
				{
					f[14] = '\0';
				}
				cout << "Enter last name: ";cin.ignore();
				cin >> l;
				y = strlen(l);
				if (y > 14)
				{
					l[14] = '\0';
				}
				cout << "Enter your birthdate ##/##/####: ";
				cin >> month;cin.ignore();
				cin >> day; cin.ignore();
				cin >> year;
				Date bday(month, day, year);
				fname = f;
				lname = l;
				
				Allpatients[id].setfirstname(fname);
				Allpatients[id].setlastname(lname);
				Allpatients[id].setbirthdate(bday);
				Allpatients[id].setprimarydocID(doc);
				patientcount++;
				CheckedInPatients[checkedIn].setID(id);
				CheckedInPatients[checkedIn].setfirstname(fname);
				CheckedInPatients[checkedIn].setlastname(lname);
				CheckedInPatients[checkedIn].setbirthdate(bday);
				CheckedInPatients[checkedIn].setprimarydocID(doc);
				checkedIn++;
				alpha.displaymenu();
				cin >> MenuOption;
			}break;

		case 'p':case'P':
			{
				for(int a=0; a < checkedIn; a++)
				{
					cout<<"Patient ID: ";
					cout<<CheckedInPatients[a].getID();
					cout<<endl;
					cout<<"Patient Name: ";
					cout<<CheckedInPatients[a].getFirstname()<<' ';
					cout<<CheckedInPatients[a].getLastname()<<endl;
					cout<<"Patient birthdate: "<<CheckedInPatients[a].getBirthdate()<<endl;
					cout<<"Patients Doctor: "<<CheckedInPatients[a].getDoctorID()<<endl;
					cout<<"--------------------------------\n";
				}
				alpha.displaymenu();
				cin>> MenuOption;
			}
			break;

		case 'r': case 'R':
			{
				
				cout << "Enter your patient ID: ";
				cin >> id;
				thatid = Allpatients[id].getID();
				thatbday = Allpatients[id].getBirthdate();
				thatdoc = Allpatients[id].getDoctorID();
				thatfname = Allpatients[id].getFirstname();
				thatlname = Allpatients[id].getLastname();
				if(id == thatid)
				{
					CheckedInPatients[checkedIn].setID(thatid);
					CheckedInPatients[checkedIn].setfirstname(thatfname);
					CheckedInPatients[checkedIn].setlastname(thatlname);
					CheckedInPatients[checkedIn].setbirthdate(thatbday);
					CheckedInPatients[checkedIn].setprimarydocID(thatdoc);
					checkedIn++;
				}
				else
				{
					cout<<"invalid id\n";
				}

				alpha.displaymenu();
				cin >> MenuOption;
			}
			break;

		case 'o':case 'O':
			{
				cout<< "Enter ID: ";
				cin >> id;
				int outpatient=0, checkoutid  = 1000;
				while(id != checkoutid)
				{
					checkoutid = CheckedInPatients[outpatient].getID();
					outpatient++;
				}
				outpatient -= 1;
				for(outpatient; outpatient < checkedIn; outpatient++)
				{
					int removeid, removedoc;
					Date removebday;
					const char *removefname, *removelname;
					removeid = CheckedInPatients[outpatient+1].getID();
					removedoc = CheckedInPatients[outpatient+1].getDoctorID();
					removebday = CheckedInPatients[outpatient+1].getBirthdate();
					removefname = CheckedInPatients[outpatient+1].getFirstname();
					removelname = CheckedInPatients[outpatient+1].getLastname();
					CheckedInPatients[outpatient].setID(removeid);
					CheckedInPatients[outpatient].setbirthdate(removebday);
					CheckedInPatients[outpatient].setprimarydocID(removedoc);
					CheckedInPatients[outpatient].setfirstname(removefname);
					CheckedInPatients[outpatient].setlastname(removelname);
				}
				checkedIn--;
				alpha.displaymenu();
				cin >> MenuOption;
			}
			break;

		case 'i':case 'I':
			{
				cout << "Enter patient ID number: ";
				cin >> id;
				cout <<"Patient Name: " << Allpatients[id].getFirstname();
				cout << ' ' <<Allpatients[id].getLastname() << endl;
				cout << "Patients Birthday: " << Allpatients[id].getBirthdate() << endl;
				cout << "Patients Doctor Id: " << Allpatients[id].getDoctorID() << endl;
				alpha.displaymenu();
				cin >> MenuOption;
			}
			break;
		default:
			{
				cout << "invalid input\n";
				alpha.displaymenu();
				cin >> MenuOption;
			}
			break;
		case 'q':
			{
				if (checkedIn != 0)
				{
					cout << "Error. Patients still checked in \n";
					alpha.displaymenu();
					cin >> MenuOption;
				}
				else
				{
					myfile.write((char *)&patientcount, sizeof(patientcount));
					for(int i=0; i<patientcount; i++)
					{
						myfile << Allpatients[i].getFirstname() << ' ';
						myfile << Allpatients[i].getLastname();
						bday = Allpatients[i].getBirthdate();
						day = bday.getDay();
						month = bday.getMonth();
						year = bday.getYear();
						myfile.write((char *)&month, sizeof(month));
						myfile.write((char *)&day, sizeof(day));
						myfile.write((char *)&year, sizeof(year));
						doc = Allpatients[i].getDoctorID();
						myfile.write((char *)&doc,sizeof(doc));
					}
					cout << "Confirm quit(y/n)? ";
					cin >> confirmquit;
				}
			}
			break;
		}
	}
	while (confirmquit != 'y');
	myfile.close();

	system("pause");
	return 0;
}
