#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    string cnic;
    int age;
    string contact;

public:
    Person(string n, string c, int a, string con)
    {
        name = n;
        cnic = c;
        age = a;
        contact = con;
    }

    virtual void displayInfo() = 0;
};

class Student : public Person
{
private:
    string rollNo;
    int semester;
    float GPA;
    string enrolledCourses[3];

public:
    Student(string n, string c, int a, string con,
            string r, int sem, float gpa,
            string courses[])
        : Person(n, c, a, con)
    {
        rollNo = r;
        semester = sem;
        GPA = gpa;

        for (int i = 0; i < 3; i++)
        {
            enrolledCourses[i] = courses[i];
        }
    }

    void calculateGrade()
    {
        if (GPA >= 3.7)
            cout << "Grade: A" << endl;
        else if (GPA >= 3.0)
            cout << "Grade: B" << endl;
        else if (GPA >= 2.0)
            cout << "Grade: C" << endl;
        else
            cout << "Grade: F" << endl;
    }

    void displayInfo()
    {
        cout << "\n----- Student Information -----" << endl;
        cout << "Name: " << name << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Semester: " << semester << endl;
        cout << "GPA: " << GPA << endl;

        cout << "Enrolled Courses: ";
        for (int i = 0; i < 3; i++)
        {
            cout << enrolledCourses[i] << " ";
        }
        cout << endl;

        calculateGrade();
    }
};

class Faculty : public Person
{
private:
    string employeeID;
    string department;
    string designation;
    string assignedCourses[3];

public:
    Faculty(string n, string c, int a, string con,
            string id, string dep, string des,
            string courses[])
        : Person(n, c, a, con)
    {
        employeeID = id;
        department = dep;
        designation = des;

        for (int i = 0; i < 3; i++)
        {
            assignedCourses[i] = courses[i];
        }
    }

    void displayInfo()
    {
        cout << "Staff Information" << endl;
        cout << "Name: " << name << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl;

        cout << "Assigned Courses: ";
        for (int i = 0; i < 3; i++)
        {
            cout << assignedCourses[i] << " ";
        }
        cout << endl;
    }
};

class Staff : public Person
{
private:
    string staffID;
    string role;
    float salary;

public:
    Staff(string n, string c, int a, string con,
          string id, string r, float s)
        : Person(n, c, a, con)
    {
        staffID = id;
        role = r;
        salary = s;
    }

    void displayInfo()
    {
        cout << "Staff Information" << endl;
        cout << "Name: " << name << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Staff ID: " << staffID << endl;
        cout << "Role: " << role << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    string studentCourses[3] = {"OOP", "DLD", "Calculus"};
    string facultyCourses[3] = {"OOP", "Database", "AI"};

    Student s1("Ali", "12345-1234567-1", 20,
               "03001234567", "22-CS-101", 2,
               3.5, studentCourses);

    Faculty f1("Ahmed", "11111-2222222-3", 40,
               "03111234567", "F101",
               "Computer Science", "Lecturer",
               facultyCourses);

    Staff st1("Usman", "33333-4444444-5", 35,
              "03211234567", "S201",
              "Lab Assistant", 50000);

    Person *persons[3];

    persons[0] = &s1;
    persons[1] = &f1;
    persons[2] = &st1;

    for (int i = 0; i < 3; i++)
    {
        persons[i]->displayInfo();
    }

    return 0;
}
