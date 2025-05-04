//namespace much {
//too long locomotive......
#ifndef _imported_mfdef
#define _imported_mfdef
#define Vd void
#define I_16 short
#define I_32 int
#define I_64 long long
#define _B bool
#define Db double
#define Chr char
#define STR std::string
#define _T true
#define _F false
#define _R return
#define mPI 3.1415926535
#define mE 2.71828182845
// This macro(29) was in 'much_func.h'.
#define caria(r) (mPI * r * r)
// This macro(31) was in 'much_func.h'.
#define cround(r) (2 * mPI * r)
#define mset(a, n) memset(a, n, sizeof(a))
#define mdst(x1, y1, x2, y2) sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2))
#define _rep(i, a, b) for (i = a; i <= b; i++)
#define _for(i, a, b) for (i = a; i < b; i++)
#if __cplusplus >= 201103L
	#define _range_for(i, _range) for (auto i : _range)
#endif
#define _check(c, a, b) (c ? a : b)
// This macro(32) was in 'much_func.h'.
#define negation(BOOL_VAL) BOOL_VAL = !BOOL_VAL
#define is_lyear(y) (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
#define random_init srand(time(NULL))
//}
#endif
