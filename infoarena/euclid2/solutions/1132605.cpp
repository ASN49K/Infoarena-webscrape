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
#include <random>
#include <assert.h>
using namespace std;

const string file = "cmlsc";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f; 

//#define ONLINE_JUDGE

int main()
{
#ifdef ONLINE_JUDGE
	ostream &fout = cout;
	istream &fin = cin;
#else
	fstream fin(infile.c_str(), ios::in);
	fstream fout(outfile.c_str(), ios::out);
#endif	

    int N, M;
    fin >> N >> M;
    vector<int> A(N + 1);
    vector<int> B(M + 1);
    for(int i = 1; i <= N; i++)
    {
        fin >> A[i];
    }
    for(int i = 1; i <= M; i++)
    {
        fin >> B[i];
    }

    vector<vector<int> > DP(N + 1, vector<int> ( M + 1));
    int maxI = 0;
    int maxJ = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(A[i] == B[j])
            {
                DP[i][j] = 1 + DP[i-1][j-1];
            }
            else if(DP[i-1][j] > DP[i][j-1])
            {
                DP[i][j] = DP[i-1][j];
            }
            else
            {
                DP[i][j] = DP[i][j-1];
            }
            if(DP[maxI][maxJ] < DP[i][j])
            {
                maxI = i;
                maxJ = j;
            }
        }
    }

    fout << DP[maxI][maxJ] << "\n";

    vector<int> Sol;
    Sol.reserve(DP[maxI][maxJ]);
    while(maxI != 0 && maxJ != 0)
    {
        if(A[maxI] == B[maxJ])
        {
            Sol.push_back(A[maxI]);
            maxI--;
            maxJ--;
        }
        else if(DP[maxI-1][maxJ] >DP[maxI][maxJ - 1])
        {
            maxI--;
        }
        else
        {
            maxJ--;
        }
    }
    for(vector<int>::reverse_iterator itr = Sol.rbegin();
            itr != Sol.rend();
            itr++)
    {
        fout << *itr << " ";
    }
    fout << "\n";
#ifdef ONLINE_JUDGE
#else
    fout.close();
	fin.close();
#endif
}
