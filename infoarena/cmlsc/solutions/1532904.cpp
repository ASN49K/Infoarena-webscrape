#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define nmax 1025
int a[nmax],b[nmax],n,m,d[nmax][nmax],subsir[nmax];

int main()
{
    fin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    fout<<d[n][m];
    fout<<"\n";/*
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            fout<<d[i][j]<<" ";
        fout<<"\n";}*/
    int k=d[n][m];
    i=n,j=m;
    while(k>0){
        if(a[i]==b[j])
            subsir[k]=a[i],k--,i--,j--;
        else
            if(d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;}
    k=d[n][m];
    for(i=1;i<=k;i++)
        fout<<subsir[i]<<" ";
    return 0;
}
