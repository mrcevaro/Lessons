#pragma once
#include "pch.h"

namespace TestHelper
{
	template <class T>
	std::unique_ptr<T[]> GetArrayFromInitializerList(std::initializer_list<T> list)
	{
		auto arr = std::make_unique<int[]>(list.size());

		{
			int i = 0;
			for (auto input_elem : list)
			{
				arr[i] = input_elem;
				i++;
			}
		}

		return arr;
	}
	
	template <class TFuction>
	class TestArrayCompare
	{
		TFuction _function;
	public:
		explicit TestArrayCompare(TFuction& function)
			: _function(function)
		{}

		void ExpectEq(std::initializer_list<int> input, std::initializer_list<int> output)
		{
			auto arr = GetArrayFromInitializerList(input);

			_function(arr.get(), static_cast<int>(input.size()));

			{
				int i = 0;
				for (auto expected_elem : output)
				{
					EXPECT_EQ(arr[i], expected_elem);
					i++;
				}
			}

		}
	};

	template <class TFuction>
	TestArrayCompare<TFuction> GetTestArrayCompare(TFuction function)
	{
		return TestArrayCompare<TFuction>{ function};
	}

	
	template <class TFuction>
	class TestReturnValue
	{
		TFuction _function;
	public:
		explicit TestReturnValue(TFuction& function)
			: _function(function)
		{}

		void ExpectEq(std::initializer_list<int> input, int expected_output)
		{
			const auto arr = GetArrayFromInitializerList(input);

			const auto result = _function(arr.get(), static_cast<int>(input.size()));

			EXPECT_EQ(result, expected_output);
		}
	};

	template <class TFuction>
	TestReturnValue<TFuction> GetTestReturnValue(TFuction function)
	{
		return TestReturnValue<TFuction>{ function};
	}
}