#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <vector> // stack + ArrayList. 근데 아무튼 짬뽕

using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, }; // 커서 정보 담고있는 구조체(클래스 다운그레이드 버전) 비슷한거
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = visible; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); // 커서 정보를 수정하는 함수
	// &cursorInfo : cursorInfo의 주소값을 투척
	// 자세한 건 포인터 배우십셔
}

class Character {
public:
	string name = "O";
	int myX = 10, myY = 10;
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

class Enemy : public Character { // C++에서의 상속 방법
// C++에는 상속시 접근제어 방법이 3가지가 있음 (public, protected, private)
// public으로 상속할 시 (public, protected, private) 으로 상속됨
// protected으로 상속할 시 (protected, protected, private) 으로 상속됨
// public으로 상속할 시 (private, private, private) 으로 상속됨
// 무슨말인지 모르면 상속 검색 ㄱㄱ

// 여담으로 C++은 다중상속 지원함
public:
	Enemy() { // 생성자에 인수 추가할려면 인수 없는 기본생성자를 정의해줘야함

	}
	Enemy(int x, int y) {
		this->name = "X";
		this->myX = x;
		this->myY = y;
		this->print();
	}
};

int main() {
	Enemy me;

	CursorView(false);

	vector<Enemy> enemyList; // 이거 모른다하면 현실에서 지건때린다
	enemyList.push_back(Enemy(5, 5)); // enemyList에 (Enemy 객체를 생성하고 해당 객체의) 데이터를 push한다.

	while (true)
	{
		me.eraser();

		// 충돌 감지 구간
		for (Enemy &em : enemyList) { // 범위 기반 for문
			em.eraser();
			if (me.myX == em.myX && me.myY == em.myY) { // 나의 X, Y좌표가 적군의 X, Y좌표와 같다면
				delete &em; // 해당 Enemy 객체를 메모리에서 삭제시킨다.
				return 0; // 게임 종료
			}
			em.print();
		}
		// for문을 통해서 루프를 돌 때마다(50ms마다) 모든 적과의 충돌여부를 일일히 체크해준다.
		// enemyList.push_back() 을 여러개 하고, 좌표를 각각 달리 해보자.
		// 어느 적과 충돌해도 게임 종료가 가능하다.

		if (GetAsyncKeyState(VK_UP)) me.move(1);
		if (GetAsyncKeyState(VK_DOWN)) me.move(2);
		if (GetAsyncKeyState(VK_LEFT)) me.move(3);
		if (GetAsyncKeyState(VK_RIGHT)) me.move(4);
		me.print();
		Sleep(50);
	}
}
