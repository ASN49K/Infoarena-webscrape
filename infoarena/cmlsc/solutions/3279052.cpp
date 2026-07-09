#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024], b[1024], n, m;
int v[1025][1025], r;

int main()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for (int i=1; i<=m; i++)
    {
        fin>>b[i];
    }
    for (int i=n; i>=1; i--)
    {
        for (int j=m; j>=1; j--)
        {
            if (a[i]!=b[j])
            {
                v[i][j]=max(v[i+1][j], v[i][j+1]);
            }
            else
            {
                v[i][j]=v[i+1][j+1]+1;
            }
        }
    }
    int l=v[1][1], x=1, y=1, xf, yf;
    fout<<l<<endl;
    while (l>0)
    {
        int maxi=0;
        for (int i=x; i<=n; i++)
        {
            for (int j=y; j<=m; j++)
            {
                if (v[i][j]==l and a[i]==b[j])
                {
                    if (a[i]>maxi)
                    {
                        maxi=a[i];
                        xf=i;
                        yf=j;
                    }
                }
            }
        }
        x=xf+1;
        y=yf+1;
        fout<<maxi<<" ";
        l--;
    }


    return 0;
}
