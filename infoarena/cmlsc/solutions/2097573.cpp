#include<bits/stdc++.h>
using namespace std;
int max(int a, int b);
int h,h1;
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]),h=X[i-1],h1=Y[j-1];
     }
   }

   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */

   return L[m][n];
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

/* Driver program to test above function */
int main()
{
 char X[1001], Y[1001];
  cin.getline(X,1001);
  cin.getline(Y,1001);

  int m = strlen(X);
  int n = strlen(Y);

  cout<< lcs( X, Y, m, n )<<endl;
  for(int i=n;i<=m;i--)
        cout<<X[i];

  return 0;
}
