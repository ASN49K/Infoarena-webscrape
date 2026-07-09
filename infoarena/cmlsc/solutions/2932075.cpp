#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#define MAX 1026
using namespace std;
int n,m,a[MAX],b[MAX],dp[MAX][MAX];
vector<int> sol;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int i = n, j = m;
    while(i){
        if(a[i] == b[j]){
            sol.push_back(a[i]);
            i--; j--;
        }else if(dp[i-1][j] >= dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(sol.begin(), sol.end());
    fout << sol.size() << "\n";
    for(auto it: sol){
        fout << it << " ";
    }
    return 0;
}
