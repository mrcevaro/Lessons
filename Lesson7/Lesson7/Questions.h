#pragma once
// 1 Что означает хорошее понимание STL

// 1.1 Что означает реализовать контейнер реализующий какой-то интерфейс и способный выбросить исключение

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

	// 3 
	struct CmdSetColumnAddress_t : public Command_t <0x15, 3> {
		using Start_t = CmdArgument_t <1, uint8_t>;
		using End_t = CmdArgument_t <2, uint8_t>;
	};