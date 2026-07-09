#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <cstdlib>

using namespace std;

#define INPUT "source.in"
#define IN "cmlsc.in"
#define OUT "cmlsc.out"

#define N 1024

int n, m;
short* x = (short*)malloc(N*sizeof(short));
short* y = (short*)malloc(N*sizeof(short));
short parent[N];
short len[N];

void sol()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", &x[i]);
	}
	for(int i=0; i<m; i++) {
		scanf("%d", &y[i]);
	}
	for(int i=0; i<n; i++) {
		parent[i]=-1;
		len[i]=-1;
	}

	short max = -1;
	short last = -1;

	for(int i=0; i<m; i++) {
		short nmax = -1;
		short llast = -1;

		for(int j=0; j< n; j++) {
			if(x[j]==y[i]) {
				if(nmax+1>len[j]) {
					len[j]=nmax+1;
					nmax++;
					parent[j]=nmax==0 ? 0 : llast;
					llast=j;
					continue;
				}
			}
			if(len[j]>nmax) {
				nmax = len[j];
				llast = j;
				continue;
			}
		}
		if(nmax>max) {
			max = nmax;
			last = llast;
		}
	}

	printf("%d\n", max+1);

	int start=0;
	while(last!=-1 && parent[last]!=-1) {
		len[start++] = last;
		last = parent[last];
	}
	for(int i=start-1; i>=0; i--) {
		printf("%d ", x[len[i]]);
	}
	printf("\n");
}

int main()
{
#ifdef PADREATI
	freopen(INPUT, "r", stdin);
#else
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
#endif
	sol();
	return 0;
}
