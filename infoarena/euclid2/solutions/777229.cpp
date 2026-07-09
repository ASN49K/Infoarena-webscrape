/*****
 *	NAME:
 *	ROUND:
 *	TIME:
 *	ABOUT:
 **/

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

#define hh 123077
#define HH 999983
#define PI 3.14159265

#define inf 0x7FFFFFFF
#define ninf -0x80000000

#define i64 long long
#define ui64 unsigned long long

#define reset(a) memset(a, 0, sizeof(a))

#define wrv(a) cout << a
#define wra(a, b, e) for(int idx = b; idx <= e; ++ idx) cout << a[idx] << ' '
#define wrm(a, bi, ei, bj, ej) for(int idi = bi; idi <= ei; ++ idi) {for(int idj = bj; idj <= ej; ++ idj) cout << a[idi][idj] << ' '; cout << '\n';}

#define swap(x, y) x ^= y, y ^= x, x ^= y

ifstream fi;
ofstream fo;

inline int cmmdc(int x, int y)
{
    if(y == 0) return x;
    return cmmdc(y, x % y);
}

int main()
{
	/*freopen(".in", "r", stdin);*/
	/*freopen(".out", "w", stdout);*/

    int T, x, y;

	fi.open("euclid2.in");
	fo.open("euclid2.out");

    fi >> T;

    while(T -- )
    {
        fi >> x >> y;
        fo << cmmdc(x, y) << '\n';
    }

    fi.close();
    fo.close();

	return 0;
}


