#include <cstdio>
#include <vector>
#include <stack>
#define pb(x) push_back(x)
#define max(a,b) a>b?a:b

int main(){
	std::vector<int> A, B;
	std::stack<int> C;
	int M, N, x, i, j;
	int **c;
	
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%d %d", &M, &N);
	
	for(i = 0; i < M; i++) scanf("%d", &x),A.pb(x);
	for(j = 0; j < N; j++) scanf("%d", &x),B.pb(x);
	
	c = new int*[1024];
	for(i = 0; i < 1024; i++) c[i] = new int[1024];
	
	for(std::vector<int>::iterator jt = B.begin(); jt != B.end(); jt++)
		for(std::vector<int>::iterator it = A.begin(); it != A.end(); it++)
			if (*it == *jt)
				if (it == A.begin() || jt == B.begin())
					c[it - A.begin()][jt - B.begin()] = 1;
				else
					c[it - A.begin()][jt - B.begin()] = c[it - A.begin() - 1][jt - B.begin() - 1] + 1;
			else{
				if (it == A.begin() && jt == B.begin()){
					c[it - A.begin()][jt - B.begin()] = 0;
					continue;
				}
				if (it == A.begin()){
					c[it - A.begin()][jt - B.begin()] = c[it - A.begin()][jt - B.begin() - 1];
					continue;
				}
				if (jt == B.begin()){
					c[it - A.begin()][jt - B.begin()] = c[it - A.begin() - 1][jt - B.begin()];
					continue;
				}
				c[it - A.begin()][jt - B.begin()] = max(c[it - A.begin() - 1][jt - B.begin()], c[it - A.begin()][jt - B.begin() - 1]);
			}

	printf("%d\n", c[M---1][N---1]);
	while(M>=0 && N>=0 && c[M][N]){
		while(M && c[M][N] == c[M-1][N]) --M;
		while(N && c[M][N] == c[M][N-1]) --N;
		C.push(*(A.begin() + M));
		--N;--M;
	}
	
	while(!C.empty())
		printf("%d ", C.top()),C.pop();
	printf("\n");
	
	delete[] c;
	c = 0;
	
	return 0;
}
