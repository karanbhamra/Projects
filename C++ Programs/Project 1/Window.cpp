#include <iostream>
#include "Window.h"

using namespace std;

Window::Window(){ winname = 0;}

Window::Window(int x, int y)
{
    xposition = x;
    yposition = y;
    winname = 0;
}

Window::Window(int x, int y, char * wname)
{
    xposition = x;
    yposition = y;
    winname = wname;
}

void Window::setWindowName(char * wname)
{
    winname = wname;
}

void Window::toString()
{
    cout << "The Window object is: (" << this->getXPosition() << "," << this->getYPosition() << "), " << this->getWindowName() << "." << endl;

}

