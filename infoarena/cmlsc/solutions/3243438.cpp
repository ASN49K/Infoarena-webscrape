#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, j;
int dp[1030][1030], a[1030], b[1030];
vector<int> sol;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++){
        fin>>a[i];
    }
    for(i=1;i<=m;i++){
        fin>>b[i];
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    fout<<dp[n][m]<<'\n';

    i=n, j=m;
    while(i>0 && j>0){
        //cout<<i<<" "<<j<<'\n';
        if(a[i]==b[j]){
            sol.push_back(a[i]);
            i--, j--;
        }else{
            //cout<<dp[i][j-1]<<"\n";
            if(dp[i][j-1]>=dp[i-1][j])
                j--;
            else
                i--;
        }
    }

    for(i=sol.size()-1;i>=0;i--){
        fout<<sol[i]<<" ";
    }



    return 0;
}
