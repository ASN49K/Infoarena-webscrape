#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");


deque <int> sol;
int dp[1050][1050];
int n, m, crt, v[1050], w[1050];

int main (){
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v[i];
    for(int j=1; j<=m; j++)
        fin>>w[j];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i] == w[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    fout<<(crt=dp[n][m])<<"\n";
    while(crt != 0){
        if(dp[n-1][m] == crt){
            n--;
        }else if(dp[n][m-1] == crt){
            m--;
        }else{
            sol.push_back(v[n]);
            crt--;
            n--;
            m--;
        }
    }

    while(!sol.empty()){fout<<sol.back()<<" "; sol.pop_back();}
    return 0;
}
