#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

class drama
{
	int dramacode, noofscenes;
	float duration;
	char drama_title[35];
public:
	void dramainput(void);
	void dramaoutput(void);
	
	int getdramacode()	//Accessor function
	{
		return dramacode;
	}

	char* getdramatitle()	//Accessor Function
	{
		return drama_title;
	}
	
}d1;

void drama::dramainput(void)
{
		cout << "\nEnter drama code: ";
		cin >> dramacode;
		cout << "\nEnter no. of scenes: ";
		cin >> noofscenes;
		cout << "\nEnter duration: ";
		cin >> duration;
		cout << "\nEnter drama title: ";
		gets(drama_title);
}

void drama::dramaoutput(void)
{
	cout << "\nDrama code: " << dramacode;
	cout << "\nNo. of scenes: " << noofscenes;
	cout << "\nDuration: " << duration;
	cout << "\nDrama title: " << drama_title;
}

void storedetails(void);
void searchdetails(void);
void countrecord(void);
void displaydetails(void);
void deletedetails(void);

void main()
{
	int ch;
	cout << "\nSelect choice from Menu: ";
	cout << "\n***Menu***";
	cout << "\n1. Storing Details";
	cout << "\n2. Searching record on the basis of drama_title";
	cout << "\n3. Count total number of records";
	cout << "\n4. Display records";
	cout << "\n5. Delete record using dramacode";
	cout << "\n6. Exit";

	cin >> ch;

	switch(ch)
    {
	case 1:	    storedetails();
	    break;
	case 2:     searchdetails();
	    break;
	case 3:     countrecord();
	    break;
	case 4:     displaydetails();
	    break;
	case 5:     deletedetails();
	    break;
	case 6:      exit(1);
    }
 }
void storedetails()
{
fstream fio;
fio.open("drama.dat", ios::binary | ios::app);
cout << "\nDrama Entry Module";
drama d1;
cout << "\nDrama Data Entry: ";
d1.dramainput();
fio.write((char*)&d1, sizeof(d1));
fio.close();
}

void searchdetails()
{
char found = 'n';
ifstream fio;
fio.open("drama.dat", ios::in | ios::binary);
char temp_title[15];
drama d1;
cout << "\nEnter drama title to be searched for: ";
gets(temp_title);
while(!fio.eof())
{
	fio.read((char*)&d1, sizeof(d1));
	if (strcmp(temp_title, d1.getdramatitle()) == 0)
	{
		d1.dramaoutput();
		found = 'y';
		break;
	}
}

if (found == 'n')
	cout << "\nDrama title not found in file." << endl;


}


void countrecord()
{
	fstream df;
	int count = 0;
	drama d1;
	clrscr();
	cout << "\nDrama Read/Display Module";
	cout << "\nThe output of drama.dat data file: \n";
	df.open("drama.dat", ios::binary | ios::in);
	while (df.read((char*)&d1, sizeof(d1)))
	{
		d1.dramaoutput();
		count++;
	}
	df.close();
	cout << "\nThe number of dramas stored are: " << count;
}

void displaydetails()
{
	fstream df;
	drama d1;
	clrscr();
	cout << "\nDrama Read/Display Module";
	cout << "\nThe output of drama.dat data file: \n";
	df.open("drama.dat", ios::binary | ios::in);
	while (df.read((char*)&d1, sizeof(d1)))
	{
		d1.dramaoutput();
	}
	df.close();
}

void deletedetails()
{
int dcode; char found = 'f', confirm = 'n';
cout << "\nEnter drama code of drama to be deleted: ";
cin >> dcode;
ifstream fio("drama.dat", ios::in | ios::binary);
ofstream file ("temp.dat", ios::out | ios::binary);
fio.read((char*)&d1, sizeof(d1));
while(!fio.eof())
{
	
	fio.read((char*)&d1, sizeof(d1));
	if (d1.getdramacode() == dcode)
	{
		d1.dramaoutput();
		found = 't';
		cout << "\nAre you sure you want to delete this record? (y/n) ";
		cin >> confirm;
		if (confirm == 'n')
			file.write((char*)&d1, sizeof(d1));	//When confirm is yes, record is not written in temp file
	}
	else 
		file.write((char*)&d1, sizeof(d1));
}

if(found == 'f')
	cout << "\nRecord not found\n";
fio.close();
file.close();
remove("drama.dat");
rename("temp.dat", "drama.dat");
fio.open("drama.dat", ios::in);

cout << "\nNow the file contains\n";
while(!fio.eof())
{
	fio.read((char*)&d1, sizeof(d1));
	if(fio.eof())
		break;
	d1.dramaoutput();
}
fio.close();
}