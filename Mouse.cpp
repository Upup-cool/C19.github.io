// Mouse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <WinUser.h>

using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)


void action(int iX_p, int iY_p, int iCount_p, int iSpeed_p)
{
	for (int iw = 0; iw <= iCount_p; iw++)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, iX_p, iY_p, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, iX_p, iY_p, 0, 0);
		cout << "  " << iw << " executions" << endl;
		Sleep(iSpeed_p);
	}
}

int main()
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 277);
	system("color F9");
	system("title 小空格连点器 1.0    小空格.com");

	POINT P;
	int iX, iY, iCount = 0, iSpeed = 0;

	cout << "Enter the number of clicks: ";
	cin >> iCount;
	cout << "Enter the click  speed(ms): ";
	cin >> iSpeed;
	cout << "\nOK, please press C to start.\n" << endl;

	while (true)
	{
		if (KEY_DOWN('C'))
		{
			cout << "\nKey press detected.\n" << endl;

			GetCursorPos(&P);
			iX = P.x;
			iY = P.y;

			cout << "x: " << iX << "	y: " << iY << "\n\n" << endl;

			for (int i = 5; i >= 1; i--)
			{
				cout << "Start execution after  " << i << "  seconds" << endl;
				Sleep(1000);
			}

			action(iX, iY, iCount, iSpeed);
		}
	}	// End of while loop.

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file