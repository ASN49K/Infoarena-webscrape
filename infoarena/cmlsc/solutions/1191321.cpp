#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,a[10001],b[10001],c[10001][10001],i,j,k,d[10001];
void cauta(int i,int j,int k)
{
    if(k>0){
    while(c[i-1][j]==k)i--;
    while(c[i][j-1]==k)j--;
    d[k]=a[i];
    k--;
    cauta(i-1,j-1,k);
    }
}
int main()
{
    ifstream fin("date.in");
    ofstream fout("date.out");
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>a[i];
    for(i=1;i<=m;i++)fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
                else c[i][j]=max(c[i][j-1],c[i-1][j]);
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)cout<<c[i][j]<<" ";
        cout<<endl;
    }*/
    fout<<c[n][m]<<endl;
    cauta(n,m,c[n][m]);
    for(i=1;i<=c[n][m];i++)fout<<d[i]<<" ";

    fin.close();
    fout.close();
    return 0;
}
