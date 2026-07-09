#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stdio.h>
#include <iostream>
using namespace std;

#ifdef _WIN32
#define TYPEOF decltype
#else
#define TYPEOF typeof
#endif

#define FOR(i,s,e) for(int i = s;i < e; i++)
#define TR(i, c) for(TYPEOF(c.begin()) i = c.begin(); i != c.end(); ++i)
#define TRS(i, c, ...) TR(__itr, c) { TYPEOF(*c.begin()) &i = *__itr;  __VA_ARGS__ }
#define TRP(f, s, c, ...) TR(__itr, c) { TYPEOF(c.begin()->first) &f = __itr->first; TYPEOF(c.begin()->second) &s = __itr->second;  __VA_ARGS__ }

int main()
{
#if 1
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		if(a < b) {
			int c = a;
			a = b;
			b = c;
		}

		while(a != b && b > 0)
		{
			int m = a % b;
			a = b;
			b = m;
		}

		//if(a == 1) a = 0;

		printf("%d\n", a);
	}
	return 0;
}
