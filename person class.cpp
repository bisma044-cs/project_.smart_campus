#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;

public:
    Student(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }
};

class Faculty
{
private:
    string name;

public:
    Faculty(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }
};

class CapacityExceededException
{
public:
    void showMessage()
    {
        cout << "Error: Course capacity exceeded!" << endl;
    }
};

class Course
{
private:
    string courseCode;
    string courseName;
    int creditHours;
    Faculty *instructor;
    int maxCapacity;
    int enrolledCount;

    Student *students[50];

    Student *waitingList[20];
    int waitingCount;

public:
    Course(string code, string name, int credits,
           Faculty *inst, int capacity)
    {
        courseCode = code;
        courseName = name;
        creditHours = credits;
        instructor = inst;
        maxCapacity = capacity;

        enrolledCount = 0;
        waitingCount = 0;
    }

    string getCourseCode()
    {
        return courseCode;
    }

    void setCourseName(string name)
    {
        courseName = name;
    }

    void enrollStudent(Student *s)
    {
        if (enrolledCount < maxCapacity)
        {
            students[enrolledCount] = s;
            enrolledCount++;
            cout << s->getName()
                 << " enrolled successfully." << endl;
        }
        else
        {
            waitingList[waitingCount] = s;
            waitingCount++;

            throw CapacityExceededException();
        }
    }

    bool operator==(Course &c)
    {
        return courseCode == c.courseCode;
    }

    Student **operator+(Course &c)
    {
        static Student *mergedList[40];

        int k = 0;

        for (int i = 0; i < waitingCount; i++)
        {
            mergedList[k++] = waitingList[i];
        }

        for (int i = 0; i < c.waitingCount; i++)
        {
            mergedList[k++] = c.waitingList[i];
        }

        return mergedList;
    }

    friend ostream &operator<<(ostream &out, Course &c);
};

ostream &operator<<(ostream &out, Course &c)
{
    out << "\nCourse Details" << endl;
    out << "Course Code: " << c.courseCode << endl;
    out << "Course Name: " << c.courseName << endl;
    out << "Credit Hours: " << c.creditHours << endl;
    out << "Instructor: " << c.instructor->getName() << endl;
    out << "Capacity: " << c.maxCapacity << endl;
    out << "Enrolled Students: " << c.enrolledCount << endl;

    return out;
}

class Enrollment
{
private:
    Student *student;
    Course *course;
    string enrollmentDate;
    string grade;

public:
    Enrollment(Student *s, Course *c,
               string date, string g)
    {
        student = s;
        course = c;
        enrollmentDate = date;
        grade = g;
    }

    void display()
    {
        cout << "\nEnrollment Record" << endl;
        cout << "Student: "
             << student->getName() << endl;

        cout << "Date: "
             << enrollmentDate << endl;

        cout << "Grade: "
             << grade << endl;
    }
};

int main()
{
    Faculty f1("Sir Ahmed");

    Student s1("Ali");
    Student s2("Usman");
    Student s3("Hamza");

    Course c1("CS101", "OOP", 3, &f1, 2);
    Course c2("CS101", "Object Oriented Programming", 3, &f1, 3);

    if (c1 == c2)
    {
        cout << "Courses are equal." << endl;
    }

    try
    {
        c1.enrollStudent(&s1);
        c1.enrollStudent(&s2);
        c1.enrollStudent(&s3);
    }
    catch (CapacityExceededException e)
    {
        e.showMessage();
    }

    cout << c1;

    Enrollment e1(&s1, &c1,
                  "20-06-2026", "A");

    e1.display();

    return 0;
}
