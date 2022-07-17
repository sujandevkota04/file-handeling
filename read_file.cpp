#include <iostream>
#include <iomanip>
#include <fstream>
#define filename student_info
using namespace std;
class Student
{
    int roll;
    char name[20];
public:
    void set()
    {
        cout << "Enter the name and roll no. of student" << endl;
        cin >> name >> roll;
    }
    void display()
    {
        cout << name << setw(20) << roll << endl;
    }
    int return_id()
    {
        return roll;
    }
};
void write_file()
{
    Student obj;
    obj.set();
    ofstream fobj ("filename", ios::binary | ios::out | ios::app);
    cout << "Writing in a file..............." << endl;
    
    fobj.write((char *) &obj, sizeof(obj));
    fobj.close();
}
void read_file()
{
    Student obj;
    ifstream fobj ("filename", ios::in | ios::binary);
    cout << "Reading a file.............." << endl;
    
    if(fobj.is_open())
    {
        cout << "Name" << setw(20) << "Roll No." << endl;
        while (fobj.read((char *) &obj, sizeof(obj)))
        {
            obj.display();
        }
        
    }
    else
        cout << "Error opening the file" << endl;
        
    fobj.close();
}
void search_file(int id)
{
    Student obj;
    ifstream fobj ("filename", ios::binary | ios::in | ios::app);
    int flag = 0;
    while(fobj.read((char *) &obj, sizeof(obj)))
    {
        if(id == obj.return_id())
        {
            obj.display();
            flag = 1;
        }
    }
    if(flag == 1)
        cout << "Search successfully..........." << endl;
    else    
        cout << "Search Unsuccessfull......." << endl;
    fobj.close();
}

int main()
{
    int n, choice;
    do
    {
        cout << "_____________Choose a number_____________" << endl;
        cout << "1: Add student's information" << endl;
        cout << "2: Display the file" << endl;
        cout << "3: Search the file" << endl;
        cout << "4: Exit" << endl;
        cin >> choice;
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
                cout << "Enter id for search:" << endl;
                cin >> id;
                search_file(id);
                break;
            case 4:
                break;
        }
    }while(choice != 4);
    return 0;
}

