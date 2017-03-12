//------------------------------
//		Name	Daniel Berumen
//		id		891954653
//------------------------------
#ifndef PatientInfo_h
#define PatientInfo_h

#include<iostream>
#include<string>
#include<fstream>
#include"Date.h"
using namespace std;
class Patient
{
	friend ostream &operator<<(ostream &, const Patient &);
private:
	char firstname[15];
	int ID;
	char lastname[15];
	Date birthdate;
	int primarydocID;
public:
	Patient(int x, const char * y, const char * z,Date b, int doc);
	Patient()
	{	}

	Patient & setID(int x)
	{
		ID = x;
		return(*this);
	}
	Patient & setfirstname(const char * y)
	{
		strncpy_s(firstname,y,14);
		return(*this);
	}
	Patient & setlastname(const char * z)
	{
		strncpy_s(lastname, z, 14);
		return(*this);
	}
	Patient & setbirthdate(Date b)
	{
		birthdate = b;
		return(*this);
	}
	Patient & setprimarydocID(int doc)
	{
		primarydocID = doc;
		return(*this);
	}
	void displaymenu()
	{
		cout <<"---------- Menu Options --------------\n";
		cout <<"N: new patient\n";
		cout <<"R: returning patient\n";
		cout <<"O: check out\n";
		cout <<"I: patient information\n";
		cout <<"P: print\n";
		cout <<"Q: quit\n";
		cout <<"--------------------------------------\n";
		cout <<"Enter menu option: ";
	}
	int getID()
	{
		return ID;
	}
	const char * getFirstname()
	{
		return firstname;
	}
	const char * getLastname()
	{
		return lastname;
	}
	Date getBirthdate()
	{
		return birthdate;
	}
	int getDoctorID()
	{
		return primarydocID;
	}
};

Patient:: Patient(int x, const char * y, const char * z ,Date b, int doc)
{
	setID(x);
	setfirstname(y);
	setlastname(z);
	setbirthdate(b);
	setprimarydocID(doc);
}

#endif // !PatientInfo_h
