#include <iostream>
#include <fstream>

using namespace std;

const int dim = (int)(1024);
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, a[dim], b[dim], c[dim], p[dim][dim], nr;

int maxim(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{

    in>>n>>m;
    for(int i=1; i<=n; i++)
        in>>a[i];
    for(int j=1; j<=m; j++)
        in>>b[j];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                p[i][j]=1+p[i-1][j-1];
            else
                p[i][j]=maxim(p[i-1][j],p[i][j-1]);
    }
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            c[++nr]=a[i];
            i--;
            j--;
        }
        else if(p[i-1][j]<p[i][j-1])
            j--;
        else
            i--;
    }
    out<<p[n][m]<<'\n';
    for(int i=nr; i>=1; --i)
        out<<c[i]<<' ';


    in.close();
    out.close();
    return 0;
}
