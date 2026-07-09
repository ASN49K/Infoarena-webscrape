#include <bits/stdc++.h>

#define MAX 1025
using namespace std;

int A[MAX][MAX];

int main()
{
   freopen("cmlsc.in", "r", stdin);
   freopen("cmlsc.out", "w", stdout);


   int n, m, x[MAX], y[MAX];
   cin>>n>>m;

   int nr = 0, sir[MAX];

   for(int i = 1; i<=n; i++)
      cin>>x[i];
   
   for(int i = 1; i<=m; i++)
      cin>>y[i];

   for(int i = 1; i<=n; i++)
      for(int j = 1; j<=m; j++)
      {
         if(x[i] == y[j])
            A[i][j] = A[i - 1][j - 1] + 1;
         else
            A[i][j] = max(A[i-1][j], A[i][j - 1]);
      }
   cout<<A[n][m]<<'\n';

   for(int i = n, j = m; i;)
   {
      if(x[i] == y[j])
         sir[++nr] = x[i], i--, j--;
      else {
         if(A[i][j-1] > A[i- 1][j])
            j--;
         else
            i--;
      }
   }
   for(int i = nr; i; i--)
      cout<<sir[i]<<' ';

}
