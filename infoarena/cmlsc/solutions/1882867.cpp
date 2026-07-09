#include <bits/stdc++.h>
#define nmax 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m;
int a[nmax],b[nmax];
int L[nmax][nmax],sol[nmax];

void read()
{int i;
 f>>n>>m;
 for(i=1;i<=n;i++) f>>a[i];
 for(i=1;i<=m;i++) f>>b[i];
}

void pd()
{int i,j;
 for(i=0;i<=n;i++)
    for(j=0;j<=m;j++)
       if(i==0||j==0) L[i][j]==0;
       else
         if(a[i]==b[j]) L[i][j]=1+L[i-1][j-1];
         else L[i][j]=max(L[i-1][j],L[i][j-1]);
}

void af()
{int i,j,nrs=0;
 g<<L[n][m]<<"\n";
 i=n; j=m;
 while(i>0&&j>0)
 {if(a[i]==b[j]) {sol[++nrs]=a[i]; i--; j--;}
  else
    if(L[i-1][j]==L[i][j]) i--;
    else j--;
 }
 for(i=nrs;i>=1;i--)
    g<<sol[i]<<" ";
}

int main()
{read();
 pd();
 af();
 return 0;
}
