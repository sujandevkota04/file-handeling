#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;
class Student
{
    int id;
    char name[20], add[15];
public:
    void set()
    {
        cout << "Enter id, name and address of student:" << endl;
        cin >> id >> name >> add;
    }
    void display()
    {
        cout << setw(4) << id << setw(15) << name << setw(15) << add << endl;        
    }
    int return_id()
    {
        return id;
    }
};

void write_file()
{
    Student obj;
    obj.set();
    ofstream fobj;
    fobj.open("filename", ios::app | ios::binary | ios::out);
    fobj.write((char *) &obj, sizeof(obj));
    system("cls");
    cout << "Information successfully added........" << endl;
    cout << endl;
    fobj.close();
}
void read_file()
{
    Student obj;
    ifstream fobj("filename", ios::binary | ios::in);
    if (fobj.is_open())
    {
        cout << setw(4) << "ID" << setw(15) << "Name" << setw(15) << "Address" << endl;
        while(fobj.read((char *) &obj, sizeof(obj)))
            obj.display();
        cout << endl;
    }
    else
        cout << "File not found........." << endl;
    fobj.close();
}
void search_file(int id)
{
    Student obj;
    ifstream fobj("filename", ios::binary | ios::in);
    int flag = 0;
    while(fobj.read((char *) &obj, sizeof(obj)))
    {
        if(id == obj.return_id())
        {
            flag = 1;
            cout << setw(4) << "ID" << setw(15) << "Name" << setw(15) << "Address" << endl;
            obj.display();
            cout << endl;
        }
    }
    if(flag == 1)
        cout << "Search successfull....." << endl << endl;
    else
        cout << "Search Unsuccessfull......." << endl << endl;
    fobj.close();  
}

int main()
{
    int choice;
    do
    {
        cout << "_____________Choose a number_____________" << endl;
        cout << "1: Add student's information" << endl;
        cout << "2: Display the file" << endl;
        cout << "3: Search file" << endl;
        cout << "4: Exit" << endl;
        cin >> choice;
        system("cls");
        switch(choice)
        {
            case 1:
                write_file();
                break;
            case 2:
                read_file();
                break;
            case 3:
                int id;
                cout << "Enter id to search" << endl;
                cin >> id;
                search_file(id);
                break;
            case 4:
                break;
        }
    } while (choice != 4);
    return 0;
}