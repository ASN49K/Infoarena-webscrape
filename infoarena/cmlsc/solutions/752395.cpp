#include <cstdio>
#include <algorithm>
#define DMAX 1030
using namespace std;

int A [DMAX], B [DMAX], sol [DMAX];
int nume [DMAX] [DMAX];

int main () {
	
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int n, m, i, j;
	
	scanf ("%d%d", &n, &m);
	
	for (i = 1; i <= n; ++ i)
		scanf ("%d", &A [i]);
	
	for (i = 1; i <= m; ++ i)
		scanf ("%d", & B [i]);
	
	for (i = 1; i <= n; ++ i)
		for (j = 1; j <= m; ++ j) {
			if( A [i] == B [j])
				nume [i] [j] = nume [i - 1] [j - 1] + 1;
			else
				nume [i] [j] = max (nume [i - 1] [j], nume [i] [j - 1]);
		}
	
	for (i = n, j = m; i && j;) {
		if (A [i] == B [j]) {
			sol [++ sol [0]] = A [i];
			-- i; -- j;
		}
		else {
			if (nume [i - 1] [j] > nume [i] [j - 1]) -- i;
			else -- j;
		}
	}
	
	printf ("%d\n", nume [n] [m]);
	for (i = sol [0]; i >= 1; -- i)
		printf ("%d ", sol [i]);
	printf ("\n");
}
