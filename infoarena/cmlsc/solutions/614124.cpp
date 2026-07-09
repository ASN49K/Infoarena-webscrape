#include <iostream>
#include <fstream>

using namespace std;

int n,m, s[1030][1030], a[1030],b[1030];
ofstream g("cmlsc.out");

void afis(int x,int y)
{
    if(x==0 || y==0)
        return;
    if (b[x]==a[y])
    {
        afis(x-1,y-1);
        g<<b[x]<<" ";
    }
    else
    {
        if (s[x-1][y]>s[x][y-1])
            afis(x-1,y);
        else
            afis (x,y-1);
    }

}




int main()
{

    ifstream f("cmlsc.in");

    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];


    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(b[i]!=a[j])
                s[i][j] = max(s[i][j-1], s[i-1][j]);
            else
                s[i][j] = 1 + s[i-1][j-1];
        }

    g<< s[m][n]<<"\n";
/*
    for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                cout << s[i][j]<< " ";
            cout <<"\n";
        }
*/
    afis(m,n);
    return 0;
}
