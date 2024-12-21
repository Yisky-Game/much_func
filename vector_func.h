#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>
namespace much{
    #define Vector std::vector
    // operator
    template<typename T>
    std::ostream& operator <<(std::ostream& outs, Vector<T> &a) {
        for (auto x : a)
            outs << x << ' ';
        return outs;
    }

    template<typename T>
    std::istream& operator >>(std::istream& ins, Vector<T> &a) {
        for (int i = 0; i < a.size(); i++)
            ins >> a[i];
        return ins;
    }
	// iofunc.h
	// 10_2
	template<typename T>
	void input_some(Vector<T> &a, const int len) {
		for (int i = 0; i < len; i++) {
			T sth = input(sth);
			a.push_back(sth);
		}
	}

	// 11_2
	template<typename T>
	void output_some(Vector<T> &a, const std::string Begin = "", const std::string end = " ", const std::string Lend = "\n") {
		for (T x : a)
			output(x, Begin, end);
		std::cout << Lend;
	}

	// 20_2
	template<typename T>
	void input_some_a_to_b(Vector<T> &a, const int A, const int B) {
		for (int i = A; i <= B; ++i)
			input(a[i]);
	}

	// 21_2
	template<typename T>
	void output_some_a_to_b(Vector<T> &a, const int A, const int B, const std::string Begin = "", const std::string end = " ", const std::string Lend = "\n") {
		for (int i = A; i <= B; ++i)
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
	void run_to_some(Vector<T> &a, const int step = 1) {
		for (int i = 0; i < a.size(); i += step)
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
	void fill_random(Vector<T> &nums, int len, long long max_rand) {
		for (int i = 0; i < len; i++)
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
