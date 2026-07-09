#include <fstream>
using namespace std;
int c[1050][1050];
int x[1050];
int v[1050];
int l[1050];
int n,m;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>v[i];
        c[i][0]=0;
    }
    for(int i=1; i<=m; i++)
    {
        fin>>x[i];
        c[0][i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(v[i]==x[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
            {
                c[i][j] = c[i-1][j]>c[i][j-1]?c[i-1][j]:c[i][j-1];
            }
        }
    }
    int p=0;
    int q=m;
    for(int i=n ;i>0;)
    {
        if(v[i]==x[q])
        {
            l[++p]=v[i];
            i--;
            q--;
        }
        else
        {
            if(c[i-1][q]>c[i][q-1])
            {
                i--;
            }
            else
            {
                q--;
            }
        }
    }
    fout<<p<<"\n";
    for(int i=p;i>=1;i--)
    {
        fout<<l[i]<<" ";
    }
    return 0;
}
