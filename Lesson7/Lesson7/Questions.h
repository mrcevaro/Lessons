#pragma once
// 1 Что означает хорошее понимание STL
// Знать как работают основные контейнеры: (vector, map (set), deque (queue, stack), list, unordered_map(unordered_set))
//		Знаить их функции. Знать как они устроены внутри.
//		Знать алгоритмическую сложность каждой функции.
//		Понимать что такое итератор
//		Пример использования

// Алгоритмы.


// 1.1 Что означает реализовать контейнер реализующий какой-то интерфейс и способный выбросить исключение

constexpr int f(int a)
{
	if (a == 1)
	{
		return 1;
	}
	return f(a - 1) * a;
}

int arr[f(10)];



// 2
namespace ssd1325 {

	template <uint8_t CODE, size_t LENGTH>
	struct Command_t {
		static constexpr uint8_t    Code() { return CODE; }
		static constexpr size_t     Length() { return LENGTH; }

		constexpr const uint8_t*    Data() const { return mData.data(); }
		constexpr size_t            Size() const { return mData.size(); }

		template <class T>
		constexpr Command_t&        SetArgument(T argument) {
			if (argument.Offset() == 0)    mData[0] = CODE | argument.Value();
			else                            mData[argument.Offset()] = argument.Value();
			return *this;
		}

	private:
		std::array <uint8_t, LENGTH> mData = { CODE };
	};

	template <uint8_t CODE>
	using Command_t_with_lenght_3 = Command_t<CODE, 3>;

	using  Command_t_0x15_3 = Command_t_with_lenght_3<0x15>;

	// 3 
	struct CmdSetColumnAddress_t : public Command_t_0x15_3 {
		using Start_t = CmdArgument_t <1, uint8_t>;
		using End_t = CmdArgument_t <2, uint8_t>;
	};
}