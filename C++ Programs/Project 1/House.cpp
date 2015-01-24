#include <iostream>
#include "House.h"

using std::cout;
using std::endl;

House::House() {}

House::House(string owner, unsigned short housenum)
{
    ownername = owner;
    housenumber = housenum;
}

House::House(string owner, unsigned short housenum, unsigned short rooms)
{
    ownername = owner;
    housenumber = housenum;
    numberofrooms = rooms;
}

void House::toString()
{
    cout << "The House object is: " << this->getOwnerName() << ", " << this->getHouseNumber() << ", " << this->getNumberofRooms() << "." << endl;
}

