#include <iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],poz[1025],L[1025][1025],C[1025];
int main()
{
f>>n>>m;
for(int i=1;i<=n;i++)
    f>>a[i];
    for(int j=1;j<=m;j++)
    f>>b[j];
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i]==b[j])
        L[i][j]=L[i-1][j-1]+1;
    else L[i][j]=max(L[i-1][j],L[i][j-1]);
    g<<L[n][m]<<endl;
int k=0,i=n,j=m;
while(i>0)
    if(a[i]==b[j])
        C[k++]=a[i],i--,j--;
        else
        {if(L[i][j-1]<L[i-1][j])
            j--;
        else i--;
            }
for(int i=k-1;i>=0;i--)
    g<<C[i]<<" ";
    return 0;
}
