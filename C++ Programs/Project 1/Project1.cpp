#include <iostream>
#include <Book.h>
#include <Window.h>
#include <House.h>
#include <string>

using namespace std;

int main()
{
    string bname, bauthor;
    int byear;
    cout << "Book object: " << endl;
    cout << "Book name: ";
    getline(cin, bname);
    cout << "Book author: ";
    getline(cin, bauthor);
    cout << "Published year: ";
    cin >> byear;

    Book bobject(bname, bauthor, byear);
    bobject.toString();

    cout << endl;
    /////////////////////////////////////////////////////////////

    int xposition, yposition;
    string winname;
    cout << "Window object: " << endl;
    cout << "Window name: ";
    cin.ignore();
    getline(cin, winname);
    cout << "Window xposition: ";
    cin >> xposition;
    cout << "Window yposition: ";
    cin >> yposition;

    Window wobject(xposition, yposition, (char*)winname.c_str());
    wobject.toString();

    cout << endl;
    //////////////////////////////////////////////////////////////

    string owner;
    unsigned short housenum, rooms;
    cout << "House object: " << endl;
    cout << "Owner's name: ";
    cin.ignore();
    getline(cin, owner);
    cout << "House number: ";
    cin >> housenum;
    cout << "Number of rooms: ";
    cin >> rooms;

    House hobject(owner, housenum, rooms);
    hobject.toString();

    return 0;
}
