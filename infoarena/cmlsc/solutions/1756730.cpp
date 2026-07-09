#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,D[1200][1200],s1[1200],s2[1200];

void citire()
{
    f>>n>>m;
    for(int i = 1; i <= n; i++) f>>s1[i];
    for(int i = 1; i <= m; i++) f>>s2[i];
}

void pd()
{
    int i,j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0) D[i][j] = 0;
            else if(s1[i] == s2[j]) D[i][j] = D[i-1][j-1] + 1;
            else D[i][j] = max(D[i-1][j],D[i][j-1]);
        }
    }
}

void rafis(int i,int j)
{
    if(i == 0 && j == 0) g<<D[n][m]<<'\n';
    else if(D[i][j] == D[i-1][j]) rafis(i-1,j);
    else if(D[i][j] == D[i][j-1]) rafis(i,j-1);
    else
    {
        rafis(i-1,j-1);
        g<<s1[i]<<" ";
    }
}

int main()
{
    citire();
    pd();
    rafis(n,m);
    return 0;
}
