#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int x[1025],y[1025],c[1025][1025],b[1025][1025],m,n;

void scrie(int i,int j)
{
    if (i==0 || j==0);
    else
    {
        if(b[i][j]==1)
        {
            scrie(i-1,j-1);
            fout<<x[i]<<' ';
        }
        else if(b[i][j]==-1)
            scrie(i-1,j);
        else scrie(i,j-1);
    }
}

int main()
{
    int i,j;
    fin>>n>>m;

    for(i=1;i<=n;i++) fin>>x[i];
    for(i=1;i<=m;i++) fin>>y[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
           if(x[i]==y[j])
           {
               c[i][j]=c[i-1][j-1]+1;
               b[i][j]=1;
           }
           else if(c[i-1][j]>=c[i][j-1])
           {
               c[i][j]=c[i-1][j];
               b[i][j]=-1;
           }
           else
           {
               c[i][j]=c[i][j-1];
               b[i][j]=-2;
           }

    fout<<c[n][m]<<'\n';
    scrie(n,m);

    fout.close();
    fin.close();
    return 0;
}
