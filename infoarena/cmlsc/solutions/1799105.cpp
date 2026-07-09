#include <fstream>
using namespace std;
int c[1050][1050];
int x[1050];
int v[1050];
int n,m;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>v[i];
        c[i][0]=0;
    }
    for(int i=1;i<=m;i++)
    {
        fin>>x[i];
        c[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i]==x[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
            {
                if(c[i-1][j]>c[j][i-1])
                {
                    c[i][j]=c[i-1][j];
                }
                else
                {
                    c[i][j]=c[i][j-1];
                }
            }
        }
    }
    fout<<c[n][m]<<"\n";
    int q=1;
    for(int i=1;i<=m;i++)
    {
        if(c[n][i]==q)
        {
            fout<<x[i]<<" ";
            q++;
        }
    }
    return 0;
}
