#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, x[101], y[101], c[101][101],s[101];

inline int maxim(int a, int b)
{
    return a > b ? a : b;
}

void citire()
{
    int i;
    f >> m;
    f >> n;
    for(i = 1; i <= m; i++)
        f >> x[i];
    for(i = 1; i <= n; i++)
        f >> y[i];
}

void afissir(int s[], int lg, char d)
{
    g << "\nsirul " << d << ": ";
    for(int i = 1; i <= lg; i++)
        g << s[i] << ' ';
    g << '\n';
}

void afismat()
{
    g << "\nMarticea lungimilor :\n";
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            g << setw(4) << c[i][j];
        g << '\n';
    }
}

void calcul()
{
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(x[i] == y[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = maxim(c[i - 1][j], c[i][j - 1]);

}

void afissir()
{
    int k=c[m][n];
    for(int i=m; i>=1 && k>=1; i--)
        for( int j=n; j>=1 &&  k>=1; j--)
            if(x[i]==y[j])
            {
                k--;
                g<<x[i]<<' ';
            }
    g<<'\n';
}

void afissubsir(int i, int j, int k)
{
    if(k>=1)
        if(i>=1)
        {
            if(j>=1)
                if(x[i]==y[j])
                {
                    afissubsir(i, j-1, k-1);
                    g<<x[i]<<' ';
                }
                else
                    afissubsir(i-1,j,k);
            else
                afissubsir(i,j-1,k);
        }
}

void afisdr()
{
    int i=m, j=n, k=c[m][n];
    for(int i=m, j=n; i>=1 && j>=1;)
        if(x[i]==y[j])
    {
        s[k]=x[i];
        i--,j--,k--;
    }
    else
        if(c[i-1][j]>=c[i][j-1])
        i--;
        else
        j--;
    //g<<'\n';
}

int main()
{
    citire();
    calcul();
    //afismat();
    g << c[m][n] << '\n';
    afisdr();
    //afissubsir(m,n,c[m][n]);
    for(int i=1;i<=c[m][n];i++)
        g<<s[i]<<' ';
    return 0;
}
