#include <iostream>
#include <fstream>

using namespace std;

int  n, m, x[256][256], a[1024], b[1024];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]!=b[j])
            {
                if(x[i][j-1]>x[i-1][j])
                    x[i][j]=x[i][j-1];
                else
                    x[i][j]=x[i-1][j];
            }
            else
                if(x[i][j-1]>x[i-1][j])
                    x[i][j]=1+x[i][j-1];
                else
                    x[i][j]=1+x[i-1][j];
    g<<x[m][n];
    f.close();
    g.close();
return 0;
}


