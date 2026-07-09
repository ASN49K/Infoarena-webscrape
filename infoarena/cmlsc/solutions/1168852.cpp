//#include <iostream>
#include <fstream>
using namespace std;
int n,m,a[1024],b[1024],dp[1024][1024],v[1024];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main(){
    int i,j;
    fin >> m >> n;
    for(i=1;i<=m;i++)
     fin >> a[i];
    for(i=1;i<=n;i++)
     fin >> b[i];
    fin.close();
    for(i = 1; i <= m; i++)
     for(j = 1; j <= n; j++)
     {
         if(a[i] == b[j])
          dp[i][j] = dp[i][j-1] + 1;
         else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
     }
     for(i = 1; i <= m; i++)
      for(j = 1; j <= n; j++)
       if(dp[i][j] != dp[i][j-1] && dp[i][j] != 0 && v[j] == 0)
       {
           v[j]++;
           fout << b[j]<<" ";
       }
//     for(i = 1; i <= m; i++)
//      {
//          for(j = 1; j<=n;j++)
//           cout << dp[i][j]<<" ";
//        cout <<"\n";
//      }
    fout.close();
    return 0;
}
