#include "pch.h"

#include "../../Shared/TestHelper.h"

#include "../Additional/Tasks_1.h"

TEST(Additioonal, Task_XX)
{
	/*1.3.��� ������ ������� n.��� �������� ����� ������ ��������� � ��������� ���������� �������� �� 0.
		������ ����� : 2 4 1 6 1 3 2 9 7 3 9 4 2
		����� : 2 4 1 0 0 0 0 0 0 0 9 4 2*/

	auto test = TestHelper::GetTestReturnValue(TestHelper::DummyFunction);
	test.ExpectEq({ 1,2,3,4,5,4,3,2,1 }, 0);
	test.ExpectEq({ 4,3,8,1 }, 1);
}

TEST(Additioonal, Task_1_3)
{
	/*1.3.��� ������ ������� n.��� �������� ����� ������ ��������� � ��������� ���������� �������� �� 0.
			������ ����� : 2 4 1 6 1 3 2 9 7 3 9 4 2
			����� : 2 4 1 0 0 0 0 0 0 0 9 4 2*/

	auto test = TestHelper::GetTestArrayCompare(TestHelper::DummyFunction);
	test.ExpectEq({ 2, 4, 1, 6, 1, 3, 2, 9, 7, 3, 9, 4, 2 }, { 2, 4, 1, 0, 0, 0, 0, 0, 0, 0, 9, 4, 2, });
}

TEST(Additioonal, Task_1_4)
{
	/*1.4.��� ������ ������� n.� ������� ����� ���� ������ ����� 0, 1, 2, 3, 4. ������� ������� ��� ����������� ������ �����.
		������ ����� : 3 2 3 4 0 0 0 2 4 3
		����� : 0 - 3
		1 - 0
		2 - 2
		3 - 3
		4 - 2*/

	auto test = TestHelper::GetTestArrayCompare(Task1_4);
	test.ExpectEq({ 3, 2, 3, 4, 0, 0, 0, 2, 4, 3 }, { 3, 0, 2, 3, 2 });
}