#pragma once

#include <memory>
#include <vector>

namespace SmartPointers
{
	struct A
	{
		int a;
		int b;
		A(int a, int b)
			:a(a), b(b) {}
	};

	void f1()
	{
		A* ptr = new A{ 1,3 };
		// ....

		int c = 0;
		int d = 0;
		// .....

		if (c == 1)
		{
			delete ptr;
			return;
		}

		if (d == 3)
		{
			delete ptr;
			return;
		}

		// .....

		delete ptr;
	}

	void f2()
	{
		std::unique_ptr<A> ptr = std::unique_ptr<A>(new A{ 1,3 });
		std::unique_ptr<A> ptr1 = std::make_unique<A>(2,3);
		std::unique_ptr<A> ptr2 = std::move(ptr1);
		// ....

		int c = 0;
		int d = 0;
		// .....

		ptr->a = 3;
		ptr->b = ptr->a;

		if (c == 1)
		{
			return;
		}

		if (d == 3)
		{
			return;
		}
		// .....
	}

	struct BigStruct
	{
		int _arr[10000000];
	};

	void f3()
	{
		std::vector<BigStruct> v(1000);
		v.erase(v.begin() + 3); // Удалить 3 элементиз массива, остальные сдвинутся

		std::vector<std::unique_ptr<BigStruct>> v1;
		for (int i = 0; i < 1000; i++)
		{
			v.emplace_back(std::make_unique<BigStruct>());
		}

		v1.erase(v1.begin() + 3);
	}

	void f4()
	{
		std::shared_ptr<A> ptr = std::shared_ptr<A>(new A{ 1,3 });
		std::shared_ptr<A> ptr1 = std::make_shared<A>(2, 3);

		{
			std::shared_ptr<A> ptr2 = ptr1;
			// ...
		}
		// ....

		int c = 0;
		int d = 0;
		// .....

		ptr->a = 3;
		ptr->b = ptr->a;

		if (c == 1)
		{
			return;
		}

		if (d == 3)
		{
			return;
		}
		// .....
	}
}