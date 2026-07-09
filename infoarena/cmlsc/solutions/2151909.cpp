#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define MAXN 1030

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,a[MAXN],b[MAXN],dp[MAXN][MAXN],sol[MAXN][MAXN];

void cit(){
    in>>n>>m;
    for(int i = 1; i <= n; i++)
        in>>a[i];
    for(int i = 1; i <= m; i ++)
        in>>b[i];
}
void afis(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cerr<<dp[i][j]<<" ";
        cerr<<endl;
    }
    cerr<<endl;
}
void rez(){
    int i,j;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                sol[i][j] = a[i];
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    sol[i][j] = sol[i-1][j];
                }else{
                    dp[i][j] = dp[i][j-1];
                    sol[i][j] = sol[i][j-1];
                }
            }
        }
    }
    afis();
    vector<int>rasp;
    out<<dp[n][m]<<"\n";
    i = n,j = m;
    rasp.push_back(sol[i][j]);
    while(i >= 2 && j >= 2){
        if(dp[i-1][j] > dp[i][j-1]){
            if(sol[i-1][j] != sol[i][j])
                rasp.push_back(sol[i-1][j]);
            i--;
        }else{
            if(sol[i][j-1] != sol[i][j])
                rasp.push_back(sol[i][j-1]);
            j--;
        }
    }
    reverse(rasp.begin(),rasp.end());
    for(int i = 0; i < rasp.size(); i ++)
        out<<rasp[i]<<" ";
}

int main()
{
    cit();
    rez();

    return 0;
}
