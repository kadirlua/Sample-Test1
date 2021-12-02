#pragma once
#include <string>

namespace myClassTest {
	class myClass
	{
	public:
		explicit myClass(int x) noexcept;
		explicit myClass(std::string str) noexcept;
		explicit myClass(int x, std::string str) noexcept;
		virtual ~myClass() = default;

		void addSum(int a) noexcept;

		void appendStr(std::string str) noexcept;

		int getVal() const noexcept {
			return mx;
		}

		std::string getStr() const noexcept {
			return mstr;
		}
		
		bool operator==(const myClass& r) const noexcept {
			return mx == r.mx && mstr == r.mstr;
		}

		bool operator!=(const myClass& r) const noexcept {
			return !(*this == r);
		}

	private:
		int mx{};
		std::string mstr;
	};
}
