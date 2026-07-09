#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

#define DMAX 1025
#define MOD 1999999973
#define ll long long
#define ull unsigned long long

int N, M;
vector<int> A, B;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main(){
	int i, j;

	//freopen("cmlsc.in", "r", stdin);
	//freopen("cmlsc.out", "w", stdout);
	/*freopen("test.in", "r", stdin);	
	freopen("test.out", "w", stdout);*/

	fin >> N >> M;
	vector<vector<int> > cmlsc;
	cmlsc.resize(N + 1);
	for (i = 0; i <= N; i++) cmlsc[i].resize(M + 1);
	
	for (i = 0; i < N; i++) fin >> j, A.push_back(j);
	for (i = 0; i < M; i++) fin >> j, B.push_back(j);

	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			if (A[i - 1] == B[j - 1]){
				cmlsc[i][j] = 1 + cmlsc[i - 1][j - 1];
			}
			else{
				cmlsc[i][j] = max(cmlsc[i][j], max(cmlsc[i - 1][j], cmlsc[i][j - 1]));
			}
		}
	}

	fout << cmlsc[N][M] << '\n';

	int lg = 0;
	for (i = 1, j = 1; i <= N; i++){
		if (cmlsc[i][j] > cmlsc[i - 1][j - 1]){
			fout << B[j++] << ' ';
		}
	}

	return 0;
}
