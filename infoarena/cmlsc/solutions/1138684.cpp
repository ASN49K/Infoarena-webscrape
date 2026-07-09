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
        fin >> A[i];
    for(int i = 1; i <= M; i++)
        fin >> B[i];

    vector<vector<int> > DP(N + 1, vector<int>(M + 1, 0));
    int Sol = 0;

    int cI = N;
    int cJ = M;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(A[i] == B[j])
            {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
            if(DP[i][j] > Sol)
            {
               Sol = DP[i][j];
               cI = i;
               cJ = j;
            }
        }

    }


    fout << Sol << "\n";

    vector<int> recons;
    recons.reserve(Sol);
    while(Sol)
    {
        if(A[cI] == B[cJ])
        {
            recons.push_back(A[cI]);
            cI--, cJ --;
            Sol--;
        }
        else
        {
            if(DP[cI - 1][cJ] > DP[cI][cJ - 1])
            {
                cI--;
            }
            else
            {
                cJ--;
            }
        }
    }

    for(vector<int>::reverse_iterator itr = recons.rbegin();
            itr != recons.rend();
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
