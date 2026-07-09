#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
    int a[2005],b[2005],c[2005][2005],n,m;

int main()
{
    vector<int>G;
    fin>>m>>n;
    for(int i=1;i<=m;i++)fin>>a[i];
    for(int j=1;j<=n;j++)fin>>b[j];

    for(int i=0;i<=m;i++)c[i][0]=0;
    for(int j=0;j<=n;j++)c[0][j]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){c[i][j]=c[i-1][j-1]+1;G.push_back(a[i]);}
            else c[i][j]=max(c[i-1][j],c[j][i-1]);
        }
    }
    fout<<c[m][n]<<'\n';
    for(int i=0;i<G.size();i++)
        fout<<G[i]<<' ';
}
