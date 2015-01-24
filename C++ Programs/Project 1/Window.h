#include <string>
using namespace std;

class Window
{
public:
    Window();
    Window(int x, int y);
    Window(int x, int y, char* wname);

    int getXPosition() { return xposition; }
    int getYPosition() { return yposition; }
    char * getWindowName() { return winname; }

    void setXPosition(int x) { xposition = x; }
    void setYPosition(int y) { yposition = y; }
    void setWindowName(char * wname);

    void toString();

private:
    int xposition;
    int yposition;
    char *winname;
};
