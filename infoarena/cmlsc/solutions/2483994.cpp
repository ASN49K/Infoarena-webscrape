#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025], b[1025], c[1025], best[1025][1025];
int n, m, k;

void Citire()
{
    int i;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
}

int Maxim(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void Best()
{
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                best[i][j]=best[i-1][j-1]+1;
            else
                best[i][j]=Maxim(best[i-1][j], best[i][j-1]);
}

void Construire(int i, int j)
{
    if(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            c[++k]=a[i];
            Construire(i-1, j-1);
        }
        else
        {
            if(best[i-1][j]>=best[i][j-1])
                Construire(i-1, j);
            else
                Construire(i, j-1);
        }
    }
}

void Afisare()
{
    g<<best[n][m]<<endl;
    for(int i=k; i>=1; i--)
        g<<c[i]<<" ";
}

int main()
{
    Citire();
    Best();
    Construire(n, m);
    Afisare();
    return 0;
}
