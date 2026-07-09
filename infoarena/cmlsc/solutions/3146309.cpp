#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, d[1025][1025], v[1025], w[1025];

int main()
{
    in>>n>>m;

    for(int i=1;i<=n;i++)
        in>>v[i];
    for(int i=1;i<=m;i++)
        in>>w[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(v[i]==w[j])
            d[i][j]=d[i-1][j-1]+1;
        else
            d[i][j]=max(d[i-1][j], d[i][j-1]);
    }

    out<<d[n][m]<<'\n';
    int *sol=new int[d[n][m]];

    int i=n, j=m;
    while(i>0&&j>0)
    {
        if(v[i]==w[j])
            {
                sol[d[i][j]-1]=v[i];
                i--;
                j--;
            }
        else
        {
            if(d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
        }
    }

    for(i=0;i<d[n][m];i++)
        out<<sol[i]<<" ";
    delete[] sol;

    return 0;
}
