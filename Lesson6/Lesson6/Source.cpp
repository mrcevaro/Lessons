#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <thread>
#include "ObjectsGamePlay.h"
#include "ConsoleHelper.h" 
#include "Score.h"
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
// 4. ������� ��������� ������
// 5. �������� ������ 
// 6. �������� � ������ � ������ ��������
// 7. ������� ��� ����, ���� ���� �������� ������, �� �� �� "�����"
// 8. ������� ������ ����� ����� ������ ��������. ������������ �������� ������ �������������� ���� �� ����� �� ����.

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

int main()
{
	//GamePlay<10,20> game;
	GamePlay game;
	ConsoleHelper cs;

	std::thread keyboard_thread(&GamePlay::GetKey, &game);
	//std::thread sound_thread(&GamePlay::PlaySoundWithBeep, &game);

	while (true)
	{
		game.MoveAsterisk();
	}
	keyboard_thread.join();
	//sound_thread.join();
	std::system("pause");
}