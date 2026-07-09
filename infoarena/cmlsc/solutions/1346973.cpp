///CMLSC
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream inStr("cmlsc.in");
	ofstream outStr("cmlsc.out");

	int N, M;
	inStr >> N >> M;
	
	vector<vector<int> > best(N+1, vector<int>(M+1, 0));
	vector<vector<int> > direction(N+1, vector<int>(M+1));
	vector<int> A(N);
	vector<int> B(M);

	for(int i=0; i<N; ++i)
		inStr >> A[i];
	for(int i=0; i<M; ++i)
		inStr >> B[i];

	for(int i=1; i<=N; ++i)
		for(int j=1; j<=M; ++j)
			if(A[i-1] == B[j-1]) {
				best[i][j] = best[i-1][j-1] + 1;
				direction[i][j] = 2;
			}
			else {
				best[i][j] = max(best[i][j-1], best[i-1][j]);
				if(best[i][j] == best[i][j-1])
					direction[i][j] = 1;
				else
					direction[i][j] = 3;			
			}

	outStr << best[N][M] << '\n';

	vector<int> answ(best[N][M]);
	int curr = answ.size() - 1;
	int i = N, j = M;
	
	while(best[i][j] > 0) 
		switch(direction[i][j]) {
		case 1:
			--j;
			break;
		case 2:
			answ[curr] = B[j-1];			
			--i;
			--j;
			--curr;
			break;
		case 3:
			--i;
			break;			
		}

	for(int i=0; i<best[N][M]; ++i)
		outStr << answ[i] << ' ';
	outStr << '\n';

	return 0;
}
