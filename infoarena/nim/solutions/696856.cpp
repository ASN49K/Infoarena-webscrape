#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
	freopen ("nim.in", "r", stdin);
	freopen ("nim.out", "w", stdout);
	
	int T;
	
	scanf ("%d", &T);
	
	while (T --)
	{
		int N, XorS = 0;
		
		scanf ("%d", &N);
		
		for (int i = 1, a; i <= N; ++ i) scanf ("%d", &a), XorS ^= a;
		
		if (XorS) printf ("DA\n");
		else printf ("NU\n");
	}
	
	return 0;
}
