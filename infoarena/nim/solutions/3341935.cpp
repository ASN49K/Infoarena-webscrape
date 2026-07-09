//https://infoarena.ro/problema/nim

//#ifdef _MSC_VER
//	#define _CRT_SECURE_NO_WARNINGS
//#elif  __GNUC__
//	#pragma GCC optimize("Ofast,unroll-loops,inline")
//	#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//#endif

//#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <utility>
#include <cstdint>
//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include <array>
//#include <list>
//#include <forward_list>
//#include <string>
//#include <cstring>
//#include <cmath>
//#include <bitset>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <limits>
//#include <climits>
//#include <iomanip>
//#include <tuple>
//#include <numeric>
//#include <chrono>
//#include <memory>

using namespace std;

using int64 = int64_t;
using uint64 = uint64_t;
using int16 = int16_t;
using uint16 = uint16_t;
using pii = pair<int, int>;
using pll = pair<int64, int64>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define for0(i,n) for(auto i=0; i<(n); ++i)
#define rfor0(i,n) for(auto i=(n)-1; i>=0; --i)
#define for1(i,n) for(auto i=1; i<=(n); ++i)
#define rfor1(i,n) for(auto i=(n); i>=1; --i)
#define foreach(x,a) for(auto& x : a)
#define cforeach(x,a) for(const auto& x : a)
#define cendl cout << "\n"
#define fendl fout << "\n"
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

ifstream fin("nim.in");
ofstream fout("nim.out");

//FILE* fin = fopen("", "r");
//FILE* fout = fopen("", "w");


int main()
{
	//FASTIO;

	int t, n, i, x, sum;

	fin >> t;
	while(t--)
	{
		fin >> n;

		sum = 0;
		for0(i, n)
		{
			fin >> x;
			sum ^= x;
		}

		if (sum)
			fout << "DA\n";
		else
			fout << "NU\n";
	}

	return 0;
}
