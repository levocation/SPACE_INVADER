#include <iostream> // C++에는 printf 말고 cout이 있는데 그거 쓰게 해줌
#include <conio.h> // getAsyncKeyState, getch 쓰게 해주는거
#include <Windows.h> // gotoxy의 원동력
#include <string> // 얘 없으면 string 자유자재로 못 씀

using namespace std; // 이거 없으면 쥬낸 불편하다는 것만 말해줌

void gotoxy(int x, int y) // gotoxy ㅇㅇ
{
	COORD pos = { x,y }; // Windows.h에서 Api로 지원하는 구조체인데, 콘솔 화면 버퍼 셀에 대한 값을 잡는거임
	// 뭔소린지 모르겠으면 대충 좌푯값 잡는갑다 하고 넘어가 ㅇㅇ
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// SetConsoleCursorPosition : 커서 위치를 이동하는 함수
	// GetStdHandle : 어느 화면에서 커서를 옮길 것인가?
	// STD_OUTPUT_HANDLE : 니가 보고 있는 콘솔창이요
	// pos : ㅇㅇ
}

class Character { // Java Class랑 똑같아
public: // public: 기호 밑으로는 전부 접근권한이 public
// 안쓰면 private 박고 시작함 (기본값이 private)
	string name = "O"; // Java String이랑 똑같은데 여기는 소문자
	int myX = 5, myY = 5; // 초기값 선언을 해줄 수 있음
	void move(int vec) {
		switch (vec) // 이거 모르면 도제학생 아님
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
		// printf(" "); 과 똑같다
	}
	void print() {
		gotoxy(myX, myY);
		cout << name;
		// printf("%s", name); 과 똑같다.
		// 차이점이라면 cout은 "%s"같은 형식 지정자가 없다는 거
		// 이걸 이용하면 실수를 처리할 때 "%.3f" "%lld" 이딴거 필요없다
	}
private: // 위에서 public 쓴 거랑 상관없이 private 밑으로는 전부 private
// protected 키워드도 있음
// default 키워드는 없음
	int test_var = 0;
};

int main() {
	Character me;
	// Java와 달리 이렇게 선언하면 끝
	// 근데 생성자를 쓰고 싶으면 Character me = Character();
	// new 키워드도 있긴 한데 어짜피 포인터 모르니 그냥 넘어가
	
	while (true)
	{
		me.eraser();
		if (GetAsyncKeyState(VK_UP)) me.move(1); // 위쪽 방향키
		if (GetAsyncKeyState(VK_DOWN)) me.move(2); // 아래쪽 방향키
		if (GetAsyncKeyState(VK_LEFT)) me.move(3); // 왼쪽 방향키
		if (GetAsyncKeyState(VK_RIGHT)) me.move(4); // 오른쪽 방향키
		
		me.print();
		Sleep(50); // 50ms(1000ms = 1초, 50ms = 0.02초)만큼 딜레이를 준다.
		// while (true)가 무한루프라서 Sleep 안쓰면 무한루프를 매우 빠른 속도로 돌다가 지가 에러남
	}
}
