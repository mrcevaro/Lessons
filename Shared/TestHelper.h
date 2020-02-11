//Hello Unicode World ☺. ☻.
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

		template <class TArray>
		void ExpectEq(std::initializer_list<int> input, TArray& output)
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

	template <class TSortFunction>
	class SortTestHelper
	{
		TestHelper::TestArrayCompare<TSortFunction> _tester;
		std::vector<std::initializer_list<int>> _input_arrays;
	public:
		SortTestHelper(TSortFunction sort_function, std::vector<std::initializer_list<int>> input_arrays)
			: _tester(sort_function),
			_input_arrays(std::move(input_arrays))
		{}

		void Test()
		{
			using InputOutputCase = std::pair<std::initializer_list<int>, std::initializer_list<int>>;

			for (auto& input_array : _input_arrays)
			{
				std::vector<int> output_array = input_array;
				std::sort(output_array.begin(), output_array.end());
				_tester.ExpectEq(input_array, output_array);
			}
		}
	};
}