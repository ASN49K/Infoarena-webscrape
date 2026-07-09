#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>

using namespace std;

const char infile[] = "cmlsc.in";
const char outfile[] = "cmlsc.out";

ifstream fin(infile);
ofstream fout(outfile);

const int MAXN = 1030;
const int oo = 0x3f3f3f3f;

typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;

const inline int min(const int &a, const int &b) { if( a > b ) return b;   return a; }
const inline int max(const int &a, const int &b) { if( a < b ) return b;   return a; }
const inline void Get_min(int &a, const int b)    { if( a > b ) a = b; }
const inline void Get_max(int &a, const int b)    { if( a < b ) a = b; }

int N, M, A[MAXN], B[MAXN], dp[MAXN][MAXN];

inline vector <int> getCmlsc(int N, int M) {
    for(int i = 1 ; i <= N ; ++ i)
        for(int j = 1 ; j <= M ; ++ j)
            if(A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    int i = N, j = M;
    vector <int> ret;
    while(i && j) {
        if(A[i] == B[j]) {
            ret.push_back(A[i]);
            -- i;
            -- j;
        }
        else
            if(dp[i][j - 1] < dp[i - 1][j])
                -- i;
            else -- j;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    fin >> N >> M;
    for(int i = 1 ; i <= N ; ++ i)
        fin >> A[i];
    for(int i = 1 ; i <= M ; ++ i)
        fin >> B[i];
    vector <int> ans = getCmlsc(N, M);
    fout << ans.size() << '\n';
    for(int i = 0 ; i < ans.size() ; ++ i)
        fout << ans[i] << ' ';
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
