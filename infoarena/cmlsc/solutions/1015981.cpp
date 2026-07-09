#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <assert.h>
using namespace std;

const string file = "cmlsc";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f;

int N, M;
int Sol = 0;

vector<int> A, B;
vector<vector<int> > DP;


int main()
{
	fstream fin(infile.c_str(), ios::in);
	
	fin >> N >> M;
	N++;
	M++;
	DP.resize(N, vector<int>(M));
	A.resize(N);
	B.resize(M);

	for(int i = 1; i < N; i++)
	{
		fin >> A[i];
	}
	for(int i = 1; i < M; i++)
	{
		fin >> B[i];
	}

	fin.close();

	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < M; j++)
		{
			if(A[i] == B[j])
			{
				DP[i][j] = DP[i-1][j-1] + 1;
				Sol = max(Sol, DP[i][j]);
			}
			else
			{
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
			}
		}
	}

	fstream fout(outfile.c_str(), ios::out);
	fout << Sol << "\n";
	vector<int> recons;
	recons.reserve(Sol);

	for(int i = N - 1, j = M - 1; i && j;)
	{
		if(A[i] == B[j])
		{
			recons.push_back(A[i]);
			i--;
			j--;
		}
		else if(DP[i-1][j] > DP[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}

	for(vector<int>::reverse_iterator itr = recons.rbegin();
		itr != recons.rend();
		itr++)
	{
		fout << *itr << " ";
	}


	fout.close();
}
