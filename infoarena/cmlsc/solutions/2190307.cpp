#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v[1024], x[1024],n,m,w[1024],j,a[1024][1024],i,k=0;
int main()
{fin>>n;
fin>>m;
    for(i=1;i<=n;i++) fin>>v[i];

    for(i=1;i<=m;i++) fin>>x[i];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(v[i]==x[j]) a[i][j]=1+a[i-1][j-1];
            else a[i][j]=max(a[i-1][j],a[i][j-1]);

    }
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        if (a[i][j]==a[i][j-1]) j--;
        else if(a[i][j]==a[i-1][j]) i--;
        else { k++; w[k]=v[i];
        i--; j--;}

    }
    fout<<k<<endl;
    for(i=k;i>=1;i--)
    {
        fout<<w[i]<<" ";
    }
}
