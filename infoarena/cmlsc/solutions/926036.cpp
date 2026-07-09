#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int C[1025][1025];
int A[1024], B[1024];

void read(){
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	cin >> M >> N ;
	for(int i = 0; i < M ; i ++ ){
		cin >> A[i];
	}

	for(int j = 0; j < N; j++){
		cin >> B[j];
	}
}

int computeLCS(){
	memset(C, 0, sizeof(C));
	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= N; j++){
			if(A[i - 1] == B[j - 1]){
				C[i][j] = C[i-1][j-1] + 1;
			}else{
				C[i][j] = max(C[i-1][j], C[i][j-1]);
			}
		}
	}
	return C[M][N];
}

vector<int> recomposeSequence(int i, int j, vector<int> sol){
	if(i == 0  || j == 0){
		return sol;
	}else{
		if(A[i - 1] == B[j - 1]){
			sol.push_back(A[i-1]);
			return recomposeSequence(i-1, j-1, sol);
		}else{
			if(C[i-1][j] > C[i][j-1]){
				return recomposeSequence(i-1, j, sol);
			}else
				return recomposeSequence(i, j-1, sol);
		}
	}
}


int main(){
	read();
	cout << computeLCS() << endl;
	vector<int> sol;
	vector<int> res = recomposeSequence(M, N, sol);
	reverse(res.begin(), res.end());
	if(res.size() != 0)
		cout << res[0] ;
	for(int i = 1; i < res.size(); i++){
		cout << " " << res[i];
	}
	cout << endl;
	cout.flush();
	return 0;
}

