#include "Person.h"
int Teacher::CountTeacher = 0;
int Student::CountStudent = 0;

void Teacher::setcount()
{
	ifstream fin;
	fin.open("Teachere.txt");
	if (fin.is_open())
	{
		int count = 0;
		string s;
		while (!fin.eof())
		{
			getline(fin, s);
			count++;
		}
		if (count == 1)
		{
			CountTeacher = 0;
			count = 0;
		}
		else
		{
			fin.close();
			count = count / 14;
			CountTeacher = count;
		}
	}
	else
		cout << "File Not Found for counting" << endl;
}
void Student::setcount()
{
	ifstream fin;
	fin.open("Student.txt");
	if (fin.is_open())
	{
		int count = 0;
		string s;
		while (!fin.eof())
		{
			getline(fin, s);
			count++;
		}
		fin.close();
		if (count == 1)
		{
			CountStudent = 0;
			count = 0;
		}
		else
		{
			count = count / 14;
			CountStudent = count;
		}
	}
	else
		cout << "File Not Found for counting" << endl;
}
string creating_id(string department, int count)
{
	string id;
	int n = department.length();
	if (n == 16)
	{
		id += "CS-";
		id += "\0";
	}
	else if (n == 20)
	{
		if (department[0] == 'E')
		{
			id += "EE-";
			id += "\0";
		}
		else
		{
			id += "SE-";
			id += "\0";
		}
	}
	else if (n == 15)
	{
		id += "SS-";
		id += "\0";
	}
	else
	{
		id += "B-";
		id += "\0";
	}
	if (count == 0)
	{
		id += "000";
		id += '\0';
	}
	else if (count > 0 && count < 9)
	{
		id += "00";
		id += count + 48;
		id += '\0';
	}
	else if (count < 99)
	{
		id += "0";
		int t, s;
		t = count % 10;
		s = count / 10;
		id += s + 48;
		id += t + 48;
		id += '\0';
	}
	else
	{
		int t, p = 0, control = 1, k = 1, start;
		char c;
		while (count != 0)
		{
			t = count % 10;
			count = count / 10;
			id += t + 48;
		}
		while (1)
		{
			if (id[k - 1] == '-')
				start = k;
			if (id[k] >= 48 && id[k] <= 57)
			{
				p++;
			}
			if (id[k] == '\0')
				break;
			k++;
		}
		for (int i = 0; i < p / 2; i++)
		{
			char temp;
			temp = id[start + i];
			id[start + i] = id[start + p - 1 - i];
			id[start + p - 1 - i] = temp;
		}
		id += '\0';
	}
	return id;
}
Person::Person()
{
	FirstName = LastName = Depatment = ID = ""; ContactNo = Qualification = Address = "";
	Gender = '\0';
}
Teacher::Teacher() :Person()
{
	UserName = Password = "";
	ch = 0;
}
void Person::setFirstName()
{
	cout << "Enter First Name = ";
	cin >> FirstName;
}
void Person::setLastName()
{
	cout << "Enter Last Name = ";
	cin >> LastName;
}
void Person::setDepatment()
{
	bool check = 0, c1 = 0;
	cout << "Enter Depatment in proper form by using spaces and first starting letter and letter after space must be cap_case" << endl;
	cout << "For Example = Computer Science, Software Engineering, Business, Social Sciences, Electric Engineering" << endl;
	while (check == 0)
	{
		cout << "Enter Depatment = ";
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, Depatment);
		if (Depatment.length() == 16 || Depatment.length() == 20 || Depatment.length() == 8 || Depatment.length() == 15)
		{
			if (!(Depatment[0] >= 'A' && Depatment[0] <= 'Z'))
			{
				check = 0;
				cout << "Pleas Enter First letter Captial" << endl;
				continue;
			}
			else
				check = 1;
			if (Depatment.length() != 8)
			{
				for (int k = 0; k < Depatment.length(); k++)
				{
					if (Depatment[k] == ' ')
					{
						c1 = 1;
						if (Depatment[k + 1] >= 'A' && Depatment[k + 1] <= 'Z')
						{
							check = 1;
							break;
						}
						else
						{
							check = 0;
							cout << "Please Enter first letter after space captial" << endl;
							break;
						}
					}
					else
					{
						check = 0;
					}
				}
				if (c1 == 0)
					cout << "Please Enter Space Between words";
			}
		}
		else
			cout << "Invalid Formate/Department you entered" << endl;
	}

}
void Person::setContactNo()
{
	bool check = 0;
	while (check == 0)
	{
		cout << "Enter Contact Number = ";
		cin >> ContactNo;
		check = 1;
		if (ContactNo.length() != 11)
		{
			cout << "Invalid Number " << endl;
			check = 0;
			continue;
		}
		for (int k = 0; k < ContactNo.length(); k++)
		{
			if (!(ContactNo[k] >= '0' && ContactNo[k] <= '9'))
			{
				check = 0;
				cout << "Use Invalid Digits " << endl;
				break;
			}
		}
	}
}
void Person::setQualification()
{
	cout << "Enter Your Qualification = ";
	cin >> Qualification;
}
void Person::setAddress()
{
	cout << "Enter Your Address = ";
	cin >> Address;
}
void Person::setGender()
{
	bool check = 0;
	while (check == 0)
	{
		cout << "Enter your Gender = ";
		cin >> Gender;
		check = 1;
		if (!(Gender == 'M' || Gender == 'F' || Gender == 'f' || Gender == 'm'))
		{
			check = 0;
			cout << "Invalid Gender we have only 2 Genders F/M" << endl;
		}
	}
}
string Person::getFirstName()
{
	return FirstName;
}
string Person::getLastName()
{
	return LastName;
}
string Person::getDepatment()
{
	return Depatment;
}
string Person::getContactNo()
{
	return ContactNo;
}
string Person::getQualification()
{
	return Qualification;
}
string Person::getAddress()
{
	return Address;
}
char Person::getGender()
{
	return Gender;
}
void Teacher::setID(const int Count)
{
	ID = creating_id(Depatment, Count);
}
void Teacher::setsub()
{
	sub = "8";
	while (sub == "8")
	{
		cout << "1. AP\n2. PRO\n3. DLD\n4. MAT\n5. PKS\n6. ENG\n7. CAL\n";
		cout << "Enter your choice = ";
		cin >> sub;
		if (sub == "1")
		{
			sub = "PHY";
		}
		else if (sub == "2")
		{
			sub = "PRO";
		}
		else if (sub == "3")
		{
			sub = "DLD";
		}
		else if (sub == "4")
		{
			sub = "MAT";
		}
		else if (sub == "5")
		{
			sub = "PKS";
		}
		else if (sub == "6")
		{
			sub = "ENG";
		}
		else if (sub == "7")
		{
			sub = "CAL";
		}
		else
		{
			cout << "You enter invalid command" << endl;
			cout << "Try again" << endl;
			sub = "8";
		}
	}

}
string Teacher::getID()
{
	return ID;
}
void Teacher::setSecurity()
{
	bool check = 0;
	cout << endl << endl << "Please Enter User Name According to following rules" << endl;
	cout << "1. The numbere of chracters of User name must be grater then 8 and less then 30" << endl;
	cout << "2. Spaces are not allowed" << endl;
	cout << "3. Not use any special character" << endl;
	cout << "  3.1) You only allowed to use characters, digits and '@' sign" << endl;
	cout << "  3.2) You can not use digits at starting of the name" << endl;
	cout << "  3.3) Use '_' insted of space" << endl;
	cout << endl << "Enter User Name = ";
	while (check == 0)
	{
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, UserName);
		if (UserName.length() >= 8 && UserName.length() <= 30)
			check = 1;
		else
		{
			cout << "User name's length must be in limit given above = " << endl;
			cout << "Enter User Name Again = ";
			check = 0;
			continue;
		}
		if (UserName[0] >= '0' && UserName[0] <= '9')
		{
			check = 0;
			cout << "You are not allowed to enter digits at starting of the user name" << endl;
			cout << "Enter User Name Again = ";
			continue;
		}
		for (int k = 0; k < UserName.length(); k++)
		{
			if ((UserName[k] >= 'A' && UserName[k] <= 'Z') || (UserName[k] >= 'a' && UserName[k] <= 'z') || (UserName[k] >= '0' && UserName[k] <= '9') || UserName[k] == '@' || UserName[k] == '_')
			{
				check = 1;
			}
			else
			{
				check = 0;
				break;
			}
		}
		if (check == 0)
		{
			cout << "You use chracters other then allowed" << endl;
			cout << "Enter User Name Again = ";
		}
	}
	check = 0;
	system("cls");
	cout << endl << "Set your password = ";
	while (check == 0)
	{
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, Password);
		if (Password.length() < 8)
		{
			cout << "Your password is too short" << endl;
			cout << "Please enter again = ";
			check = 0;
			continue;
		}
		check = 0;
		for (int k = 0; k < Password.length(); k++)
		{
			if ((Password[k] >= 32 && Password[k] <= 47) || (Password[k] >= 58 && Password[k] <= 64) || (Password[k] >= 91 && Password[k] <= 96))
			{
				check = 1;
			}
		}
		if (check == 0)
		{
			cout << "Too week Password, use special characters to make it strong" << endl;
			cout << "Please enter again = ";
		}
	}
}
void Teacher::setsalary()
{
	int ch = 1;
	cout << "Enter Salary = ";
	while (ch)
	{
		cin >> salary;
		if (salary < 0)
		{
			cout << "Invalid Data " << endl;
			cout << "Enter Agian = ";
		}
		else if (salary < 5)
		{
			cout << "Salary is too low" << endl;
			cout << "Enter Agian = ";
		}
		else if (salary > 100000)
		{
			cout << "Salary is too High" << endl;
			cout << "Enter Agian = ";
		}
		else
			ch = 0;
	}
}
void Teacher::setdata()
{
	ofstream fout;
	setcount();
	cout << endl << "Enter Data of Teacher " << CountTeacher << endl;
	setFirstName();
	setLastName();
	setContactNo();
	setQualification();
	setAddress();
	setGender();
	setDepatment();
	setsalary();
	setsub();
	setID(CountTeacher);
	setSecurity();
	fout.open("Teachere.txt", ios::app);
	if (fout.is_open())
	{
		fout << "Data of Teacher Number = " << CountTeacher << endl;
		fout << getID() << endl;
		fout << getFirstName() << endl;
		fout << getLastName() << endl;
		fout << getContactNo() << endl;
		fout << getAddress() << endl;
		fout << getGender() << endl;
		fout << getQualification() << endl;
		fout << getDepatment() << endl;
		fout << salary << endl;
		fout << sub << endl;
		fout << UserName << endl;
		fout << Password << endl;
		fout << endl;
		fout.close();
	}
	else
		cout << "File Is not present in Folder";
	ch = 1;
	CountTeacher++;
}
void Student::setSecurity()
{
	UserName = FirstName + "_" + LastName + "@";
	Password = FirstName + "$123";
}
void Student::setbloodGroup()
{
	int n = 0;
	cout << "Chose your choice" << endl << "1. A+" << endl << "2. A" << endl << "3. B+" << endl << "4. AB+" << endl << "5. O+" << endl << "6. O-" << endl;
	cout << "Enter you choice = ";
	while (n == 0)
	{
		cin >> n;
		if (n == 1)
			bloodGroup = "A+";
		else if (n == 2)
			bloodGroup = "A";
		else if (n == 3)
			bloodGroup = "B+";
		else if (n == 4)
			bloodGroup = "AB+";
		else if (n == 5)
			bloodGroup = "O+";
		else if (n == 6)
			bloodGroup = "O-";
		else
		{
			cout << "Enter again you entered invalid command = ";
			n = 0;
		}
	}
}
void Student::setFeeStatus()
{
	int n = 0;
	cout << "Chose Fee Status" << endl << "1. Paid" << endl << "2. UnPaid" << endl << "Enter your choice = ";
	while (n == 0)
	{
		cin >> n;
		if (n == 1)
			feeStatus = "Paid";
		else if (n == 2)
			feeStatus = "UnPaid";
		else
		{
			cout << "You Enter invalid command" << endl;
			n = 0;
			cout << "Enter your choice again = ";
		}
	}
}
void Student::setMarks()
{
	cout << "Enter Marks of following subjects " << endl;
	do
	{
		cout << "Digital Logic Designing = ";
		cin >> marks.DLD;
	} while (!(marks.DLD <= 100 && marks.DLD >= 0));
	do
	{
		cout << "Linear Alagebra = ";
		cin >> marks.LA;
	} while (!(marks.LA <= 100 && marks.LA >= 0));
	do
	{
		cout << "Object Orinted Programing = ";
		cin >> marks.OOP;
	} while (!(marks.OOP <= 100 && marks.OOP >= 0));
	do
	{
		cout << "Pakistan Studies = ";
		cin >> marks.PS;
	} while (!(marks.PS <= 100 && marks.PS >= 0));
	do
	{
		cout << "Applied Physics = ";
		cin >> marks.AP;
	} while (!(marks.AP <= 100 && marks.AP >= 0));
	do
	{
		cout << "Calculus = ";
		cin >> marks.CAL;
	} while (!(marks.CAL <= 100 && marks.CAL >= 0));
	do
	{
		cout << "Communication And Presentation Skills = ";
		cin >> marks.CP;
	} while (!(marks.CP <= 100 && marks.CP >= 0));

}
void Student::setId()
{
	string id;
	string batch;
	bool ch = 1;
	while (ch)
	{
		cout << "Enter Batch of student such as \"23\" = ";
		cin >> batch;
		if (batch.length() == 2)
		{
			if (batch[0] > '0' && batch[0] <= '2')
			{
				if (batch[0] >= '0' && batch[0] <= '9')
				{
					ch = 0;
				}
				else
					cout << "Try again " << endl;
			}
			else
				cout << "Try again " << endl;
		}
		else
			cout << "Try again " << endl;
	}
	id += batch;
	int n = Depatment.length();
	if (n == 16)
	{
		id += "CS-";
		id += "\0";
	}
	else if (n == 20)
	{
		if (Depatment[0] == 'E')
		{
			id += "EE-";
			id += "\0";
		}
		else
		{
			id += "SE-";
			id += "\0";
		}
	}
	else if (n == 15)
	{
		id += "SS-";
		id += "\0";
	}
	else
	{
		id += "BB-";
		id += "\0";
	}
	if (CountStudent == 0)
	{
		id += "000";
		id += '\0';
	}
	else if (CountStudent > 0 && CountStudent < 9)
	{
		id += "00";
		id += CountStudent + 48;
		id += '\0';
	}
	else if (CountStudent < 99)
	{
		id += "0";
		int t, s;
		t = CountStudent % 10;
		s = CountStudent / 10;
		id += s + 48;
		id += t + 48;
		id += '\0';
	}
	else
	{
		int t, p = 0, control = 1, k = 1, start;
		char c;
		while (CountStudent != 0)
		{
			int count = CountStudent;
			t = count % 10;
			count = count / 10;
			id += t + 48;
		}
		while (1)
		{
			if (id[k - 1] == '-')
				start = k;
			if (id[k] >= 48 && id[k] <= 57)
			{
				p++;
			}
			if (id[k] == '\0')
				break;
			k++;
		}
		for (int i = 0; i < p / 2; i++)
		{
			char temp;
			temp = id[start + i];
			id[start + i] = id[start + p - 1 - i];
			id[start + p - 1 - i] = temp;
		}
		id += '\0';
	}
	ID = id;
	cout << endl << endl << id << endl << ID << endl;
}
string Student::getID()
{
	return ID;
}
void Student::setdata()
{
	ofstream fout;
	setcount();
	cout << endl << "Enter Data of Student " << CountStudent << endl;
	setFirstName();
	setLastName();
	setContactNo();
	setQualification();
	setAddress();
	setGender();
	setDepatment();
	//setMarks();
	setbloodGroup();
	setFeeStatus();
	setId();
	setSecurity();
	fout.open("Student.txt", ios::app);
	if (fout.is_open())
	{
		fout << "Data of Student Number = " << CountStudent << endl;
		fout << getID() << endl;
		fout << getFirstName() << endl;
		fout << getLastName() << endl;
		fout << getContactNo() << endl;
		fout << getAddress() << endl;
		fout << getGender() << endl;
		fout << getQualification() << endl;
		fout << getDepatment() << endl;
		//fout << marks.AP << endl << marks.CAL << endl << marks.CP << endl << marks.DLD << endl << marks.LA << endl << marks.OOP << endl << marks.PS << endl;
		fout << bloodGroup << endl;
		fout << feeStatus << endl;
		fout << UserName << endl;
		fout << Password << endl;
		fout << endl;
		fout.close();
	}
	else
		cout << "File Is not present in Folder";
	ch = 1;
	CountStudent++;
}
Admin::Admin()
{
	total = 0;
}
Student::Student()
{
	marks.AP = marks.CAL = marks.CP = marks.DLD = marks.LA = marks.OOP = marks.PS = 0;
	feeStatus = "";
	ch = 0;
	setcount();
}
void Admin::LoginAdmin()
{
	ifstream fin;
	string st, s;
	int i = 0;
	fin.open("Admin.txt");
	if (fin.is_open())
	{
		getline(fin, st);
		for (int k = 0, p = 0; st[k] != '\0'; k++, p++)
		{
			if (st[k] == 32 || st[k + 1] == '\0')
			{
				if (i == 0)
				{
					userNameLogin = s;
					s = "";
					i++;
				}
				else if (i == 1)
				{
					s += st[k];
					PasswordLogin = s;
					cout << s;
				}
				p = 0;
			}
			if (st[k] != 32)
				s += st[k];
		}
		cout << endl << PasswordLogin << endl;
		s = "";
		cout << "Enter User Name = ";
		while (s != "0")
		{
			cin >> s;
			if (s == userNameLogin)
			{
				cout << "Enter Password = ";
				cin >> s;
				if (s == PasswordLogin)
				{
					menu();
				}
				else
				{
					cout << "!! Password is incorect !!" << endl;
					cout << "Enter Password again and 0 to go back = ";
				}
			}
			else
			{
				cout << "!! There is no account by this user name !!" << endl;
				cout << "Enter User Name again and 0 to go back = ";
			}
		}
		fin.close();
	}
	else
		cout << "File Not found = " << endl;
}
void Admin::menu()
{
	int ch = 1;
	Student student1;
	Teacher teacher1;
	while (ch != 0)
	{
		cout << "Chose Your Command" << endl;
		cout << "0. To Go back" << endl;
		cout << "1. To Add Teacher" << endl;
		cout << "2. To Add Student" << endl;
		cout << "3. To Update student" << endl;
		cout << "4. To Update Teacher" << endl;
		cout << "5. To view all Students " << endl;
		cout << "6. To view all Teachers " << endl;
		cout << "Enter Your Choice = ";
		cin >> ch;
		if (ch == 1)
		{
			teacher1.setdata();
		}
		else if (ch == 2)
		{
			student1.setdata();
		}
		else if (ch == 3)
		{
			student1.updateData();
		}
		else if (ch == 4)
		{
			teacher1.updateData();
		}
		else if (ch == 5)
		{
			student1.display();
		}
		else if (ch == 6)
		{
			teacher1.display();
		}
	}
}
void Teacher::updateData()
{
	ifstream fin;
	setcount();
	Teacher* t;
	string s, id = " ", username;
	char c;
	int ch, up = -1;
	t = new Teacher[CountTeacher];
	fin.open("Teachere.txt");
	if (fin.is_open())
	{
		int sal;
		for (int n = 0; n < CountTeacher; n++)
		{
			fin.ignore();
			getline(fin, s);
			s = "";
			fin >> s;
			t[n].ID = s;
			fin >> s;
			t[n].FirstName = s;
			fin >> s;
			t[n].LastName = s;
			fin >> s;
			t[n].ContactNo = s;
			s = "";
			fin.ignore();
			getline(fin, s);
			t[n].Address = s;
			fin >> c;
			t[n].Gender = c;
			fin.ignore();
			getline(fin, s);
			t[n].Qualification = s;
			getline(fin, s);
			t[n].Depatment = s;
			fin >> sal;
			t[n].salary = sal;
			fin >> s;
			t[n].sub = s;
			fin >> s;
			t[n].UserName = s;
			fin.ignore();
			getline(fin, s);
			t[n].Password = s;
			getline(fin, s);
		}
		fin.close();
		cout << "1. Update by ID " << endl << "2. Update by User Name" << endl;
		cout << "Enter Your choice/Enter any other number to go back = ";
		cin >> ch;
		if (ch == 1)
		{
			cout << "Enter ID of Teacher = " << endl;
			cin >> id;
			id += '\0';
			while (up == -1)
			{
				for (int n = 0; n < CountTeacher; n++)
				{
					if (t[n].ID == id)
					{
						up = n;
						break;
					}
				}
				if (up == -1)
				{
					cout << "ID not match" << endl;
					cout << "Enter Again/Enter 0 to go back = ";
					cin >> id;
					id += '\0';
				}
			}
		}
		else if (ch == 2)
		{
			cout << "Enter user name of teachere  = ";
			string username;
			cin >> username;
			while (up == -1)
			{
				for (int n = 0; n < CountTeacher; n++)
				{
					if (t[n].UserName == username)
					{
						up = n;
						break;
					}
				}
				if (up == -1)
				{
					cout << "no user_name found" << endl;
					cout << "Enter Again/Enter 0 to go back = ";
					cin >> username;
				}
			}
		}
		else
		{
			cout << "Invalid Command" << endl;
			up = -1;
		}
		if (up != -1)
		{
			ofstream fout;
			cout << "What You want to update" << endl;
			while (ch)
			{
				cout << "1. Address" << endl << "2. Contect Number" << endl << "3. Qualification" << endl << "4. Salary " << endl;
				cout << "Enter Your Choice and enter 0 to go back = ";
				cin >> ch;
				if (ch == 1)
				{
					t[up].setAddress();
					cout << "Enter 0 to go back and 1 to update any thing again = ";
					cin >> ch;
				}
				else if (ch == 2)
				{
					t[up].setContactNo();
					cout << "Enter 0 to go back and 1 to update any thing again = ";
					cin >> ch;
				}
				else if (ch == 3)
				{
					t[up].setQualification();
					cout << "Enter 0 to go back and 1 to update any thing again = ";
					cin >> ch;
				}
				else if (ch == 4)
				{
					t[up].setsalary();
					cout << "Enter 0 to go back and 1 to update any thing again = ";
					cin >> ch;
				}
				else
				{
					cout << "Invalid command" << endl;
					cout << "Try Again" << endl;
				}
			}
			fout.open("Teachere.txt");
			if (fout.is_open())
			{
				for (int i = 0; i < CountTeacher; i++)
				{
					fout << "Data of Teacher Number = " << i << endl;
					fout << t[i].getID() << endl;
					fout << t[i].getFirstName() << endl;
					fout << t[i].getLastName() << endl;
					fout << t[i].getContactNo() << endl;
					fout << t[i].getAddress() << endl;
					fout << t[i].getGender() << endl;
					fout << t[i].getQualification() << endl;
					fout << t[i].getDepatment() << endl;
					fout << t[i].salary << endl;
					fout << t[i].sub << endl;
					fout << t[i].UserName << endl;
					fout << t[i].Password << endl;
					fout << endl;
				}
				fout.close();
			}
			else
				cout << "File not found " << endl;
		}
	}
	else
		cout << "file not found" << endl;
}
void Student::setdata_to_s()
{
	setcount();
	s = new Student[CountStudent];
	string st, id, username;
	char c;
	ifstream fin;
	fin.open("Student.txt");
	if (fin.is_open())
	{
		for (int k = 0; k < CountStudent; k++)
		{
			fin.ignore();
			getline(fin, st);
			st = "";
			fin >> st;
			s[k].ID = st;
			fin >> st;
			s[k].FirstName = st;
			fin >> st;
			s[k].LastName = st;
			fin >> st;
			s[k].ContactNo = st;
			fin.ignore();
			getline(fin, st);
			s[k].Address = st;
			fin >> c;
			s[k].Gender = c;
			fin >> st;
			s[k].Qualification = st;
			fin.ignore();
			getline(fin, st);
			s[k].Depatment = st;
			fin >> st;
			s[k].bloodGroup = st;
			fin >> st;
			s[k].feeStatus = st;
			fin >> st;
			s[k].UserName = st;
			fin.ignore();
			getline(fin, st);
			s[k].Password = st;
			getline(fin, st);
		}
		fin.close();
	}
	else
		cout << "File not found" << endl;
}
void Student::updateData()
{
	ifstream fin;
	string st, id, username;
	char c;
	int num;
	int ch, up = -1;
	setdata_to_s();
	cout << "1. Update by ID " << endl << "2. Update by User Name" << endl;
	cout << "Enter Your choice/Enter any other number to go back = ";
	cin >> ch;
	if (ch == 1)
	{
		cout << "Enter ID of Student = " << endl;
		cin >> id;
		id += '\0';
		while (up == -1)
		{
			for (int n = 0; n < CountStudent; n++)
			{
				if (s[n].ID == id)
				{
					up = n;
					break;
				}
			}
			if (up == -1)
			{
				cout << "ID not match" << endl;
				cout << "Enter Again/Enter 0 to go back = ";
				cin >> id;
				id += '\0';
			}
		}
	}
	else if (ch == 2)
	{
		cout << "Enter user name of Student  = ";
		string username;
		cin >> username;
		while (up == -1)
		{
			for (int n = 0; n < CountStudent; n++)
			{
				if (s[n].UserName == username)
				{
					up = n;
					break;
				}
			}
			if (up == -1)
			{
				cout << "no user_name found" << endl;
				cout << "Enter Again/Enter 0 to go back = ";
				cin >> username;
			}
		}
	}
	if (up != -1)
	{
		ofstream fout;
		ch = 1;
		cout << "What You want to update" << endl;
		while (ch)
		{
			cout << "1. First Name" << endl << "2. Last Name " << endl << "3. Contect Number" << endl << "4. Fee Status " << endl << "5. Address " << endl;
			cout << "Enter Your Choice = ";
			cin >> ch;
			if (ch == 1)
			{
				s[up].setFirstName();
				s[up].setSecurity();
				cout << "Enter 0 to go back and 1 to update any thing again = ";
				cin >> ch;
			}
			else if (ch == 2)
			{
				s[up].setLastName();
				s[up].setSecurity();
				cout << "Enter 0 to go back and 1 to update any thing again = ";
				cin >> ch;
			}
			else if (ch == 3)
			{
				s[up].setContactNo();
				cout << "Enter 0 to go back and 1 to update any thing again = ";
				cin >> ch;
			}
			else if (ch == 4)
			{
				s[up].setFeeStatus();
				cout << "Enter 0 to go back and 1 to update any thing again = ";
				cin >> ch;
			}
			else if (ch == 5)
			{
				s[up].setAddress();
				cout << "Enter 0 to go back and 1 to update any thing again = ";
				cin >> ch;
			}
			else
			{
				cout << "Invalid command" << endl;
				cout << "Try Again" << endl;
			}
		}
		fout.open("Student.txt");
		if (fout.is_open())
		{
			for (int i = 0; i < CountStudent; i++)
			{
				fout << "Data of Student Number = " << i << endl;
				fout << s[i].getID() << endl;
				fout << s[i].getFirstName() << endl;
				fout << s[i].getLastName() << endl;
				fout << s[i].getContactNo() << endl;
				fout << s[i].getAddress() << endl;
				fout << s[i].getGender() << endl;
				fout << s[i].getQualification() << endl;
				fout << s[i].getDepatment() << endl;
				//fout << marks.AP << endl << marks.CAL << endl << marks.CP << endl << marks.DLD << endl << marks.LA << endl << marks.OOP << endl << marks.PS << endl;
				fout << s[i].bloodGroup << endl;
				fout << s[i].feeStatus << endl;
				fout << s[i].UserName << endl;
				fout << s[i].Password << endl;
				fout << endl;
			}
			fout.close();
		}
		else
			cout << "File not found " << endl;
	}
}
void Student::display()
{
	system("cls");
	setcount();
	ifstream fin;
	string st;
	char c;
	fin.open("Student.txt");
	if (fin.is_open())
	{
		cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-All Students-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl << endl;
		for (int k = 0; k < CountStudent; k++)
		{
			getline(fin, st);
			cout << st << endl;
			fin >> st;
			cout << "ID = " << st << endl;
			fin >> st;
			cout << "Name = " << st;
			fin >> st;
			cout << st << endl;
			fin >> st;
			cout << "Contact Number = " << st << endl;
			fin.ignore();
			getline(fin, st);
			cout << "Address = " << st << endl;
			fin >> c;
			cout << "Gender = " << c << endl;
			fin >> st;
			cout << "Qualification = " << st << endl;
			fin.ignore();
			getline(fin, st);
			cout << "Depatment = " << st << endl;
			fin >> st;
			cout << "Blood Group = " << st << endl;
			fin >> st;
			cout << "FeeStatus = " << st << endl;
			fin >> st;
			cout << "User Name = " << st << endl;
			fin.ignore();
			getline(fin, st);
			cout << "Password = " << st << endl;
			getline(fin, st);
			cout << endl;
			cout << "`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`";
			cout << endl;

		}
	}
}
void Teacher:: operator ~()
{
	ifstream fin;
	string s;
	fin.open("Teachere.txt");
	if (fin.is_open())
	{
		cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-All Teachers-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl << endl;
		system("cls");
		int sal;
		char c;
		setcount();
		for (int n = 0; n < CountTeacher; n++)
		{
			cout << endl;
			getline(fin, s);
			cout << s << endl;
			fin >> s;
			cout << "ID = " << s << endl;
			fin >> s;
			cout << "Name = " << s << " ";
			fin >> s;
			cout << s << endl;
			fin >> s;
			cout << "Contact Number = " << s << endl;
			fin.ignore();
			getline(fin, s);
			cout << "Address = " << s << endl;
			fin >> c;
			cout << "Gender = " << c << endl;
			fin.ignore();
			getline(fin, s);
			cout << "Qualification = " << s << endl;
			getline(fin, s);
			cout << "Depatment = " << s << endl;
			fin >> sal;
			cout << "Salary = " << sal << endl;
			fin >> s;
			cout << "Subject = " << s << endl;
			fin >> s;
			cout << "User Name = " << s << endl;
			fin.ignore();
			getline(fin, s);
			cout << "Password = " << s << endl;
			getline(fin, s);
			cout << endl;
			cout << "`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`";
			cout << endl;
		}
		fin.close();
	}
	else
		cout << "File Not found" << endl;
}
void Teacher::display()
{
	Teacher t;
	~t;
}
int Teacher::signin()
{
	string username, password;
	setcount();
	int ind = -1;
	cout << "Enter User Name = ";
	cin >> username;
	ifstream fin;
	string s;
	delete t;
	t = 0;
	t = new Teacher[CountTeacher];
	fin.open("Teachere.txt");
	if (fin.is_open())
	{
		char c;
		int sal;
		for (int n = 0; n < CountTeacher; n++)
		{
			fin.ignore();
			getline(fin, s);
			s = "";
			fin >> s;
			t[n].ID = s;
			fin >> s;
			t[n].FirstName = s;
			fin >> s;
			t[n].LastName = s;
			fin >> s;
			t[n].ContactNo = s;
			s = "";
			fin.ignore();
			getline(fin, s);
			t[n].Address = s;
			fin >> c;
			t[n].Gender = c;
			fin.ignore();
			getline(fin, s);
			t[n].Qualification = s;
			getline(fin, s);
			t[n].Depatment = s;
			fin >> sal;
			t[n].salary = sal;
			fin >> s;
			t[n].sub = s;
			fin >> s;
			t[n].UserName = s;
			fin.ignore();
			getline(fin, s);
			t[n].Password = s;
			getline(fin, s);
		}
		fin.close();
	}
	else
		cout << "File not found" << endl;
	int trye = 0;
	while (ind == -1)
	{
		for (int k = 0; k < CountTeacher; k++)
		{
			cout << t[k].UserName << endl;
			if (username == t[k].UserName)
			{
				ind = k;
				break;
			}
		}
		if (ind == -1)
		{
			if (trye == 4)
				break;
			trye++;
			cout << "No Account found of this name" << endl;
			cout << "Try Again = ";
			cin >> username;
		}
	}
	if (ind != -1)
	{
		cout << "Enter Password = ";
		cin.ignore();
		getline(cin, password);
		if (password == t[ind].Password)
		{
			menu(ind);
		}
		else
			cout << "Password is incorrect" << endl;
	}
	return 0;
}
void Teacher::menu(int ind)
{
	int ch;
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|| Teacher Mode ||_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
	cout << "1. Time Table" << endl << "2. Assign Marks" << endl << "3. Mark Attendance" << endl << "4. Mark Grading" << endl;
	cout << "Enter Your choice = ";
	cin >> ch;
	if (ch == 1)
	{
		string st;
		int size;
		st = t[ind].ID;
		size = st.length();
		st[size - 1] = '_';
		st += "timetable.txt";
		ifstream fin;
		fin.open(st);
		if (!fin.is_open())
			genratetimetable(ind);
		viewtimetable(ind);
	}
	else if (ch == 2)
	{
		markmarks(ind);
	}
	else if (ch == 3)
	{
		markattandus(ind);
	}
	else if (ch == 4)
	{
		grading(ind);
	}
}
void Teacher::viewtimetable(int ind)
{
	string st;
	int size;
	st = t[ind].ID;
	size = st.length();
	st[size - 1] = '_';
	st += "timetable.txt";
	ifstream fin;
	fin.open(st);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, st);
			cout << st << endl;
		}
	}
	else
		cout << "File not found" << endl;

}
void Teacher::genratetimetable(int ind)
{
	int time = 0;
	string arr[6][10];
	bool ar[6][10];
	for (int k = 0; k < 6; k++)
	{
		for (int i = 0; i < 10; i++)
		{
			arr[k][i] = "0";
			ar[k][i] = 0;
		}
	}
	string* id;
	int* i;
	int ij;
	string st;
	ifstream fin;
	int b2, b1, b4, b3;
	b2 = b1 = b4 = b3 = 0;
	Student::setcount();
	id = new string[Student::CountStudent];
	i = new int[Student::CountStudent];
	for (int k = 0; k < Student::CountStudent; k++)
	{
		i[k] = 0;
	}
	fin.open("Student.txt");
	if (fin.is_open())
	{
		char c;
		for (int k = 0; k < Student::CountStudent; k++)
		{
			fin.ignore();
			getline(fin, st);
			st = "";
			fin >> st;
			id[k] = st;
			fin >> st;
			fin >> st;
			fin >> st;
			fin.ignore();
			getline(fin, st);
			fin >> c;
			fin >> st;
			fin.ignore();
			getline(fin, st);
			fin >> st;
			fin >> st;
			fin >> st;
			fin.ignore();
			getline(fin, st);
			getline(fin, st);
			st = id[k];
			if (t[ind].ID[0] == st[2])
			{
				if (st[2] = 'B')
				{
					ij = st[1] - 48;
					ij = ij + ((st[0] - 48) * 10);
					i[k] = ij;
				}
				else if (st[3] == t[ind].ID[1])
				{
					ij = st[1] - 48;
					ij = ij + ((st[0] - 48) * 10);
					i[k] = ij;
				}
			}
		}
		fin.close();
		int max = i[0];
		for (int k = 1; k < Student::CountStudent; k++)
		{
			if (max < i[k])
				max = i[k];
		}
		for (int k = 0; k < Student::CountStudent; k++)
		{
			if (i[k] < max - 3 && i[k] != 0)
				b1++;
			else if (i[k] == max - 2)
				b2++;
			else if (i[k] == max - 1)
				b3++;
			else if (i[k] == max)
				b4++;
		}
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0)
		{
			cout << "Students not found of this teachers department" << endl;
		}
		else
		{
			ofstream fout;
			int size = 0;
			Teacher::setcount();
			ifstream fin;
			int j = -1;
			int k = -1;
			for (int i = 0; i < CountTeacher; i++)
			{
				st = t[i].ID;
				size = st.length();
				st[size - 1] = '_';
				st += "timetable.txt";
				fin.open(st);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						string temp;
						fin >> temp;
						if (temp == "Monday")
							j = 0;
						else if (temp == "Tuesday")
							j = 1;
						else if (temp == "Wednesday")
							j = 2;
						else if (temp == "Thursday")
							j = 3;
						else if (temp == "Friday")
							j = 4;
						else if (temp == "Saturday")
							j = 5;
						fin >> temp;
						fin >> temp;
						k = temp[0] - 48;
						if (k >= 0)
						{
							ar[j][k] = 1;
						}
						getline(fin, temp);
						temp = "";
					}
					fin.close();
					j = -1; k = -1;
				}
			}
			for (int k = 0; k < 6; k++)
			{
				for (int i = 0; i < 10; i++)
				{
					cout << ar[k][i];
				}
				cout << endl;
			}
			st = t[ind].ID;
			size = st.length();
			st[size - 1] = '_';
			st += "timetable.txt";
			fout.open(st);
			time = 0;
			int hours = 0;
			if (b1 != 0)
				hours += 2;
			if (b2 != 0)
				hours += 2;
			if (b3 != 0)
				hours += 2;
			if (b4 != 0)
				hours += 2;
			if (hours == 2)
				hours = 3;
			if (hours == 8)
				hours = 7;
			if (fout.is_open())
			{
				int j = rand() % 4 + 1;
				cout << j << endl;
				for (int k = 0; k < 6; k++)
				{
					for (int i = 0; i < 10; i++)
					{
						if (time < hours)
						{
							if (ar[k][i] == 0)
							{
								if (b1 != 0 && j == 1)
								{
									arr[k][i] = ((max - 3) / 10) + 48;
									arr[k][i] += ((max - 3) % 10) + 48;
									arr[k][i] += "-";
									arr[k][i] += t[ind].sub;
									time++;
									j = 2;
									break;
								}
								if (b2 != 0 && j == 2)
								{
									arr[k][i] = ((max - 2) / 10) + 48;
									arr[k][i] += ((max - 2) % 10) + 48;
									arr[k][i] += "-";
									arr[k][i] += t[ind].sub;
									time++;
									j = 3;
									continue;
								}
								if (b3 != 0 && j == 3)
								{
									arr[k][i] = ((max - 1) / 10) + 48;
									arr[k][i] += ((max - 1) % 10) + 48;
									arr[k][i] += "-";
									arr[k][i] += t[ind].sub;
									time++;
									j = 4;
									break;
								}
								if (b4 != 0 && j == 4)
								{
									arr[k][i] = ((max) / 10) + 48;
									arr[k][i] += ((max) % 10) + 48;
									arr[k][i] += "-";
									arr[k][i] += t[ind].sub;
									time++;
									j = 1;
									break;
								}
								while (1)
								{
									j = rand() % 4 + 1;
									if (j == 1)
									{
										if (b1 != 0)
											break;
									}
									else if (j == 2)
									{
										if (b2 != 0)
											break;
									}
									else if (j == 3)
									{
										if (b3 != 0)
											break;
									}
									else if (j == 4)
									{
										if (b4 != 0)
											break;
									}
								}
							}
						}
					}
				}
				string temp;
				bool a = 1;
				for (int k = 0; k < 6; k++)
				{
					for (int s = 0; s < 10; s++)
					{
						temp = arr[k][s];
						if (temp != "0")
						{
							for (int p = 0; p < 2; p++)
							{
								if (temp[p + 3] != t[ind].sub[p])
								{
									a = 0;
									break;
								}
							}
							if (a)
							{
								switch (k)
								{
								case 0:
									fout << "Monday = " << s << " Slot to " << s + 1 << " Slot";
									fout << " Room = " << arr[k][s] << endl;
									break;
								case 1:
									fout << "Tuesday = " << s << " Slot to " << s + 1 << " Slot";
									fout << " Room = " << arr[k][s] << endl;
									break;
								case 2:
									fout << "Wednesday = " << s << " Slot to " << s + 1 << " Slot";
									fout << " Room = " << arr[k][s] << endl;
									break;

								case 3:
									fout << "Thursday = " << s << " Slot to " << s + 1 << " Slot";
									fout << " Room = " << arr[k][s] << endl;
									break;
								case 4:
									fout << "Friday = " << s << " Slot to " << s + 1 << " Slot";
									fout << " Room = " << arr[k][s] << endl;
									break;
								case 5:
									fout << "Saturday = " << s << " Slot to " << s + 1 << " Slot";
									fout << " Room = " << arr[k][s] << endl;
									break;
								}
							}
						}
					}
				}

			}
			else
				cout << "File Not Found" << endl;
		}
	}
	else
		cout << "File not found" << endl;
}
void Teacher::markattandus(int ind)
{
	int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	int tot;
	int max;
	string** arr;
	arr = 0;
	string st;
	int size;
	st = t[ind].sub;
	size = st.length();
	st += "_";
	st += "att.txt";
	string filename = st;
	ofstream fout;
	string str;
	ifstream fin;
	Student::setcount();
	string* id;
	id = new string[Student::CountStudent];
	int* i;
	i = new int[Student::CountStudent];
	for (int k = 0; k < Student::CountStudent; k++)
	{
		i[k] = 0;
	}
	fin.open("Student.txt");
	if (fin.is_open())
	{
		char c;
		int ij;
		for (int k = 0; k < Student::CountStudent; k++)
		{
			fin.ignore();
			getline(fin, str);
			str = "";
			fin >> str;
			id[k] = str;
			fin >> str;
			fin >> str;
			fin >> str;
			fin.ignore();
			getline(fin, str);
			fin >> c;
			fin >> str;
			fin.ignore();
			getline(fin, str);
			fin >> str;
			fin >> str;
			fin >> str;
			fin.ignore();
			getline(fin, str);
			getline(fin, str);
			str = id[k];
		}
		fin.close();
		for (int k = 0; k < Student::CountStudent; k++)
		{
			string s;
			s = id[k];
			i[k] = stoi(string(1, s[1]));
			int p = stoi(string(1, s[0]));
			i[k] = (p * 10) + i[k];
		}

		max = i[0];
		for (int k = 1; k < Student::CountStudent; k++)
		{
			if (max < i[k])
				max = i[k];
		}
		for (int k = 0; k < Student::CountStudent; k++)
		{
			if (i[k] < max - 3 && i[k] != 0)
				b1++;
			else if (i[k] == max - 2)
				b2++;
			else if (i[k] == max - 1)
				b3++;
			else if (i[k] == max)
				b4++;
		}
		arr = 0;
		if (t[ind].sub == "PHY" || t[ind].sub == "PRO")
		{
			tot = b4;
			arr = new string * [b4];
			for (int k = 0; k < b4; k++)
			{
				arr[k] = new string[31];
			}
		}
		else if (t[ind].sub == "DLD" || t[ind].sub == "MAT")
		{
			tot = b3;
			arr = new string * [b3];
			for (int k = 0; k < b3; k++)
			{
				arr[k] = new string[31];
			}
		}
		else if (t[ind].sub == "PKS" || t[ind].sub == "ENG")
		{
			tot = b2;
			arr = new string * [b2];
			for (int k = 0; k < b2; k++)
			{
				arr[k] = new string[31];
			}
		}
		else if (t[ind].sub == "CAL")
		{
			tot = b1;
			arr = new string * [b1];
			for (int k = 0; k < b1; k++)
			{
				arr[k] = new string[31];
			}
		}
	}
	else
		cout << "File not found" << endl;
	for (int k = 0; k < tot; k++)
	{
		for (int j = 0; j < 31; j++)
		{
			arr[k][j] = "0";
		}
	}
	fin.open(filename);
	if (fin.is_open())
	{
		int j = 0, z = 0;
		for (int k = 0; k < tot; k++)
		{
			fin >> st;
			arr[k][j] = st;
			j++;
			for (int z = 1; z < 30; z++)
			{
				fin >> st;
				arr[k][z] = st;
			}
			j = 0;
		}
		fin.close();
		int cou = 0;
		for (int k = 1; arr[0][k] != "0"; k++)
		{
			cou = k;
		}
		for (int k = 0; k < tot; k++)
		{
			for (int i = 31 - 2; i >= 1; i--) {
				arr[k][i + 1] = arr[k][i];
			}
			// move the second element to the third position
			string temp = arr[k][1];
			arr[k][1] = arr[k][2];
			arr[k][2] = temp;
		}
		int at;
		for (int k = 0; k < tot; k++)
		{
			cout << arr[k][0] << endl;
			cout << "1. Present\n2. Absent\n3. Leave" << endl;
			cout << "Enter your choice = ";
			cin >> at;
			if (at == 1)
				arr[k][1] = "Present";
			else if (at == 3)
				arr[k][1] = "Leave";
			else
				arr[k][1] = "Absent";
		}
		fout.open(filename);
		if (fout.is_open())
		{
			for (int k = 0; k < tot; k++)
			{
				for (int j = 0; j < 31; j++)
				{
					fout << arr[k][j] << " ";
				}
				fout << endl;
			}
		}
		fout.close();
	}
	else
	{

		int y = 0;
		for (int k = 0; k < Student::CountStudent; k++)
		{
			if (t[ind].sub == "PHY" || t[ind].sub == "PRO")
			{
				if (i[k] == max)
				{
					arr[y][0] = id[k];
					y++;
				}
			}
			else if (t[ind].sub == "DLD" || t[ind].sub == "MAT")
			{
				if (i[k] == max - 1)
				{
					arr[y][0] = id[k];
					y++;
				}
			}
			else if (t[ind].sub == "PKS" || t[ind].sub == "ENG")
			{
				if (i[k] == max - 2)
				{
					arr[y][0] = id[k];
					y++;
				}
			}
			else if (t[ind].sub == "CAL")
			{
				if (i[k] == max - 3)
				{
					arr[y][0] = id[k];
					y++;
				}
			}
		}
		int at;
		for (int k = 0; k < tot; k++)
		{
			cout << arr[k][0] << endl;
			cout << "1. Present\n2. Absent\n3. Leave" << endl;
			cout << "Enter your choice = ";
			cin >> at;
			if (at == 1)
				arr[k][1] = "Present";
			else if (at == 3)
				arr[k][1] = "Leave";
			else
				arr[k][1] = "Absent";
		}
		fout.open(filename);
		if (fout.is_open())
		{
			for (int k = 0; k < tot; k++)
			{
				for (int j = 0; j < 31; j++)
				{
					fout << arr[k][j] << " ";
				}
				fout << endl;
			}
		}
		fout.close();
	}
}
void Teacher::markmarks(int ind)
{
	string st;
	string filename;
	string str;
	Student::setcount();
	st = t[ind].sub;
	st += "_";
	st += "mark.txt";
	filename = st;
	ifstream fin;
	ofstream fout;
	string* id;
	string** arr;
	id = new string[Student::CountStudent];
	int* i;
	i = new int[Student::CountStudent];
	for (int k = 0; k < Student::CountStudent; k++)
	{
		i[k] = 0;
		id[k] = "0";
	}
	fin.open("Student.txt");
	if (fin.is_open())
	{
		char c;
		int ij;
		for (int k = 0; k < Student::CountStudent; k++)
		{
			fin.ignore();
			getline(fin, str);
			str = "";
			fin >> str;
			id[k] = str;
			fin >> str;
			fin >> str;
			fin >> str;
			fin.ignore();
			getline(fin, str);
			fin >> c;
			fin >> str;
			fin.ignore();
			getline(fin, str);
			fin >> str;
			fin >> str;
			fin >> str;
			fin.ignore();
			getline(fin, str);
			getline(fin, str);
			str = id[k];
		}
		fin.close();
		for (int k = 0; k < Student::CountStudent; k++)
		{
			string s;
			s = id[k];
			i[k] = stoi(string(1, s[1]));
			int p = stoi(string(1, s[0]));
			i[k] = (p * 10) + i[k];
		}
		int max;
		max = i[0];
		int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
		for (int k = 1; k < Student::CountStudent; k++)
		{
			if (max < i[k])
				max = i[k];
		}
		for (int k = 0; k < Student::CountStudent; k++)
		{
			if (i[k] < max - 3 && i[k] != 0)
				b1++;
			else if (i[k] == max - 2)
				b2++;
			else if (i[k] == max - 1)
				b3++;
			else if (i[k] == max)
				b4++;
		}
		arr = 0;
		int tot;
		if (t[ind].sub == "PHY" || t[ind].sub == "PRO")
		{
			tot = b4;
			arr = new string * [b4];
			for (int k = 0; k < b4; k++)
			{
				arr[k] = new string[2];
			}
		}
		else if (t[ind].sub == "DLD" || t[ind].sub == "MAT")
		{
			tot = b3;
			arr = new string * [b3];
			for (int k = 0; k < b3; k++)
			{
				arr[k] = new string[2];
			}
		}
		else if (t[ind].sub == "PKS" || t[ind].sub == "ENG")
		{
			tot = b2;
			arr = new string * [b2];
			for (int k = 0; k < b2; k++)
			{
				arr[k] = new string[2];
			}
		}
		else if (t[ind].sub == "CAL")
		{
			tot = b1;
			arr = new string * [b1];
			for (int k = 0; k < b1; k++)
			{
				arr[k] = new string[2];
			}
		}
		int y = 0;
		for (int k = 0; k < Student::CountStudent; k++)
		{
			if (t[ind].sub == "PHY" || t[ind].sub == "PRO")
			{
				if (i[k] == max)
				{
					arr[y][0] = id[k];
					y++;
				}
			}
			else if (t[ind].sub == "DLD" || t[ind].sub == "MAT")
			{
				if (i[k] == max - 1)
				{
					arr[y][0] = id[k];
					y++;
				}
			}
			else if (t[ind].sub == "PKS" || t[ind].sub == "ENG")
			{
				if (i[k] == max - 2)
				{
					arr[y][0] = id[k];
					y++;
				}
			}
			else if (t[ind].sub == "CAL")
			{
				if (i[k] == max - 3)
				{
					arr[y][0] = id[k];
					y++;
				}
			}
		}
		int marks;
		for (int k = 0; k < tot; k++)
		{
			while (1)
			{
				cout << arr[k][0] << " = ";
				cin >> marks;
				if (marks < 0 || marks > 100)
				{
					cout << "Invalid marks" << endl;
					cout << "Enter again" << endl;
				}
				else
				{
					arr[k][1] = to_string(marks);
					break;
				}
			}
		}
		fout.open(filename);
		if (fout.is_open())
		{
			for (int k = 0; k < tot; k++)
			{
				fout << arr[k][0] << " " << arr[k][1] << endl;
			}
		}
	}
}
void Teacher::grading(int ind)
{
	string marksfile;
	marksfile = t[ind].sub;
	marksfile += "_";
	marksfile += "mark.txt";
	string gradefile;
	gradefile = t[ind].sub;
	gradefile += "_";
	gradefile += "grade.txt";
	ifstream fin;
	ofstream fout;
	int absrel;
	int thrush;
	cout << "1. Relative Grading\n2. Abslute grading\n";
	cout << "Enter Your Choice = ";
	cin >> absrel;
	if (absrel == 1)
	{
		cout << "Enter value fo thrush = ";
		cin >> thrush;
	}
	else
	{
		thrush = 50;
	}

	string id;
	int i;
	int sum = 0;
	float avg;
	int count = 0;
	bool whilecheck = 1;
	while (whilecheck)
	{
		fin.open(marksfile);
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				count++;
				fin >> id;
				fin >> id;
				sum = stoi(id) + sum;
			}
			count -= 1;
			fin.close();
			avg = sum / count;
			string g;
			fin.open(marksfile);
			if (fin.is_open())
			{
				fout.open(gradefile);
				for (int k = 0; k < count; k++)
				{
					fin >> id;
					fout << id << " ";
					fin >> id;
					i = stoi(id);
					if (absrel != 1)
					{
						if (i < thrush)
						{
							g = "F";
						}
						else if (i == thrush)
						{
							g = "D";
						}
						else if (i < thrush + 3)
						{
							g = "C-";
						}
						else if (i < thrush + 7)
						{
							g = "C";
						}
						else if (i < thrush + 13)
						{
							g = "C+";
						}
						else if (i < thrush + 18)
						{
							g = "B-";
						}
						else if (i < thrush + 20)
						{
							g = "B";
						}
						else if (i < thrush + 25)
						{
							g = "b+";
						}
						else if (i < thrush + 30)
						{
							g = "-A";
						}
						else if (i <= thrush + 35)
						{
							g = "A";
						}
						else if (i > thrush + 35)
						{
							g = "A+";
						}
					}
					else
					{
						i = stoi(id);
						if (i < thrush)
						{
							g = "F";
						}
						else if (i == avg)
						{
							g = "D";
						}
						else if (i < avg + 3)
						{
							g = "C-";
						}
						else if (i < avg + 7)
						{
							g = "C";
						}
						else if (i < avg + 13)
						{
							g = "C+";
						}
						else if (i < avg + 18)
						{
							g = "B-";
						}
						else if (i < avg + 20)
						{
							g = "B";
						}
						else if (i < avg + 25)
						{
							g = "b+";
						}
						else if (i < avg + 30)
						{
							g = "-A";
						}
						else if (i <= avg + 35)
						{
							g = "A";
						}
						else if (i > avg + 35)
						{
							g = "A+";
						}
					}
					fout << g << endl;;
				}
				fin.close();
				fout.close();
			}
			whilecheck = 0;
		}
		else
		{
			cout << "First Enter Marks" << endl;
			markmarks(ind);
			whilecheck = 1;
		}
	}
}
int Student::signin()
{
	string login, ID, user_password;
	ifstream fin;
	int count = 0;
	string str, st;
	char b;
	int k = 0;
	char c;
	int ind = -1;
	setdata_to_s();
	bool b1 = 1;
	system("cls");
	while (b1)
	{
		while (count < 7)
		{
			cout << "Enter Your Roll Number: " << "e.g (22CS-3851)" << endl;
			b = _getch();
			if (isdigit(b))
			{
				cout << b;
				count++;
				str += b;
				b = _getch();
				if (isdigit(b))
				{
					cout << b;
					count++;
					str += b;
					b = _getch();
					if (isdigit(b))
					{
						cout << endl << "You didn't Enter your Department" << endl;
						cout << "Enter from start " << endl;
						count = 0;
						str = "";
						system("cls");
					}
					if (isalpha(b) && count != 0)
					{
						if (b >= 'a' && b <= 'z')
						{
							b = b - 32;
						}
						cout << b;
						count++;
						str += b;

						b = _getch();
						if (isalpha(b) && count != 0)
						{
							if (b >= 'a' && b <= 'z')
							{
								b = b - 32;
							}
							cout << b;
							count++;
							cout << "-";
							str += b;
							str += "-";
							b = _getch();
							if (isdigit(b) && count != 0)
							{
								cout << b;
								count++;
								str += b;
								b = _getch();
								if (isdigit(b) && count != 0)
								{
									cout << b;
									count++;
									str += b;
									b = _getch();
									if (isdigit(b) && count != 0)
									{
										cout << b;
										count++;
										str += b;
										str += '\0';
										cout << endl;
									}
									else
									{
										str = "";
										count = 0;
									}
								}
								else
								{
									str = "";
									count = 0;
								}
							}
							else
							{
								str = "";
								count = 0;
							}
						}
						else
						{
							str = "";
							count = 0;
						}
					}
					else
					{
						str = "";
						count = 0;
					}
				}
				else
				{
					str = "";
					count = 0;
				}
			}
			else
			{
				str = "";
				count = 0;
			}
		}
		cout << str << endl;
		for (int k = 0; k < CountStudent; k++)
		{
			if (str == s[k].ID)
			{
				b1 = 0;
				ind = k;
				cout << s[ind].Password << endl;
			}
		}
		if (b1)
		{
			cout << "NO Roll number matches " << endl;
			cout << "Enter again " << endl;
			count = 0;
			str = "";
		}
	}
	b1 = 1;
	int n = 0;
	while (b1)
	{
		cout << endl << "Enter Your Password = ";
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, user_password);
		if (user_password == s[ind].Password)
		{
			menu(ind);
			b1 = 0;
		}
		n++;
		if (n == 5)
		{
			ind = -1;
			cout << "Limit full error" << endl;
			break;
		}
	}
	return ind;
}
void Student::menu(int ind)
{
	int ch;
	string check = "1";
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|| Wellcome In Student Mode ||_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
	cout << "1. View Attandus" << endl << "2. View Marks" << endl << "3. View Course Registered" << endl << "4. View FeeStatus" << endl << "5. View Grades" << endl;
	while (check == "1")
	{
		cout << "Enter Your choice = ";
		cin >> ch;
		if (ch == 3)
		{
			check = "0";
			int max = 0;
			Student::setcount();
			int* i;
			i = new int[CountStudent];
			int a;
			for (int k = 0; k < CountStudent; k++)
			{
				a = s[k].ID[1] - 48;
				a += ((s[k].ID[0]) - 48) * 10;
				if (max < a)
					max = a;
			}
			a = s[ind].ID[1] - 48;
			a += ((s[ind].ID[0]) - 48) * 10;
			if (a == max)
			{
				cout << "Subject No 1  =  PRO" << endl;
				cout << "Subject No 2  =  PHY" << endl;
			}
			else if (a == max - 1)
			{
				cout << "Subject No 1  =  DLD" << endl;
				cout << "Subject No 2  =  MAT" << endl;
			}
			else if (a == max - 2)
			{
				cout << "Subject No 1  =  PKS" << endl;
				cout << "Subject No 2  =  ENG" << endl;
			}
			else if (a == max - 3)
			{
				cout << "Subject =  CAL" << endl;
			}
		}
		else if (ch == 4)
		{
			check = "0";
			cout << "Fee Status = " << s[ind].feeStatus << endl;
		}
		else if (ch == 2)
		{
			check = "0";
			ifstream fin;
			string filename;
			int a, max = 0;
			for (int k = 0; k < CountStudent; k++)
			{
				a = s[k].ID[1] - 48;
				a += ((s[k].ID[0]) - 48) * 10;
				if (max < a)
					max = a;
			}
			a = s[ind].ID[1] - 48;
			a += ((s[ind].ID[0]) - 48) * 10;
			if (a == max)
			{
				string st;
				filename = "PHY";
				filename += "_";
				filename += "mark.txt";
				cout << "Marks of PHY = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "PHY marks are not uploded yet" << endl;
				}
				filename = "PRO";
				filename += "_";
				filename += "mark.txt";
				cout << "Marks of PRO = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "PRO marks are not uploded yet" << endl;
				}

			}
			else if (a == max - 1)
			{
				string st;
				filename = "DLD";
				filename += "_";
				filename += "mark.txt";
				cout << "Marks of DLD = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "DLD marks are not uploded yet" << endl;
				}
				filename = "MAT";
				filename += "_";
				filename += "mark.txt";
				cout << "Marks of MAT = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "MAT marks are not uploded yet" << endl;
				}
			}
			else if (a == max - 2)
			{
				string st;
				filename = "ENG";
				filename += "_";
				filename += "mark.txt";
				cout << "Marks of ENG = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "ENG marks are not uploded yet" << endl;
				}
				filename = "PKS";
				filename += "_";
				filename += "mark.txt";
				cout << "Marks of PKS = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "PKS marks are not uploded yet" << endl;
				}
			}
			else if (a == max - 3)
			{
				string st;
				filename = "CAL";
				filename += "_";
				filename += "mark.txt";
				cout << "Marks of CAL = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "CAL marks are not uploded yet" << endl;
				}
			}
		}
		else if (ch == 5)
		{
			check = "0";
			ifstream fin;
			string filename;
			int a, max = 0;
			for (int k = 0; k < CountStudent; k++)
			{
				a = s[k].ID[1] - 48;
				a += ((s[k].ID[0]) - 48) * 10;
				if (max < a)
					max = a;
			}
			a = s[ind].ID[1] - 48;
			a += ((s[ind].ID[0]) - 48) * 10;
			if (a == max)
			{
				string st;
				filename = "PHY";
				filename += "_";
				filename += "grade.txt";
				cout << "Grade of PHY = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "PHY Grade are not uploded yet" << endl;
				}
				filename = "PRO";
				filename += "_";
				filename += "grade.txt";
				cout << "Grade of PRO = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "PRO Grade are not uploded yet" << endl;
				}

			}
			else if (a == max - 1)
			{
				string st;
				filename = "DLD";
				filename += "_";
				filename += "grade.txt";
				cout << "Grade of DLD = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "DLD Grade are not uploded yet" << endl;
				}
				filename = "MAT";
				filename += "_";
				filename += "grade.txt";
				cout << "Grade of MAT = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "MAT Grade are not uploded yet" << endl;
				}
			}
			else if (a == max - 2)
			{
				string st;
				filename = "ENG";
				filename += "_";
				filename += "grade.txt";
				cout << "Grade of ENG = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "ENG Grade are not uploded yet" << endl;
				}
				filename = "PKS";
				filename += "_";
				filename += "grade.txt";
				cout << "Grade of PKS = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "PKS Grade are not uploded yet" << endl;
				}
			}
			else if (a == max - 3)
			{
				string st;
				filename = "CAL";
				filename += "_";
				filename += "grade.txt";
				cout << "Grade of CAL = ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							fin >> st;
							cout << st << endl;
						}
					}
					fin.close();
				}
				else
				{
					cout << "CAL Grade are not uploded yet" << endl;
				}
			}
		}
		else if (ch == 1)
		{
			check = "0";
			ifstream fin;
			string filename;
			int a, max = 0;
			for (int k = 0; k < CountStudent; k++)
			{
				a = s[k].ID[1] - 48;
				a += ((s[k].ID[0]) - 48) * 10;
				if (max < a)
					max = a;
			}
			a = s[ind].ID[1] - 48;
			a += ((s[ind].ID[0]) - 48) * 10;
			if (a == max)
			{
				string st;
				filename = "PHY";
				filename += "_";
				filename += "att.txt";
				cout << "PHY == ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							for (int k = 0; k < 30; k++)
							{
								fin >> st;
								if (st[0] >= '0' && st[0] <= '9')
									break;
								cout << st << "\t";
							}
							break;
						}
					}
					fin.close();
				}
				else
				{
					cout << " Att are not uploded yet" << endl;
				}
				filename = "PRO";
				filename += "_";
				filename += "att.txt";
				cout << "PRO ==  ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							for (int k = 0; k < 30; k++)
							{
								fin >> st;
								if (st[0] >= '0' && st[0] <= '9')
									break;
								cout << st << "\t";
							}
							break;
						}
					}
					fin.close();
				}
				else
				{
					cout << "Att are not uploded yet" << endl;
				}

			}
			else if (a == max - 1)
			{
				string st;
				filename = "DLD";
				filename += "_";
				filename += "att.txt";
				cout << "DLD == ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							for (int k = 0; k < 30; k++)
							{
								fin >> st;
								if (st[0] >= '0' && st[0] <= '9')
									break;
								cout << st << "\t";
							}
							break;
						}
					}
					fin.close();
				}
				else
				{
					cout << "DLD Att are not uploded yet" << endl;
				}
				filename = "MAT";
				filename += "_";
				filename += "att.txt";
				cout << "MAT == ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							for (int k = 0; k < 30; k++)
							{
								fin >> st;
								if (st[0] >= '0' && st[0] <= '9')
									break;
								cout << st << "\t";
							}
							break;
						}
					}
					fin.close();
				}
				else
				{
					cout << "Att are not uploded yet" << endl;
				}
			}
			else if (a == max - 2)
			{
				string st;
				filename = "ENG";
				filename += "_";
				filename += "att.txt";
				cout << "ENG == ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							for (int k = 0; k < 30; k++)
							{
								fin >> st;
								if (st[0] >= '0' && st[0] <= '9')
									break;
								cout << st << "\t";
							}
							break;
						}
					}
					fin.close();
				}
				else
				{
					cout << "Att are not uploded yet" << endl;
				}
				filename = "PKS";
				filename += "_";
				filename += "att.txt";
				cout << "PKS == ";
				fin.open(filename);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							for (int k = 0; k < 30; k++)
							{
								fin >> st;
								if (st[0] >= '0' && st[0] <= '9')
									break;
								cout << st << "\t";
							}
							break;
						}
					}
					fin.close();
				}
				else
				{
					cout << "Att are not uploded yet" << endl;
				}
			}
			else if (a == max - 3)
			{
				string st;
				filename = "CAL";
				filename += "_";
				filename += "att.txt";
				fin.open(filename);
				cout << "CAL == ";
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> st;
						if (st == s[ind].ID)
						{
							for (int k = 0; k < 30; k++)
							{
								fin >> st;
								if (st[0] >= '0' && st[0] <= '9')
									break;
								cout << st << "\t";
							}
							break;
						}
					}
					fin.close();
				}
				else
				{
					cout << "Att are not uploded yet" << endl;
				}
			}
		}
		else
		{
			cout << "Invalid command" << endl;
			check = "1";
		}
		if (check == "0")
		{
			cout << endl;
			cout << "Enter 1 to take more option and 0 to go back = ";
			cin >> check;
		}
	}
}





