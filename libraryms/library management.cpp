#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int bookId;
    string title;
    string author;
    bool issued;
};

Book books[100];
int totalBooks = 0;

void addBook()
{
    cout << "\nEnter Book ID: ";
    cin >> books[totalBooks].bookId;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, books[totalBooks].title);

    cout << "Enter Author Name: ";
    getline(cin, books[totalBooks].author);

    books[totalBooks].issued = false;

    totalBooks++;

    cout << "\nBook Added Successfully!\n";
}

void displayBooks()
{
    if (totalBooks == 0)
    {
        cout << "\nNo Books Available!\n";
        return;
    }

    cout << "\n------ BOOK LIST ------\n";

    for (int i = 0; i < totalBooks; i++)
    {
        cout << "\nBook ID : " << books[i].bookId;
        cout << "\nTitle   : " << books[i].title;
        cout << "\nAuthor  : " << books[i].author;
        cout << "\nStatus  : "
             << (books[i].issued ? "Issued" : "Available");
        cout << "\n-----------------------\n";
    }
}

void searchBook()
{
    string searchTitle;

    cin.ignore();

    cout << "\nEnter Book Title to Search: ";
    getline(cin, searchTitle);

    bool found = false;

    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].title == searchTitle)
        {
            cout << "\nBook Found!";
            cout << "\nBook ID : " << books[i].bookId;
            cout << "\nAuthor  : " << books[i].author;
            cout << "\nStatus  : "
                 << (books[i].issued ? "Issued" : "Available")
                 << endl;

            found = true;
        }
    }

    if (!found)
        cout << "\nBook Not Found!\n";
}

void issueBook()
{
    int id;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].bookId == id)
        {
            if (!books[i].issued)
            {
                books[i].issued = true;
                cout << "\nBook Issued Successfully!\n";
            }
            else
            {
                cout << "\nBook Already Issued!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

void returnBook()
{
    int id;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].bookId == id)
        {
            if (books[i].issued)
            {
                books[i].issued = false;
                cout << "\nBook Returned Successfully!\n";
            }
            else
            {
                cout << "\nBook Was Not Issued!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}