#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int x[1025],y[1025],c[1025][1025],b[1025][1025];
void afisare(int m,int n)
{
    if (m==0||n==0) return;
    if (b[m][n]==0)
    {
        afisare(m-1,n-1);
        fout << x[m] << " ";
    }
    else if (b[m][n]==-1) afisare(m-1,n);
    else afisare(m,n-1);
}
int main()
{
    int m,n,maxx=0;
    fin >> m >> n;
    for (int i=1;i<=m;i++)
    {
        fin >> x[i];
    }
    for (int i=1;i<=n;i++)
    {
        fin >> y[i];
    }
    for (int i=1;i<=m;i++)
    {
        c[i][0]=0;
    }
    for (int i=1;i<=n;i++)
    {
        c[0][i]=0;
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                if (c[i][j]>maxx) maxx=c[i][j];
                b[i][j]=0;
            }
            else
            {
                if (c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    if (c[i][j]>maxx) maxx=c[i][j];
                    b[i][j]=-1;
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    if (c[i][j]>maxx) maxx=c[i][j];
                    b[i][j]=1;
                }
            }
        }
    }
    fout << maxx << '\n';
    afisare(m,n);
}
