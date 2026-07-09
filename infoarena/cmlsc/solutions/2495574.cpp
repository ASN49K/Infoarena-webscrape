#include <iostream>
#include <fstream>

#define Nmax 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[Nmax][Nmax],s1[Nmax],s2[Nmax],n,m;
void ans(int x,int y)
{
    if(x!=0&&y!=0)
    {
        if(s1[x]==s2[y])
        {
            ans(x-1,y-1);
            g<<s1[x]<<" ";
        }
        else if (a[x][y-1]>a[x-1][y])
        {
            ans(x,y-1);
        }
        else
        {
            ans(x-1,y);
        }
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>s1[i];
    for(int i=1;i<=m;++i)
        f>>s2[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s1[i]==s2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    g<<a[n][m]<<'\n';
    ans(n,m);
    return 0;
}
