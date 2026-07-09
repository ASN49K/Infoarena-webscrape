#include <iostream>
#include <fstream>
using namespace std;
int n,m,a[1024],b[1024],dp[1024][1024],v[1024];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main(){
    int i,j,k,c;
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
          dp[i][j] = dp[i-1][j-1] + 1;
         else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
     }
     fout << dp[m][n]<<"\n";
     k =dp[m][n];
     c=1;
     for(i = m; i >= 1; i--)
      for(j = n; j >= 1; j--)
       if(a[i] == b[j] && k > 0)
       {
           k--;
           v[c++] = b[j];
       }
       for(i=c-1;i>0;i--)
        fout << v[i]<<" ";
    fout << "\n";
     for(i = 1; i <= m; i++)
      {
          for(j = 1; j<=n;j++)
           cout << dp[i][j]<<" ";
        cout <<"\n";
      }
    fout.close();
    return 0;
}
