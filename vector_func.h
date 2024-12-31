#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>
#include "mfdef.h"
namespace much{
    // operator
	#if __cplusplus >= 201103L
    template<typename T>
    std::ostream& operator <<(std::ostream& outs, Vector<T> &a) {
        for (auto x : a)
            outs << x << ' ';
        return outs;
    }
	#endif

    template<typename T>
    std::istream& operator >>(std::istream& ins, Vector<T> &a) {
        for (I_32 i = 0; i < a.size(); i++)
            ins >> a[i];
        return ins;
    }
	// iofunc.h
	// 10_2
	template<typename T>
	void input_some(Vector<T> &a, const I_32 len) {
		for (I_32 i = 0; i < len; i++) {
			T sth = input(sth);
			a.push_back(sth);
		}
	}

	// 11_2
	template<typename T>
	void output_some(Vector<T> &a, const STR Begin = "", const STR end = " ", const STR Lend = "\n") {
		for (T x : a)
			output(x, Begin, end);
		std::cout << Lend;
	}

	// 20_2
	template<typename T>
	void input_some_a_to_b(Vector<T> &a, const I_32 A, const I_32 B) {
		for (I_32 i = A; i <= B; ++i)
			input(a[i]);
	}

	// 21_2
	template<typename T>
	void output_some_a_to_b(Vector<T> &a, const I_32 A, const I_32 B, const STR Begin = "", const STR end = " ", const STR Lend = "\n") {
		for (I_32 i = A; i <= B; ++i)
			output(a[i], Begin, end);
		std::cout << Lend;
	}


	// much_func.h
	// 5_2
	template<typename T>
	double avg(Vector<T> &nums) {
		T sum = std::accumulate(nums.begin(), nums.end(), T(0));
		return static_cast<double>(sum) / nums.size();
	}

	// 9_2
	template<typename T>
	T sum_some(Vector<T> &a) {
		return std::accumulate(a.begin(), a.end(), T(0));
	}

	// 12_2
	template<typename T>
	void n_to_some(Vector<T> &a, const T n) {
		std::fill_n(a.begin(), a.size(), n);
	}

	// 16_2
	template<typename T>
	T nums_max(Vector<T> &nums) {
		return *std::max_element(nums.begin(), nums.end());
	}

	// 17_2
	template<typename T>
	T nums_min(Vector<T> &nums) {
		return *std::min_element(nums.begin(), nums.end());
	}

	// 22_2
	template<typename T>
	void run_to_some(Vector<T> &a, const I_32 step = 1) {
		for (I_32 i = 0; i < a.size(); i += step)
			a[i] = i;
	}

	// 25_2
	template<typename T>
	void reverse_some(Vector<T> &a) {
		std::reverse(a.begin(), a.end());
	}

	// 27_2
	// wrong.

    // 33_2
	//Please call srand(time(NULL))
	template <typename T>
	void fill_random(Vector<T> &nums, I_32 len, I_64 max_rand) {
		for (I_32 i = 0; i < len; i++)
			nums[i] = rand() % max_rand;
	}

	// 37
	template<typename T>
	Vector<T> vector_range(T len, T _begin = 0, T step = 1) {
		Vector<T> Range;
		T num = _begin;
		for (T i = 0; i < len; i++) {
			Range.push_back(num);
			num += step;
		}
		return Range;
	}
}
