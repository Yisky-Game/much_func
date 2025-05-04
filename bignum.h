#ifndef _imported_bignum
#define _imported_bignum
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using std::string;
#define calc_c __helper_bignum::__div c = __helper_bignum::calc(a, b)
namespace much{
    class bignum {
        private:
            int len, s[460];
            void clean() { while (len > 1 && !s[len - 1]) len--; }
        public:
            bignum() { memset(s, 0, sizeof(s)); len = 1; }
            bignum(int num) { *this = num; }
			bignum(long long num) { *this = num; }
            bignum(const char* num) { *this = num; }
            bignum(const string num) { *this = num; }
            bignum(bignum& num) { *this = num.to_str(); }
			
			bignum operator = (bignum num) {
				len = num.len;
				std::memcpy(s, num.s, sizeof(int) * num.len);
				return *this;
			}
            bignum operator = (int num) {
                char str[460];
                sprintf(str, "%d", num);
                *this = str;
                return *this;
            }
			bignum operator = (long long num) {
				char str[460];
				sprintf(str, "%lld", num);
				*this = str;
				return *this;
			}
            bignum operator = (const char* num) {
                len = strlen(num);
                for (int i = 0; i < len; i++) s[i] = num[len - i - 1] - '0';
                return *this;
            }
            bignum operator = (const string num) {
                len = num.size();
                *this = num.c_str();
                return *this;
            }
            string to_str() const {
                string res = "";
                for (int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
                if (res == "") res = "0";
                return res;
            }

            int& operator [](const int& i) {
                return s[len - 1 - i];
            }

            bignum operator +(const bignum& b) const {
                bignum c;
                c.len = 0;
                for (int i = 0, g = 0; g || i < std::max(len, b.len); i++) {
                    int x = g;
                    if (i < len) x += s[i];
                    if (i < b.len) x += b.s[i];
                    c.s[c.len++] = x % 10;
                    g = x / 10;
                }
                return c;
            }
            bignum operator -(const bignum& b) const {
                bignum c;
                c.len = 0;
                for (int i = 0, g = 0; i < len; i++) {
                    int x = s[i] - g;
                    if (i < b.len) x -= b.s[i];
                    if (x >= 0) g = 0;
                    else {
                        g = 1;
                        x += 10;
                    }
                    c.s[c.len++] = x;
                }
                c.clean();
                return c;
            }
            bignum operator *(const bignum& b) const {
                bignum c;
                c.len = len + b.len;
                for (int i = 0; i < len; i++)
                    for (int j = 0; j < b.len; j++)
                        c.s[i + j] += s[i] * b.s[j];
                for (int i = 0; i < c.len - 1; i++) {
                    c.s[i + 1] += c.s[i] / 10;
                    c.s[i] %= 10;
                }
                c.clean();
                return c;
            }
			
		public:
            bool operator <(const bignum& b) const {
                if (len != b.len) return len < b.len;
                for (int i = len - 1; i >= 0; i--)
                    if (s[i] != b.s[i]) return s[i] < b.s[i];
                return false;
            }
            bool operator >(const bignum& b) const { return b < *this; }
            bool operator <=(const bignum& b) const { return !(b > *this); }
            bool operator >=(const bignum& b) const { return !(b < *this); }
            bool operator ==(const bignum& b) const { return !(b < *this) && !(b > *this); }
            bool operator !=(const bignum& b) const { return !(b == *this); }
            bignum operator +=(const bignum& b) { *this = *this + b; return *this; }
            bignum operator -=(const bignum& b) { *this = *this - b; return *this; }
            bignum operator *=(const bignum& b) { *this = *this * b; return *this; }
			bignum operator ++(int) { return *this += 1; }
			bignum operator --(int) { return *this -= 1; }
    };
	
	/* wrong. It will be released in '4.0-Pre' version.
	namespace __helper_bignum {
		struct __div{
			bignum ans, rem;
			__div(bignum _ans, bignum _rem) { ans = _ans; rem = _rem; }
		};
		__div calc(bignum a, const bignum& b) {
			if (b == 0)
				throw "The divisor must not be 0.";
			if (a < b)
				return __div(0, a);
			bignum x(0);
			while (a >= b) {
				a -= b;
				x++;
			}
			return __div(x, a);
		}
	}
	bignum operator /(bignum a, const bignum& b) {
		calc_c;
		return c.ans;
	}
	bignum operator %(bignum a, const bignum& b) {
		calc_c;
		return c.rem;
	}
	*/
	
    std::istream& operator >> (std::istream& instr, bignum& x) {
        std::string s;
        instr >> s;
        x = s;
        return instr;
    }
    std::ostream& operator << (std::ostream& outstr, const bignum& x) {
        outstr << x.to_str();
        return outstr;
    }
	
    bignum big_fac(int num = 0) {
		bignum facn(1);
		for (int i = 2; i <= num; i++)
			facn *= bignum(i);
		return facn;
	}
	bignum big_pow(int n, int m = 0) {
		bignum pown(1);
		if (m == 0)
            return pown;
		for (int i = 1; i <= m; i++)
			pown *= bignum(n);
		return pown;
	}
}
#endif
