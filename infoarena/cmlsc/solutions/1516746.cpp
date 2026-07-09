#include <fstream>
#include <iostream>
using namespace std;
int c[1024][1024];
int main()
{
    int i,subsir[1024],a[1024],b[1024],n,m,j;
    ifstream fin("cmlsc.in");
    fin>>n>>m;

    for(i=1;i<=n;i++) fin>>a[i];
    for(j=1;j<=m;j++) fin>>b[j];
    fin.close();
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
        if(a[i]==b[j])  c[i][j]=c[i-1][j-1]+1;
    else c[i][j]=max(c[i-1][j],c[i][j-1]);

    ofstream fout("cmlsc.out");
    fout<<c[n][m]<<endl;
int    k=c[n][m];
     i=n;j=m;
    while(k>0)
    {
        if(a[i]==b[j])
        {subsir[k]=a[i];k--;i--;j--;}
        else
            if(c[i-1][j]>c[i][j-1]) i--;else j--;

    }

    k=c[n][m];
    for(i=1;i<=k;i++)
         fout<<subsir[i]<<" ";
    return 0;
}
