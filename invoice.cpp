#include<iostream>
using namespace std;

class Invoice
{
private:

    int invoiceID;
    static int invoiceCounter;

    string date;

    string *items;
    int size;

    float totalAmount;

public:

    Invoice(string d, int s, float t)
    {
        invoiceCounter++;

        invoiceID = invoiceCounter;

        date = d;

        size = s;

        totalAmount = t;

        items = new string[size];
    }
    Invoice(const Invoice &obj)
    {
        invoiceID = obj.invoiceID;

        date = obj.date;

        size = obj.size;

        totalAmount = obj.totalAmount;

        items = new string[size];

        for(int i=0; i<size; i++)
        {
            items[i] = obj.items[i];
        }
    }
    Invoice& operator=(const Invoice &obj)
    {
        delete[] items;

        invoiceID = obj.invoiceID;

        date = obj.date;

        size = obj.size;

        totalAmount = obj.totalAmount;

        items = new string[size];

        for(int i=0; i<size; i++)
        {
            items[i] = obj.items[i];
        }
    }

    void setItem(int index, string item)
    {
        items[index] = item;
    }

    void display()
    {
        cout<<"Invoice ID: "<<invoiceID<<endl;

        cout<<"Date: "<<date<<endl;

        cout<<"Items:"<<endl;

        for(int i=0; i<size; i++)
        {
            cout<<items[i]<<endl;
        }

        cout<<"Total Amount: "<<totalAmount<<endl;
    }

    static int getInvoiceCount()
    {
        return invoiceCounter;
    }

    ~Invoice()
    {
        delete[] items;
    }
};

int Invoice::invoiceCounter = 0;
int main()
{
    Invoice i1("19-06-2026", 3, 62000);

    i1.setItem(0, "Semester Fee");
    i1.setItem(1, "Hostel Fee");
    i1.setItem(2, "Library Fine");

    i1.display();

    return 0;
}