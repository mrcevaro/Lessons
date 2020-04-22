
#include "GamePlay.h"




//1. ������������� ������� ����� � ���������� �� �������� ����� �� #.
//2. �� ��������� ��������� �������� �� �������.
//2.5 ��� �����  - ���� ����
//3. ��������� ������ ���� ���������� ������� � ���������� n ����.
//4. ���������� ����� �� �������.
//5. �� ��������� ��������� ��������� �� �����.
//6/ ������� ���������� �������� ������. ������ ��������� ������ ������, ���� ����� �� �����.
// ������ �������� ���: ������ ������ �� ����� �������, � ��� ��������� �������� ��������� ������
// {2,0} {3,0} {3,1} {3,2} {4,2}
// {1,0} {2,0} {3,0} {3,1} {3,2}
// 7 �������� �� ���� � ��������� ����� ��� (1 ������), ���� ������ �� ��������, �� �������� Hello
// ��� ������������ � ����� �����
// �������
// 1. ������ _wals, _foods. ������� ������ ������ fields
// 2. ������ ������ score � ��������� �����
// 3. ��������� ������ �� ������. ������� ���� ������ ���� � ������ �������


// 1. �������� ������ �� ��������
// 2. � ������ Score �� �������� �����, �� �� ��������� ������� ����. � ��������� ������ ����� ���� ������.
// 3. ������� ���� Snake � ����
// 4. �������� ������ 
// 5. ������� ��� ����, ���� ���� �������� ������, �� �� �� "�����"
// 6. �������� � ������ � ������ ��������

// 7. ������� ��������� ������
// 8. ������� ������ ����� ����� ������ ��������. ������������ �������� ������ �������������� ���� �� ����� �� ����.
// 9. ������� ������� AddObject, RemoveObject, MoveObject - ������� ���������� ������ ��������� ��������� � _field � ��������� �������.
// 10. MovementSnake - � ���� ������� TODO

char RandomMove()
{
	char ch;
	switch (std::rand() % 4)
	{
	case 0: ch = 'w'; break;
	case 1: ch = 'a'; break;
	case 2: ch = 's'; break;
	case 3: ch = 'd'; break;
	default:
		break;
	}
	return ch;
}

#include "Parallel.h"
#include "circlebuffrer.h"




class B
{
	std::string s;
	int a;
	double b;
	
public:
	static int objects_count;

	B()
	{
		objects_count++;
	}

	~B()
	{
		objects_count--;
	}

};

int B::objects_count = 0;


struct A
{
	B b;
	B b1;
};


int main()
{
	B b;
	{
		B b1;
		B b2;
		{
			A a;
			std::cout << B::objects_count << std::endl;
		}

		std::cout << B::objects_count << std::endl;
	}

	std::cout << B::objects_count << std::endl;

	//f1();
	//return 0;

	//GamePlay<10,20> game;
	GamePlay game;
	std::thread keyboard_thread(&GamePlay::GetKey, &game);
	//std::thread sound_thread(&GamePlay::PlaySoundWithBeep, &game);

	while (true)
	{
		game.Action();
	}
	keyboard_thread.join();
	//sound_thread.join();
	std::system("pause");
}

void f(int& a)
{
	
}

void g()
{
	int r = 0;
	f(r);
	
}

class A
{
	int a;

public:
	void Draw();
};

class B
{
	A a1;
	A a2;
};

void g()
{
	A a1;
	A a2;

}

