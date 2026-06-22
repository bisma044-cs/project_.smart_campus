#include<iostream>
using namespace std;

class FeeRecord
{
private:

    string studentID;

    int semesterFee;

    int hostelFee;

    int libraryFine;

    int totalPaid = 0;

    int balance;

public:

    FeeRecord(string id, int sem, int hostel, int fine)
    {
        studentID = id;

        semesterFee = sem;

        hostelFee = hostel;

        libraryFine = fine;

        balance = semesterFee + hostelFee + libraryFine;
    }

    FeeRecord(const FeeRecord &f)
    {
        studentID = f.studentID;

        semesterFee = f.semesterFee;

        hostelFee = f.hostelFee;

        libraryFine = f.libraryFine;

        totalPaid = f.totalPaid;

        balance = f.balance;
    }
    FeeRecord& operator=(const FeeRecord &f)
    {
        if(this != &f)
        {
            studentID = f.studentID;

            semesterFee = f.semesterFee;

            hostelFee = f.hostelFee;

            libraryFine = f.libraryFine;

            totalPaid = f.totalPaid;

            balance = f.balance;
        }

        return *this;
    }

    void payFee(int amount)
    {
        totalPaid = totalPaid + amount;

        balance = balance - amount;

        if(balance < 0)
        {
            balance = 0;
        }
    }

    void showRecord()
    {
        cout << "Student ID : " << studentID << endl;

        cout << "Semester Fee : " << semesterFee << endl;

        cout << "Hostel Fee : " << hostelFee << endl;

        cout << "Library Fine : " << libraryFine << endl;

        cout << "Total Paid : " << totalPaid << endl;

        cout << "Balance : " << balance << endl;
    }
};

int main()
{
    FeeRecord f1("22-CS-101", 50000, 15000, 1000);

    cout << "Original Record:" << endl;

    f1.showRecord();

    f1.payFee(30000);

    cout << "After Paying Fee:" << endl;

    f1.showRecord();

    FeeRecord f2(f1);

    cout << "Copied Record:" << endl;

    f2.showRecord();

    FeeRecord f3("0",0,0,0);

    f3 = f1;

    cout << "Assigned Record:" << endl;

    f3.showRecord();

    return 0;
}
