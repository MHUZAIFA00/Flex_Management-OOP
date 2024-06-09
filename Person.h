#pragma once
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include<iostream>
#include<cctype>
#include <algorithm>
using namespace std;
class Adimn;
class Teacher;
class Person;
class HOD;
ifstream& operator >>(ifstream& in, HOD& h);
struct Marks
{
	float OOP, DLD, LA, AP, CP, CAL, PS;
};
class Person
{
protected:
	string FirstName, LastName, Depatment, ID, ContactNo, Qualification, Address;
	string UserName, Password;
	char Gender;
public:
	Person();
	void setFirstName();
	void setLastName();
	void setDepatment();
	void setContactNo();
	void setQualification();
	void setAddress();
	void setGender();
	string getFirstName();
	string getLastName();
	string getDepatment();
	string getContactNo();
	string getQualification();
	string getAddress();
	char getGender();
	virtual void setdata() = 0;
	friend class Admin;
};
class Teacher :public Person
{
protected:
	bool ch;
	Teacher* t;
	string sub;
	int salary;
	void setSecurity();
	void setsalary();
	void setID(const int);
	void genratetimetable(int);
	void setsub();
	void operator ~();
public:
	int signin();
	static void setcount();
	static int CountTeacher;
	string getID();
	Teacher();
	void setdata();
	void updateData();
	void display();

	void menu(int);
	void viewtimetable(int);
	void markattandus(int);
	void markmarks(int);
	void grading(int);
};
class Student : public Person
{
	bool ch;
	string feeStatus;
	string bloodGroup;
	Marks marks;
	void setSecurity();
	void setMarks();
	void setbloodGroup();
	void setFeeStatus();
	void setId();
	Student* s;
	void setdata_to_s();
public:
	static void setcount();
	static int CountStudent;
	Student();
	string getID();
	void setdata();
	void updateData();
	void display();
	int signin();
	void menu(int);

	//static MyClass* operator*() {
	//	MyClass* ptr = new MyClass(10);
	//	return ptr;
	//}



	friend class HOD;
};
class Admin
{
	string userNameLogin, PasswordLogin;
	int total;
	/*Person* p;*/
	/*void main();*/
	void menu();
public:
	Admin();
	void LoginAdmin();
};
class HOD :public Teacher
{
	HOD* hod;
public:
	HOD();
	void Sign_In();
	void menu(int);
	void Student_files();
	friend ifstream& operator >>(ifstream& in, HOD& h);
};