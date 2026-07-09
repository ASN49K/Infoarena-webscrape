#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define NMAX 1025
#define MMAX 1025

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int DP[NMAX][MMAX], n, m;
vector<int> a, b;

void read(){
    int toRead;
    a.push_back(-1);
    b.push_back(-1);
    in >> n >> m;
    for(int i = 1; i <= n; i++){
        in >> toRead;
        a.push_back(toRead);
    }

    for(int i = 1; i <=m ;i++){
        in >> toRead;
        b.push_back(toRead);
    }

}

void solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            if(a[i] == b[j]){
                DP[i][j] = max(DP[i][j], 1 + DP[i-1][j-1]);
            }
        }
    }
    int lmax = DP[n][m];
    out << lmax << '\n';

    int *sol = new int[lmax+1];
    int i = n, j = m;
    int k = 0;
    while(i > 0 && j > 0){
        if(DP[i][j]==lmax){
            if(a[i] == b[j]){
                sol[++k] = a[i];
                lmax--;
                i--;
                j--;
            }
            else if(DP[i-1][j] == lmax){
                i--;
            }
            else{
                j--;
            }
        }

    }

    for(int i = DP[n][m]; i > 0; i--){
        out << sol[i] <<  ' ';
    }

}

int main()
{
    read();
    solve();
    return 0;
}
