#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1030],b[1030],s[1030][1030];

void drum(int i, int j)
{
    if(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            drum(i-1,j-1);
            g<<a[i]<<' ';
        }
        else if(s[i-1][j]>s[i][j-1]) drum(i-1,j);
        else drum(i,j-1);
    }
}

int main()
{
    int n,m;
    f>>n>>m;
    for(int i=1;i<=n;i++)f>>a[i];
    for(int i=1;i<=m;i++)f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]) s[i][j]=s[i-1][j-1]+1;
            else s[i][j]=max(s[i-1][j],s[i][j-1]);

    g<<s[n][m]<<'\n';
    drum(n,m);
    return 0;
}
