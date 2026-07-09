#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,x[1025],y[1025],c[1025][1025],b[1025][1025],i,j;
void constr(int x[],int y[])
{
    for (i=1;i<=n;i++)
    {
        c[i][0]=0;
    }
    for (j=1;j<=m;j++)
    {
        c[0][j]=0;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=0;
            }
            else
            {
                if (c[i-1][j]>c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]=-1;
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]=1;
                }
            }
        }
    }
}
void afisare(int b[][1025],int x[],int lg1,int lg2)
{
    if (lg1==0||lg2==0) return;
    if (b[lg1][lg2]==0)
    {
        afisare(b,x,lg1-1,lg2-1);
        fout << x[lg1] << " ";
    }
    else if (b[lg1][lg2]==-1) afisare(b,x,lg1-1,lg2);
    else afisare(b,x,lg1,lg2-1);
}
int main()
{
    fin >> n >> m;
    for (i=1;i<=n;i++)
    {
        fin >> x[i];
    }
    for (i=1;i<=m;i++)
    {
        fin >> y[i];
    }
    constr(x,y);
    fout << c[n][m] << '\n';
    afisare(b,x,n,m);
}
