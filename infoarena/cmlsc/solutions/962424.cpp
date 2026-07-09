#include <cstdio>
#include <vector>
#define pb(x) push_back(x)
#define max(a,b) a>b?a:b

void print(std::vector<int> a);

int main(){
	std::vector<int> A, B, C;
	int M, N, x, i, j;
	int **c;
	
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%d %d", &M, &N);
	
	for(i = 0; i < M; i++) scanf("%d", &x),A.pb(x);
	for(j = 0; j < N; j++) scanf("%d", &x),B.pb(x);
	
	c = new int*[1024];
	for(i = 0; i < 1024; i++) c[i] = new int[1024];
	
	for(std::vector<int>::iterator it = A.begin(); it != A.end(); it++)
		for(std::vector<int>::iterator jt = B.begin(); jt != B.end(); jt++){
			if (*it == *jt){
				if (it == A.begin() && jt == B.begin()){
					c[it - A.begin()][jt - B.begin()] = 1;
					continue;
				}
				if (it == A.begin()){
					c[it - A.begin()][jt - B.begin()] = c[it - A.begin()][jt - B.begin()] + 1;
					continue;
				}
				if (jt == B.begin()){
					c[it - A.begin()][jt - B.begin()] = c[it - A.begin() - 1][jt - B.begin()] + 1;
					continue;
				}
				c[it - A.begin()][jt - B.begin()] = c[it - A.begin() - 1][jt - B.begin() - 1] + 1;
			}
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
				c[it - A.begin()][jt - B.begin()] = max(c[it - A.begin() - 1][jt - B.begin()],c[it - A.begin()][jt - B.begin() - 1]);
			}
		}
	
	printf("%d\n", c[M---1][N---1]);
	while(M && N){
		while(M && c[M][N] == c[M-1][N]) --M;
		while(N && c[M][N] == c[M][N-1]) --N;
		if (c[M][N]) C.pb(*(A.begin() + M));
		--N;
	}
	
	for(std::vector<int>::iterator it = C.end() - 2; it != C.begin() - 1; it--)
		printf("%d ", *it);
	printf("\n");
	
	delete[] c;
	c = 0;
	
	return 0;
}

void print(std::vector<int> a){
	std::vector<int>::iterator it;
	for(it = a.begin(); it != a.end(); it++)
		printf("%d ", *it);
	printf("\n");
	return;
}
