#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j;
int MAP[1026][1026];
int v1[1026],v2[1026];
int v3[1026];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>v1[i];
    for(j=1;j<=m;j++) fin>>v2[j];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(v1[i]==v2[j]) MAP[i][j]=MAP[i-1][j-1]+1;
                else MAP[i][j]=max(MAP[i-1][j],MAP[i][j-1]);

   cout<<MAP[n][m]<<"\n";
    int x=MAP[n][m];
    i=n;j=m;
    while(x!=0)
    {
        while(MAP[i][j]==MAP[i-1][j]) i--;
        while(MAP[i][j]==MAP[i][j-1]) j--;
         v3[x]=v1[i];
         i--;j--;
         x--;
    }
    for(i=1;i<=MAP[n][m];i++) cout<<v3[i]<<" ";
    //cout<<sizeof(MAP)+sizeof(v1)+sizeof(v2)+sizeof(v3);

    return 0;
}
