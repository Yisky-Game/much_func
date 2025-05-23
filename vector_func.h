#ifndef _imported_vector_func
#define _imported_vector_func
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <random>
using std::vector;
namespace much {
    // operator
    template<typename T>
    std::ostream& operator <<(std::ostream& outs, vector<T> &a) {
        for (auto x : a)
            outs << x << ' ';
        return outs;
    }

    template<typename T>
    std::istream& operator >>(std::istream& ins, vector<T> &a) {
        for (int i = 0; i < a.size(); i++)
            ins >> a[i];
        return ins;
    }
	// iofunc.h
	// 10_2
	template<typename T>
	void input_some(vector<T> &a, const int len) {
		for (int i = 0; i < len; i++) {
			T sth = input(sth);
			a.push_back(sth);
		}
	}

	// 11_2
	template<typename T>
	void output_some(vector<T> &a, const std::string Begin = "", const std::string end = " ", const std::string Lend = "\n") {
		for (T x : a)
			output(x, Begin, end);
		std::cout << Lend;
	}

	// 20_2
	template<typename T>
	void input_some_a_to_b(vector<T> &a, const int A, const int B) {
		for (int i = A; i <= B; ++i)
			input(a[i]);
	}

	// 21_2
	template<typename T>
	void output_some_a_to_b(vector<T> &a, const int A, const int B, const std::string Begin = "", const std::string end = " ", const std::string Lend = "\n") {
		for (int i = A; i <= B; ++i)
			output(a[i], Begin, end);
		std::cout << Lend;
	}


	// much_func.h
	// 5_2
	template<typename T>
	double avg(vector<T> &nums) {
		T sum = std::accumulate(nums.begin(), nums.end(), T(0));
		return static_cast<double>(sum) / nums.size();
	}

	// 9_2
	template<typename T>
	T sum_some(vector<T> &a) {
		return std::accumulate(a.begin(), a.end(), T(0));
	}

	// 12_2
	template<typename T>
	void n_to_some(vector<T> &a, const T n) {
		std::fill_n(a.begin(), a.size(), n);
	}

	// 16_2
	template<typename T>
	T nums_max(vector<T> &nums) {
		return *std::max_element(nums.begin(), nums.end());
	}

	// 17_2
	template<typename T>
	T nums_min(vector<T> &nums) {
		return *std::min_element(nums.begin(), nums.end());
	}

	// 22_2
	template<typename T>
	void run_to_some(vector<T> &a, const int step = 1) {
		for (int i = 0; i < a.size(); i += step)
			a[i] = i;
	}

	// 25_2
	template<typename T>
	void reverse_some(vector<T> &a) {
		std::reverse(a.begin(), a.end());
	}

	// 27_2
	// wrong.
	
	// 29_2
	template <typename T>
	vector<T> merge(vector<T> a, vector<T> b, vector<T>& obj) {
		obj = a;
		for (auto x : b)
			obj.emplace_back(x);
		return obj;
	}

	// 31_3
	template <typename rT>
	void fill_random(vector<int> *nums, rT rtype, const int len, const int maxr) {
		for (int i = 0; i < len; i++)
			nums[i] = rtype() % maxr;
	}
	
	// 31_4
	template <typename rT>
	void fill_random(vector<long long> *nums, rT rtype, const int len, const long long maxr) {
		for (int i = 0; i < len; i++)
			nums[i] = rtype() % maxr;
	}
	
    // 33_3
	// Please call srand(time(NULL))
	template <typename T>
	void fill_random(vector<T> &nums, long long maxr) {
		int len = nums.size();
		for (int i = 0; i < len; i++)
			nums[i] = rand() % maxr;
	}
	
	// 33_4
	// Please call srand(time(NULL))
	template <typename T>
	void fill_random(vector<T> &nums, int maxr) {
		int len = nums.size();
		for (int i = 0; i < len; i++)
			nums[i] = rand() % maxr;
	}
	
	// 41
	template<typename T>
	vector<T> vector_range(T len, T _begin = 0, T step = 1) {
		vector<T> Range;
		T num = _begin;
		for (T i = 0; i < len; i++) {
			Range.push_back(num);
			num += step;
		}
		return Range;
	}
	
	// 42_2
	template <typename T, typename _rdt, typename _sdt>
	void fill_random_ab(vector<T>& nums, const T a, const T b, const _sdt sd) {
		std::default_random_engine eng;
		_rdt rd(a, b);
		eng.seed(sd);
		int len = nums.size();
		for (int i = 0; i < len; i++)
			nums[i] = rd(eng);
	}
}
#endif
