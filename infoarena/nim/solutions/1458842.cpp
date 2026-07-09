
#include <stdio.h>
#include <string.h>
int v[10001];

void Solve() {
	int N, s = 0;
	memset(v, 0, sizeof(v));
	scanf("%d %d", &N, &v[1]);

	s = v[1]; 
	for(register int i = 1; i < N; ++ i)
		scanf("%d", &v[i + 1]), s = s xor v[i + 1];

	if(s)
		puts("DA");
	else
		puts("NU");
}
int main() {

	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	int T;
	scanf("%d", &T);

	while(T --)
		Solve();
	return 0;
}