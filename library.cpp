#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class OverdueException
{
private:
    float fine;

public:
    OverdueException(float f)
    {
        fine = f;
    }

    void showFine()
    {
        cout << "Overdue Item!" << endl;
        cout << "Fine Amount: Rs. " << fine << endl;
    }
};

class LibraryItem
{
protected:
    int itemID;
    string title;
    string author;
    int publicationYear;

public:
    LibraryItem(int id, string t, string a, int year)
    {
        itemID = id;
        title = t;
        author = a;
        publicationYear = year;
    }

    virtual void checkout() = 0;

    string getTitle()
    {
        return title;
    }

    int getItemID()
    {
        return itemID;
    }

    virtual void displayInfo() = 0;
};

class Book : public LibraryItem
{
private:
    string ISBN;
    string genre;
    int copiesAvailable;

public:
    Book(int id, string t, string a, int year,
         string isbn, string g, int copies)
        : LibraryItem(id, t, a, year)
    {
        ISBN = isbn;
        genre = g;
        copiesAvailable = copies;
    }

    void checkout()
    {
        if (copiesAvailable > 0)
        {
            copiesAvailable--;
            cout << "Book Issued Successfully" << endl;
        }
        else
        {
            cout << "No Copies Available" << endl;
        }
    }

    void displayInfo()
    {
        cout << "\nBook Information" << endl;
        cout << "ID: " << itemID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << publicationYear << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Genre: " << genre << endl;
        cout << "Copies: " << copiesAvailable << endl;
    }
};

class Journal : public LibraryItem
{
private:
    string ISSN;
    int volume;
    int issueNumber;

public:
    Journal(int id, string t, string a, int year,
            string issn, int vol, int issue)
        : LibraryItem(id, t, a, year)
    {
        ISSN = issn;
        volume = vol;
        issueNumber = issue;
    }

    void checkout()
    {
        cout << "Journal Issued Successfully" << endl;
    }

    void displayInfo()
    {
        cout << "\nJournal Information" << endl;
        cout << "ID: " << itemID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << publicationYear << endl;
        cout << "ISSN: " << ISSN << endl;
        cout << "Volume: " << volume << endl;
        cout << "Issue Number: " << issueNumber << endl;
    }
};

struct IssuedRecord
{
    string rollNo;
    int itemID;
};

class Library
{
private:
    LibraryItem* catalog[50];
    int totalItems;

    IssuedRecord issued[50];
    int issuedCount;

public:
    Library()
    {
        totalItems = 0;
        issuedCount = 0;
    }

    void addItem(LibraryItem* item)
    {
        catalog[totalItems] = item;
        totalItems++;
    }

    void searchByTitle(string searchTitle)
    {
        bool found = false;

        for (int i = 0; i < totalItems; i++)
        {
            if (catalog[i]->getTitle() == searchTitle)
            {
                catalog[i]->displayInfo();
                found = true;
            }
        }

        if (!found)
        {
            cout << "Item Not Found" << endl;
        }
    }

    void issueItem(string rollNo, int itemID)
    {
        issued[issuedCount].rollNo = rollNo;
        issued[issuedCount].itemID = itemID;

        issuedCount++;

        cout << "Item Issued Successfully" << endl;
    }

    void saveToFile()
    {
        ofstream file("library.txt");

        for (int i = 0; i < totalItems; i++)
        {
            file << catalog[i]->getItemID() << " "
                 << catalog[i]->getTitle() << endl;
        }

        file.close();

        cout << "Data Saved Successfully" << endl;
    }

    void loadFromFile()
    {
        ifstream file("library.txt");

        string line;

        cout << "\nData From File:\n";

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    void returnItem(int daysLate)
    {
        if (daysLate > 0)
        {
            float fine = daysLate * 20;

            throw OverdueException(fine);
        }

        cout << "Item Returned Successfully" << endl;
    }
};

int main()
{
    Library library;

    Book b1(
        101,
        "OOP",
        "Ali Ahmad",
        2024,
        "978123",
        "Programming",
        5
    );

    Journal j1(
        201,
        "AI Research",
        "Dr Ahmed",
        2025,
        "ISSN123",
        10,
        2
    );

    library.addItem(&b1);
    library.addItem(&j1);

    library.searchByTitle("OOP");

    library.issueItem("22-CS-101", 101);

    library.saveToFile();
    library.loadFromFile();

    try
    {
        library.returnItem(5);
    }
    catch (OverdueException e)
    {
        e.showFine();
    }

    return 0;
}
