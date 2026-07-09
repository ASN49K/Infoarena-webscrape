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
using namespace std;

const string file = "cmlsc";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f;
int N, M;
vector<int> A;
vector<int> B;

vector<vector<int> > Best;
vector<vector<int> > Prec;
int Sol = 0;
int maxI;
int maxJ;


void printSol(int i, int j, int sol, ostream& fout)
{
	if(sol == 0)
		return;


	if(Prec[i][j] == 0)
	{
		printSol(i - 1, j - 1, sol - 1, fout);
		fout << A[i] << " ";
	}
	else if(Prec[i][j] == 1)
	{
		printSol(i -1, j, sol, fout);
	}
	else //if(Prec[i][j] == 2
	{
		printSol(i, j -1, sol, fout);
	}

}

int main()
{
	fstream fin(infile.c_str(), ios::in);
	fin >> N >> M;
	A.resize(N + 1);
	B.resize(M + 1);
	Prec.resize(N + 1, vector<int>(M+1));
	Best.resize(N + 1, vector<int>(M + 1));


	for(int i = 1; i <= N; i++)
		fin >> A[i];
	for(int j = 1; j <= M; j++)
		fin >> B[j];
	fin.close();



	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if(A[i] == B[j])
			{
				Best[i][j] = Best[i-1][j-1] + 1;
				Prec[i][j] = 0;

				Sol = max(Sol, Best[i][j]);
				if(Sol == Best[i][j])
				{
					maxI = i;
					maxJ = j;
				}
			}
			else
			{
				Best[i][j] = max(Best[i-1][j], Best[i][j-1]);
				if(Best[i][j] == Best[i-1][j])
				{
					Prec[i][j] = 1;
				}
				else
				{
					Prec[i][j] = 2;
				}
			}
			
		}
	}



	fstream fout(outfile.c_str(), ios::out);
	fout << Sol << "\n";
	printSol(maxI, maxJ, Sol, fout);
	fout << "\n";
	fout.close();
}