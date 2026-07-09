#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

const int MAXN = 1024 + 5;

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,a[MAXN],b[MAXN],dp[MAXN][MAXN],solutie[MAXN];

inline int recursiv(int i,int j){
    if(dp[i][j])
        return dp[i][j];
    if(i == 0 || j == 0)
        return 0;
    int result;
    if(a[i] == b[j])
        result = 1 + recursiv(i - 1,j - 1);
    else{
        int varianta1 = recursiv(i,j - 1);
        int varianta2 = recursiv(i - 1,j);
        result = max(varianta1,varianta2);
    }
    dp[i][j] = result;
    return result;
}
inline void afisare(){
    int i = n,j = m,valoare_cautata = dp[i][j],contor = 0;
    while(i > 0 && j > 0){
        if(a[i] == b[j]){
            solutie[++contor] = a[i];
            i--;
            j--;
            valoare_cautata--;
        }else{
            if(dp[i][j - 1] == valoare_cautata)
                j--;
            else
                i--;
        }

    }
    for(int i = contor; i >= 1; i--)
        out<<solutie[i]<<" ";
}

int main()
{
    in.tie(NULL);
    out.tie(NULL);
    ios::sync_with_stdio(false);
    in>>n>>m;
    for(int i = 1; i <= n; i++)
        in>>a[i];
    for(int j = 1; j <= m; j++)
        in>>b[j];
    out<<recursiv(n,m)<<"\n";
    afisare();
    return 0;
}
