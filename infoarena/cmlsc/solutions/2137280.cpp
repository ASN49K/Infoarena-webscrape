#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int v1[1026],v2[1026],m,n,v[1026][1026];

void form(int i, int j)
{
    if(i<1 || j<1) return;
    if(v1[i]==v2[j]) form(i-1,j-1),fout<<v1[i]<<" ";
    else if(v[i-1][j]>v[i][j-1]) form(i-1,j);
         else form(i,j-1);
}

int main()
{
    int i,j;fin>>n>>m;
    for(i=1;i<=n;i++) fin>>v1[i];
    for(i=1;i<=m;i++) fin>>v2[i];

    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
        if(v1[i]==v2[j]) v[i][j]=v[i-1][j-1]+1;
        else v[i][j]=max(v[i-1][j],v[i][j-1]);

    fout<<v[n][m]<<"\n";

    form(n,m);

    return 0;
}