void HOD::Sign_In()
{
	hod = new HOD[5];
	ifstream fin;
	fin.open("HOD.txt");
	if (fin.is_open())
	{
		for (int k = 0; k < 5; k++)
		{
			fin >> hod[k];
		}
		fin.close();
	}
	else
		cout << "File not found" << endl;
	string password, username;
	int ind;
	bool ch = 1;
	system("cls");
	for (int k = 0; k < 5; k++)
	{
		cout << hod[k].UserName;
		cout << endl;
	}
	while (ch)
	{
		cout << "Enter Your User name: ";
		getline(cin, username);
		for (int k = 0; k < 5; k++)
		{
			if (hod[k].UserName == username)
			{
				cout << hod[k].UserName << endl;
				ind = k;
				ch = 0;
				break;
			}
		}
		if (ch)
		{
			cout << "Try Again" << endl;
		}
	}
	ch = 1;
	int count = 0;
	while (ch)
	{
		cout << "Enter Your Password :";
		getline(cin, password);
		if (hod[ind].Password == password)
		{
			menu(ind);
			ch = 0;
		}
		else
		{
			cout << "Try Again" << endl;
			count++;
			if (count == 5)
				break;
		}
	}
	if (ch)
	{
		cout << "Your account is locked" << endl;
	}
}
void HOD::menu(int ind)
{
	string ch;
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|| HOD Mode ||_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
	cout << "1. View All Teacher" << endl << "2. View All Student" << endl << "3. Student Module" << endl << "4. HOD As Teacher" << endl;
	cout << "Enter Your choice = ";
	cin >> ch;
	int i;
	bool b1 = 0;
	if (ch == "1")
	{
		Teacher::display();
	}
	else if (ch == "2")
	{
		Student stu;
		stu.setdata_to_s();
		system("cls");
		for (int k = 0; k < Student::CountStudent; k++)
		{
			if (stu.s[k].Depatment == hod[ind].Depatment)
			{
				cout << "ID = " << stu.s[k].ID << endl;
				cout << "Name = " << stu.s[k].FirstName << " " << stu.s[k].LastName << endl;
				cout << "Contact Number = " << stu.s[k].ContactNo << endl;
				cout << "Address = " << stu.s[k].Address << endl;
				cout << "Gender = " << stu.s[k].Gender << endl;
				cout << "Qualification = " << stu.s[k].Qualification << endl;
				cout << "Depatment = " << stu.s[k].Depatment << endl;
				cout << "Blood Group = " << stu.s[k].bloodGroup << endl;
				cout << "FeeStatus = " << stu.s[k].feeStatus << endl;
				cout << "User Name = " << stu.s[k].UserName << endl;
				cout << "Password = " << stu.s[k].Password << endl;
				cout << endl;
				cout << "`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`-_-`";
				cout << endl;
			}
		}
	}
	else if (ch == "3")
	{
		string rollno;
		cout << "Enter Roll No. = ";
		cin >> rollno;
		int size = rollno.length();
		rollno += '\0';
		Student stu;
		stu.setdata_to_s();
		for (int k = 0; k < Student::CountStudent; k++)
		{
			if (stu.s[k].ID == rollno)
			{
				i = k;
				b1 = 1;
				break;
			}
		}
		if (b1)
		{
			stu.menu(i);
		}
		else
			cout << "NO Student exist of this roll no." << endl;
	}
	else if (ch == "4")
	{

	}
}
//void HOD::Teacher_files()
//{
//
//
//
//
//}
void HOD::Student_files()
{
	cout << "Student Password file" << endl;
	ifstream read;
	string data;
	read.open("Roll-no.txt");
	if (read.is_open())
	{
		while (!read.eof())
		{
			getline(read, data);
			cout << "Roll-No & Password: " << data << endl;
		}
	}
	else
	{
		cout << "File not found ";
	}

}
HOD::HOD() :Teacher()
{

}
ifstream& operator >>(ifstream& in, HOD& h)
{
	string s;
	char c;
	int sal;
	in.ignore();
	getline(in, s);
	s = "";
	in >> s;
	h.ID = s;
	in >> s;
	h.FirstName = s;
	in >> s;
	h.LastName = s;
	in >> s;
	h.ContactNo = s;
	s = "";
	in.ignore();
	getline(in, s);
	h.Address = s;
	in >> c;
	h.Gender = c;
	in.ignore();
	getline(in, s);
	h.Qualification = s;
	getline(in, s);
	h.Depatment = s;
	in >> sal;
	h.salary = sal;
	in >> s;
	h.sub = s;
	in >> s;
	h.UserName = s;
	in.ignore();
	getline(in, s);
	h.Password = s;
	getline(in, s);
	return in;
}