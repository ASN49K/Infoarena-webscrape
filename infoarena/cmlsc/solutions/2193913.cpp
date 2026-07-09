#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define MAX 1000
int n, m;
int d[MAX][MAX];
int a[MAX], b[MAX], e[MAX], c=1;


int main()
{
    int i,j;
    f>>n;
    f>>m;
    for(i=1; i<n+1; i++)
        f>>a[i];
    for(i=1; i<m+1; i++)
        f>>b[i];
    for(i=0; i<=n; i++)
        for(j=0; j<=m; j++)
            if(i==0 || j==0) d[i][j]=0;
    if(a[i]!=b[j])  {if(d[i-1][j]>d[i][j-1]) d[i][j]=d[i-1][j];
                     else if(d[i-1][j]<=d[i][j-1]) d[i][j]=d[i][j-1];
    }
        else if(a[i]==b[j])  d[i][j]=d[i-1][j-1]+1;
    for(j=m,i=n; i && j;)
        if(a[i]==b[j])
        {
            e[c]=a[i];
            i--;
            j--;
            c++;

        }
        else if(a[i]!=b[j])
                        {if(d[i-1][j]>d[i][j-1])
                                       i--;
                                   else j--;
                        }
g<<d[n][m];
for(i=c;i>0;i--)
 g<<e[c]<<" ";
return 0;
}
