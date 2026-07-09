#include <bits/stdc++.h>
#define optim ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define let auto
#define popcount __builtin_popcount
#define ctzll __builtin_ctzll
#define clzll __builtin_clzll

using namespace std;
string filename = "cmlsc";
ifstream fin(filename + ".in");
ofstream fout(filename + ".out");



const int sze = 1024;
int a[sze + 1], b[sze + 1],d[sze + 1][sze + 1], r[sze + 1];


int main()
{
    int n, m;
    fin>>n>>m;
    for(int i = 1;i<=n;++i) fin>>a[i];
    for(int i = 1;i<=m;++i) fin>>b[i];
    
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(a[i] == b[j]){
                d[i][j] = 1 + d[i - 1][j - 1];
            }
            else{
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    int cnt = 0;
    for(int j = m, i = n;i; ){
        if(a[i] == b[j]){
            r[++cnt] = a[i];
            --i;
            --j;
        }
        else if(d[i - 1][j] < d[i][j - 1]){
            --j;
        }
        else{
            --i;
        }
    }

    fout<<cnt<<'\n';
    for(int i = cnt;i;--i){
        fout<<r[i]<<' ';
    }



    return 0;
}