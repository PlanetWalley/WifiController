#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void move(int x, int y)
{
	POINT pt;
	GetCursorPos(&pt);
	SetCursorPos(pt.x + x, pt.y + y);
}

void singleClick()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void rightClick()
{
	mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}

void makeForeground()
{
	SetWindowPos(HWND_TOPMOST, 0, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

int main(int argc, char* argv[])
{
	if ( !(argc == 4  || (argc == 2 && atoi(argv[1]) != 1) ))
	{
		//cout << "ConsoleMoveCursor: Move the cursor relative to the current position." << endl;
		//cout << "3 and 4 not yet implemented." << endl;
		//cout << "Usage: " << argv[0] << " m x y" << endl;
		//cout << "\tm - mode: 1: move, 2: single click; 3: right click." << endl;
		//cout << "\tx - pixels to move to right." << endl;
		//cout << "\ty - pixels to move to bottom." << endl;
		return 0; // Incorrect args
	}
	int mode = atoi(argv[1]);
	switch(mode) {
	case 1: {
		int x = atoi(argv[2]), y = atoi(argv[3]) ;
		//cout << "Move with vector (" << x << ", " << y << ")." << endl;
		move(x, y);
			}
			break;
	case 2:
		singleClick();
		break;
	case 3:
		rightClick();
		break;
	}

	return 0;
}