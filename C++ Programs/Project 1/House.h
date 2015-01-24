#include <string>
using namespace std;

class House
{
public:
    House();
    House(string owner, unsigned short housenum);
    House(string owner, unsigned short housenum, unsigned short rooms);

    void setOwnerName(string owner) { ownername = owner; }
    void setHouseNumber(unsigned short housenum) { housenumber = housenum; }
    void setNumberOfRooms(unsigned short rooms) { numberofrooms = rooms; }

    string getOwnerName() { return ownername; }
    unsigned short getHouseNumber() { return housenumber; }
    unsigned short getNumberofRooms() { return numberofrooms; }

    void toString();

private:
    string ownername;
    unsigned short housenumber;
    unsigned short numberofrooms;
};

