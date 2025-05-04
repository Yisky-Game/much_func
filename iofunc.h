//much_func: I/O function.
#ifndef _imported_iofunc
#define _imported_iofunc
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using std::cin;
using std::cout;
using std::string;
using std::istream;
using std::ostream;
#define fastcinout ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define __input(__tp, __a) \
template <typename T> \
istream& operator >>(istream& istr, std::__tp<T>& __a) { \
	T __x; \
	while (istr >> __x)  \
		__a.push(__x); \
	return istr; \
}
#define __output(__tp, __a, __f) \
template<typename T> \
ostream& operator <<(ostream& ostr, std::__tp<T> __a) { \
	while (!__a.empty()) \
		ostr << at_##__f(__a) << ' '; \
	return ostr; \
}
namespace much {
	// 6
	template<typename T>
	T input(T &sth) {
		cin >> sth;
		return sth;
	}

	// 7
	template<typename T>
	void output(const T sth, const string Begin = "", const string end = " ") {
		cout << Begin << sth << end;
	}

	// 8
	void digit_output(const double n, const int sp) {
		cout << std::fixed << std::setprecision(sp) << n;
	}

	// 10_1
	template<typename T>
	void input_some(T *a, const int len) {
		for (int i = 0; i < len; ++i)
			input(a[i]);
	}

	// 11_1
	template<typename T>
	void output_some(const T *a, const int len, const string Begin = "", const string end = " ", const string Lend = "\n") {
		for (int i = 0; i < len; ++i)
			output(a[i], Begin, end);
		cout << Lend;
	}

	// 15
	string input_stlstr(void) {
		string str;
		getline(cin, str);
		return str;
	}

	// 18_1
	void nextl(void) {
		putchar('\n');
	}

	// 18_2
	void backl(void) {
		putchar('\b');
	}

	// 20_1
	template<typename T>
	void input_some_a_to_b(T *a, const int A, const int B) {
		for (int i = A; i <= B; ++i)
			input(a[i]);
	}

	// 21
	template<typename T>
	void output_some_a_to_b(const T *a, const int A, const int B, const string Begin = "", const string end = " ", const string Lend = "\n") {
		for (int i = A; i <= B; ++i)
			output(a[i], Begin, end);
		cout << Lend;
	}

	// 34
	template <typename T>
	T fast_read(T &m) {
		T n = 0; int f = 1;
		char c = getchar();
		while (c < '0' || c >= '9') {
			if (c == '-') f = -1;
			c = getchar();
		}
		while ('0' <= c && c <= '9') {
			n = (n << 3) + (n << 1) + (c ^ 48);
			c = getchar();
		}
		m = n * f;
		return m;
	}

	// 35
	template <typename T>
	void fast_write(T n) {
		if (n < 0) {
			putchar('-');
			n = -n;
		}
		if (n > 9) fast_write(n / 10);
		putchar(n % 10 + '0');
	}
	
	// helper 'much_func.h' and 'iofunc.h' .
	// 36_1
	template <typename T>
	T at_front(std::queue<T> &_q) {
		T tmp = _q.front();
		_q.pop();
		return tmp;
	}
	
	// 36_2
	template <typename T>
	T at_front(std::priority_queue<T> &_pq) {
		T tmp = _pq.front();
		_pq.pop();
		return tmp;
	}
	
	// 36_3
	template <typename T>
	T at_top(std::stack<T> &_stk) {
		T tmp = _stk.top();
		_stk.pop();
		return tmp;
	}
	
	// operator
	// 37_1
	__output(queue, _q, front)
	// 37_2
	__output(priority_queue, _q, front)
	// 37_3
	__output(stack, _stk, top)
#ifdef _INT128_DEFINED
	// _38
	ostream& operator <<(ostream& ostr, __int128 i128) {
		fast_write(i128);
		return ostr;
	}
	// _39
	istream& operator >>(istream& istr, __int128 i128) {
		fast_read(i128);
		return istr;
	}
#endif
	// 40_1
	__input(queue, _q)
	// 40_2
	__input(priority_queue, _q)
	// 40_3
	__input(stack, _stk)
}
#endif
