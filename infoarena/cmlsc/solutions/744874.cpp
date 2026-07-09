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


int a[2048], b[2048];
int c[2048][2048];
int d[2048];

#ifdef MY_STUFF
//static
#endif
int main()
{
#if 1
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
#endif

	int na, nb;
	scanf("%d %d\n", &na, &nb);

	FOR(i, 0, na) scanf("%d", &a[i]);
	FOR(i, 0, nb) scanf("%d", &b[i]);

	bool found = false;
	FOR(i, 1, na+1)
		FOR(j, 1, nb+1)
			if(a[i-1] == b[j-1])
				c[i][j] = 1 + c[i-1][j-1];
			else
				c[i][j] = max(c[i-1][j], c[i][j-1]);

	printf("%d\n", c[na][nb]);



	for(int i = na, j = nb, k = c[na][nb]-1; j > 0 && i > 0; ) {
		if(a[i-1] == b[j-1]) {
			d[k--] = a[i-1];
			i--,j--;
		} else
			if(c[i-1][j] > c[i][j-1])
				i--;
			else 
				j--;
	}

	FOR(i, 0, c[na][nb])
		printf("%d ", d[i]);

	return 0;
}