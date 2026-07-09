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
int* a = (int*)malloc(N*sizeof(int));
int* b = (int*)malloc(N*sizeof(int));
int parent[N];
int len[N];

void sol()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i=0; i<m; i++) {
		scanf("%d", &b[i]);
	}

	int *x, *y, xlen, ylen;
	if(n>=m) {
		x = a;
		y = b;
		xlen = n;
		ylen = m;
	} else {
		x = b;
		y = a;
		xlen = m;
		ylen = n;
	}
	for(int i=0; i<xlen; i++) {
		parent[i]=-1;
		len[i]=-1;
	}

	int max = -1;
	int last = -1;

	for(int i=0; i<ylen; i++) {
		int nmax = -1;
		int llast = -1;

		for(int j=0; j< xlen; j++) {
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
	stack<int> s;

	while(parent[last]!=-1) {
		s.push(last);
		last = parent[last];
	}
	while(!s.empty()) {
		printf("%d ", x[s.top()]);
		s.pop();
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
