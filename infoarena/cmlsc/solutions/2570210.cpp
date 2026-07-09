#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");



int D[1025][1025];
short a[1025],b[1025],sir[1025];


int main()
{


    int n,m;
      fin>>n>>m;

      for(int i=1;i<=n;i++)
        fin>>a[i];
      for(int i=1;i<=m;i++)
        fin>>b[i];


      for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
      {

          if(a[i]==b[j])
               D[i][j]=D[i-1][j-1]+1;
          else
           D[i][j]=max(D[i-1][j],D[i][j-1]);
      }

     int i,j,k=0;
     i=n;
     j=m;



    for (i = n, j = m; i; )
        if (a[i] == b[j])
            sir[++k] = a[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;




     fout<<k<<endl;
     for(int i=k;i>=1;i--)
        fout<<sir[i]<<" ";









    return 0;
}
