
#include "GamePlay.h"




//1. Зафиксировать размеры карты и нарисовать на границах стену из #.
//2. Не позволять звездочке выходить за границу.
//2.5 При вверх  - есть бага
//3. Заполнить массив стен рандомными стенами в количестве n штук.
//4. Нарисовать стены из массива.
//5. Не позволять звездочке наступать на стены.
//6/ Сделать правильное движение змейки. Сейчас двигается только голова, тело стоит на месте.
// Змейка движется так: голова встает на новую позицию, а все следующие элементы двигаются вперед
// {2,0} {3,0} {3,1} {3,2} {4,2}
// {1,0} {2,0} {3,0} {3,1} {3,2}
// 7 добавить на поле в случаеное место еду (1 клетка), кога голова ее касается, то написать Hello
// Еда генерируется в новом месте
// задания
// 1. Убрать _wals, _foods. Сделать только массив fields
// 2. Убарть логику score в отдельный класс
// 3. Перевести змейку на вектор. Сделать чтоб голова была в начале массива


// 1. Разнести логику по файликам
// 2. В классе Score не рисовать стену, ит не принимать размеры поля. А принимать только точку куда писать.
// 3. Заюзать енам Snake в поле
// 4. Добавить врагов 
// 5. Сделать так чтоб, если враг касается змейки, то он ее "режет"
// 6. Добавить к змейке и врагам скорость

// 7. Сделать кольцеовй массив
// 8. Сделать врагам более умную логику движения. Использовать алгоритм поиска наикратчайшего пути от врага до змеи.
// 9. Сделать функции AddObject, RemoveObject, MoveObject - котоыре объединяют логику установки значаниея в _field и рисовнаия объекта.
// 10. MovementSnake - в этой функции TODO

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

