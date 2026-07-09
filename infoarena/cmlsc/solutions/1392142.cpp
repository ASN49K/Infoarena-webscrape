#include <iostream>
#include <fstream>
#include <algorithm>
#define NMax 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[NMax],b[NMax],i,j,D[NMax][NMax],sir[NMax],bst;
int main()
{
fin>>m>>n;
for(i=1;i<=m;i++)
    fin>>a[i];
for(j=1;j<=n;j++)
    fin>>b[j];
for(i=1;i<=m;++i)
{
    for(j=1;j<=n;++j)
    {
        if(a[i]==b[j])
            D[i][j]=1+D[i-1][j-1];
        else
            D[i][j]=max(D[i-1][j],D[i][j-1]);
    }
}

for(i=m,j=n;i;)
{
    if(a[i]==b[j])
    {
        sir[++bst]=a[i];
        --i;
        --j;
    }
    else if(D[i-1][j]<D[i][j-1])
        j--;
    else i--;
}
fout<<bst<<"\n";
for(i=bst;i>=1;i--)
    fout<<sir[i]<<" ";
    return 0;
}
