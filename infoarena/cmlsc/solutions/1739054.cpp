#include <fstream>

using namespace std;

int a[1025], b[1025];
int n, m;
int L[1025][1025];
int c[1025], k;
bool semafor=true;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int max (int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void calcul ()
{
    int i, j;

    for(i=0; i<=n; i++)
        L[i][0]=0;
    for(j=0; j<=m; j++)
        L[0][j]=0;

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
}

void afisare (int k)
{
    fout<<k<<'\n';
    int i;
    for(i=k; i>=1; i--)
        fout<<c[i]<<' ';
    semafor=false;
}

void construire (int i, int j, int lungime)
{
    if(semafor)
    {
        if(i>=1&&j>=1)
        {
            if(a[i]==b[j])
            {
                c[lungime+1]=a[i];
                construire(i-1,j-1,lungime+1);
            }
            else
            {
                if(L[i-1][j]>L[i][j-1])
                    construire(i-1,j,lungime);

                if(L[i-1][j]<L[i][j-1])
                    construire(i,j-1,lungime);

                if(L[i-1][j]==L[i][j-1])
                    construire(i-1,j,lungime), construire(i,j-1,lungime);
            }
        }
        else
            afisare(lungime);
    }
}

int main()
{
    fin>>n>>m;
    int i;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];
    calcul();
    k=0;
    construire(n,m,0);
    return 0;
}
