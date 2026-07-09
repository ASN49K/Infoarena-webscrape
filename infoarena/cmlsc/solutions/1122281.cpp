#include <fstream>
#define maxim(a,b) (a>b?a:b)
using namespace std;
fstream f("cmlsc.in",ios::in);
fstream g("cmlsc.out",ios::out);

short m,n,a[1025], b[1025],i,j,k, d[1025][1025], sir[1025], lmax;
void citire()
{
    f>>m>>n;
    for(i=1; i<=m; i++)
        f>>a[i];
    for(i=1; i<=n; i++)
        f>>b[i];
    f.close();

}

void prelucrare()
{

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            if(a[i] == b[j])
                {
                    d[i][j]= 1 + d[i-1][j-1];
                }
            else
                {
                    d[i][j]= maxim(d[i][j-1], d[i-1][j]);
                }
    }

    for (i = m, j = n; i>0; )
        if (a[i] == b[j])
            sir[++lmax] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
}

void scrie()
{
    g<<lmax<<'\n';
    for(i=lmax; i>=1; i--)
        g<<sir[i]<<' ';
    g.close();
}

int main()
{
    citire();
    prelucrare();
    scrie();
    return 0;
}
