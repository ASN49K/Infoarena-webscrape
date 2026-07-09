#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short n,m,i,j,mat[1025][1025];
short v[1025],w[1025];
short af[1025];

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=m;i++)
        f>>w[i];
    for(i=0;i<=n;i++)
    {
        mat[0][i]=0;
        mat[i][0]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==w[j])
            {
                mat[i][j]=1+mat[i-1][j-1];
            }
            else
            {
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    int l=mat[n][m];
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        if(v[i]==w[j])
        {
            af[l]=v[i];
            //g<<v[i]<<" ";
            i--;
            j--;
            l--;
        }
        else if (mat[i-1][j] > mat[i][j-1])
        {
            i--;
        }
        else j--;
    }
    g<<mat[n][m]<<"\n";
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            g<<mat[i][j]<<" ";
        g<<"\n";
    }*/
    for(i=1;i<=mat[n][m];i++)
    {
        g<<af[i]<<" ";
    }
    return 0;
}
