#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, crt, v[1050], w[1050], dp[1050][1050];
deque <int> q;

int main (){
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v[i];
    for(int i=1; i<=m; i++)
        fin>>w[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i] == w[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    fout<<(crt=dp[n][m])<<"\n";
    while(crt != 0)
        if(v[n] == w[m]){
            q.push_back(v[n]);
            crt--;n--;m--;
        }else
            if(dp[n-1][m] > dp[n][m-1])
                n--;
            else
                m--;

    while(!q.empty()){fout<<q.back()<<" ";q.pop_back();}
    return 0;
}
