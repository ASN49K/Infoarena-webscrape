#include <iostream>
#include<fstream>
#define n_maxx 1030

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int maxx[n_maxx][n_maxx];
int main()
{
    int n,m,v1[n_maxx],v2[n_maxx],vec[n_maxx],index=0;;
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>v1[i];
    for(int i=1; i<=m; i++)
        f>>v2[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            if(v1[i]==v2[j])
            {
                maxx[i][j]=1+maxx[i-1][j-1];
                index++;
                vec[index]=v1[i];
            }

            else
                maxx[i][j]=max(maxx[i-1][j],maxx[i][j-1]);
    }

    g<<maxx[n][m]<<"\n";
    for(int i=1; i<=index; i++)
        g<<vec[i]<<" ";

}


