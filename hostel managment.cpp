#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    int id;
    string name;

    Student()
    {
        id = 0;
        name = "";
    }

    Student(int i, string n)
    {
        id = i;
        name = n;
    }
};
class Accommodation
{
public:

    virtual void allocateRoom(Student* s, int roomNo) = 0;

    virtual void vacateRoom(int roomNo) = 0;
};
class Reportable
{
public:

    virtual void generateReport() = 0;
};
class Room
{
public:

    int roomNumber;
    string type;
    int floor;

    Student* occupants[3];
    int totalStudents;

    Room()
    {
        roomNumber = 0;
        type = "";
        floor = 0;

        totalStudents = 0;

        for(int i=0; i<3; i++)
        {
            occupants[i] = NULL;
        }
    }

    Room(int no, string t, int f)
    {
        roomNumber = no;
        type = t;
        floor = f;

        totalStudents = 0;

        for(int i=0; i<3; i++)
        {
            occupants[i] = 0;
        }
    }
};
class HostelBlock
{
public:

    string blockName;

    Room rooms[3];

    HostelBlock()
    {
        blockName = "Rumi Block";
    }

    HostelBlock(string name)
    {
        blockName = name;

        rooms[0] = Room(101,"Single",1);
        rooms[1] = Room(102,"Double",1);
        rooms[2] = Room(201,"Triple",2);
    }
};
class HostelManager : public Accommodation , public Reportable
{
public:

    HostelBlock block;

    HostelManager()
    {
        block = HostelBlock("A Block");
    }

    void allocateRoom(Student* s, int roomNo)
    {
        for(int i=0; i<3; i++)
        {
            if(block.rooms[i].roomNumber == roomNo)
            {
                if(block.rooms[i].totalStudents < 3)
                {
                    int pos = block.rooms[i].totalStudents;

                    block.rooms[i].occupants[pos] = s;

                    block.rooms[i].totalStudents++;

                    cout << s->name<< " allocated to Room "<< roomNo << endl;

                    return;
                }

                else
                {
                    cout << "Room is Full!" << endl;
                    return;
                }
            }
        }

        cout << "Room not found!" << endl;
    }

    void vacateRoom(int roomNo)
    {
        for(int i=0; i<3; i++)
        {
            if(block.rooms[i].roomNumber == roomNo)
            {
                block.rooms[i].totalStudents = 0;

                for(int j=0; j<3; j++)
                {
                    block.rooms[i].occupants[j] = NULL;
                }

                cout << "Room " << roomNo << " is now empty." << endl;

                return;
            }
        }
    }

    void generateReport()
    {
        cout << "Block : "<< block.blockName<< endl;

        for(int i=0; i<3; i++)
        {
            cout << "Room Number : "<< block.rooms[i].roomNumber<< endl;

            cout << "Type : " << block.rooms[i].type << endl;

            cout << "Floor : "<< block.rooms[i].floor<< endl;

            cout << "Occupants : "<< block.rooms[i].totalStudents<< endl;

            for(int j=0; j<block.rooms[i].totalStudents; j++)
            {
                cout << "- "<< block.rooms[i].occupants[j]->name<< endl;
            }
        }
    }
};
int main()
{
    Student s1(1,"Ali");
    Student s2(2,"Ahmed");
    Student s3(3,"Sara");

    HostelManager h;

    h.allocateRoom(&s1,101);

    h.allocateRoom(&s2,102);

    h.allocateRoom(&s3,102);

    h.generateReport();

    h.vacateRoom(102);

    cout << "After Vacating:"<<endl;

    h.generateReport();

    return 0;
}