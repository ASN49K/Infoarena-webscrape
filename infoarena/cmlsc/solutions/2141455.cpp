#include <iostream>
#include <fstream>
#include<stdlib.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int k,a[1025],b[1025],maxm,L[1025][1025],poz[1025],v[1025],C[1025];
int main()
{int n,m,i,j;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(j=1;j<=m;j++)
        in>>b[j];
    for(i=1;i<=n;i++)

        for(j=1;j<=m;j++)
       if(a[i]==b[j])
            L[i][j]=L[i-1][j-1]+1;
       else
       L[i][j]=max(L[i-1][j],L[i][j-1]);
   out<<L[n][m]<<"\n";
    i=n;j=m;
    while(i>0)
    {
        if(a[i]==b[j])
        {
            C[k++]=a[i];
            i--;j--;
        }
        else
            if(L[i][j-1]>L[i-1][j])
            j--;
            else
            i--;
    }
    for(i=k-1;i>=0;i--)
        out<<C[i]<<" ";
    return 0;
}
