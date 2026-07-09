#include <bits/stdc++.h>

void read(int arr[], int p, int r) {
	for(int i = p; i <= r; i++) scanf("%d", arr + i);
}

int main () {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	int a[1024] = {}, b[1024] = {}, m, n;
	scanf("%d%d", &m, &n);
	read(a, 0, m - 1); read(b, 0, n - 1);
	
	int solver[1024] = {}, tt = 0;	
	
	for(int i = 0; i < m; i++)
	for(int j = 0; j < n; j++) {
	if(a[i] == b[j]) solver[tt++] = a[i];
	}
	
	printf("%d\n", tt);
	for(int i = 0; i < tt; i++) printf("%d ", *(solver + i));
}