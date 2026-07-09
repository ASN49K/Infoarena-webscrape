#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1032],c[1032],b[1032][1032],n,m,sir[1032],bst;
void citire()
{int i,j;
 fin>>n>>m;
 for(i=1;i<=n;i++)fin>>a[i];
 for(j=1;j<=m;j++)fin>>c[j];

}
void construire()
{int i,j;
 for (i = n, j = m; i; )
        if (a[i] == c[j])
            sir[++bst] = a[i], --i, --j;
        else if (b[i-1][j] < b[i][j-1])
            --j;
        else
            --i;
}
void rezolva()
{int i,j;
 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
            {if(a[i]==c[j])b[i][j]=b[i-1][j-1]+1;
             else b[i][j]=max(b[i-1][j],b[i][j-1]);

            }

 construire();
 fout<<b[n][m]<<"\n";
 for(i=bst;i>=1;i--)fout<<sir[i]<<" ";
}
int main()
{
    citire();
    rezolva();
    return 0;
}
