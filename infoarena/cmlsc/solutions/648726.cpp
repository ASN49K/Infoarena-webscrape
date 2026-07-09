#include<cstdio>
#include<vector>
#include<iostream>
#define max(a,b) a > b ? a : b
using namespace std;

int n, m;
vector <int> a, b;
vector <vector <int> > lng;

void AfiseazaSol(int x, int y){
	/*
	Caut cea mai din dreapta sus pozitie care a fost actualizata pe diagonala. In exemplu pozitiile sunt incercuite
	0 7 5 8 
	1 0 0 0 
	7 (1) 1 1 
	3 1 1 1 
	9 1 1 1 
	8 1 1 (2) 
	*/
	if (lng[x][y] == 0) return;
	int i, j;
	
	for (j = y; j >= 1 && lng[x][j] == lng[x][j-1]; j--);
	for (i = x; i >= 1 && lng[i][j] == lng[i-1][j]; i--);
	
	AfiseazaSol(i - 1, j - 1);
	printf("%d ", a[i]);
}

int main(){
	freopen("cmlsc.in", "r", stdin), freopen("cmlsc.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int i, j;
	a.assign(n + 1, 0);
	b.assign(m + 1, 0);
	lng.resize(n + 1);
	for (i = 0; i <= n; i++) lng[i].resize(m + 1);
	
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 1; i <= m; i++) scanf("%d", &b[i]);
	
	for (i = 0; i <= n; i++) 
		for (j = 0; j <= m; j++) lng [i][j] = 0;
	
	for (i = 1; i <= n; i++) 
		for (j = 1; j <= m; j++)
			if (a[i] == b[j]) lng[i][j] = lng[i-1][j-1] + 1;
			else lng[i][j] = max (lng[i-1][j], lng[i][j-1]);
	
	printf("%d\n", lng[n][m]);
	AfiseazaSol(n, m);
	return 0;
}
