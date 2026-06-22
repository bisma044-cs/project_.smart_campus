#include<iostream>
#include<algorithm>
using namespace std;
class Student
{
public:

    string name;
    float gpa;
};
class Book
{
public:

    string title;
    bool overdue;
};
class Reports
{
public:

    void campusReport()
    {
        cout << "===== Campus Report =====" << endl;

        cout << "Students : 3" << endl;

        cout << "Teachers : 10" << endl;

        cout << "Books : 3" << endl;

        cout << "Rooms : 20" << endl;
    }

    void pdfReport()
    {
        cout << "===== PDF Style Report =====" << endl;

        cout << "Students : 3" << endl;

        cout << "Teachers : 10" << endl;

        cout << "Books : 3" << endl;

        cout << "Rooms : 20" << endl;
    }
};
class Utils
{
public:

    void line()
    {
        cout << "----------------------" << endl;
    }

    bool check(int n)
    {
        return n >= 0;
    }
};

bool sortGPA(Student a, Student b)
{
    return a.gpa < b.gpa;
}

bool overdueBook(Book b)
{
    return b.overdue == true;
}

int main()
{
    Reports r;
    Utils u;
    Student *s = new Student[3];

    s[0].name = "Ali";
    s[0].gpa = 3.4;

    s[1].name = "Sara";
    s[1].gpa = 3.9;

    s[2].name = "Ahmed";
    s[2].gpa = 3.2;


    Book *b = new Book[3];

    b[0].title = "OOP";
    b[0].overdue = false;

    b[1].title = "DSA";
    b[1].overdue = true;

    b[2].title = "DBMS";
    b[2].overdue = false;
    r.campusReport();
    sort(s, s + 3, sortGPA);

    cout << "Students Sorted By GPA"<<endl;

    for(int i=0; i<3; i++)
    {
        cout << s[i].name <<""<< s[i].gpa<< endl;
    }
    Book *result;

    result = find_if(b, b + 3, overdueBook);

    if(result != b + 3)
    {
        cout << "First Overdue Book : "<<endl;

        cout << result->title << endl;
    }
    r.pdfReport();

    delete[] s;

    delete[] b;

    return 0;
}