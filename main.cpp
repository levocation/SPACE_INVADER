#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

class Character {
public:
	string name = "O";
	int myX = 5, myY = 5;
	void move(int vec) {
		switch (vec)
		{
		case 1: myY--;
			break;
		case 2: myY++;
			break;
		case 3: myX--;
			break;
		case 4: myX++;
			break;
		default:
			break;
		}
	}
	void eraser() {
		gotoxy(myX, myY);
		cout << " ";
	}
	void print() {
		gotoxy(myX, myY);
		cout << name;
	}
};

int main() {
	Character me;
	while (true)
	{
		me.eraser();
		if (GetAsyncKeyState(VK_UP)) me.move(1);
		if (GetAsyncKeyState(VK_DOWN)) me.move(2);
		if (GetAsyncKeyState(VK_LEFT)) me.move(3);
		if (GetAsyncKeyState(VK_RIGHT)) me.move(4);
		me.print();
		Sleep(50);
	}
}
