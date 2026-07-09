#include <fstream>
#define NMAX 1024
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,x[NMAX],y[NMAX],a[NMAX][NMAX];

void citire()
{
    int i;
    f>>m>>n;
    for(i=1;i<=m;i++) f>>x[i];
    for(i=1;i<=n;i++) f>>y[i];
}

void dinamica()
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
}

void afisare(int i, int j)
{
    if(a[i][j])
        if(x[i]==y[j])
            afisare(i-1,j-1), g<<x[i]<<" ";
        else
            if(a[i][j]==a[i-1][j])
                afisare(i-1,j);
            else
                afisare(i,j-1);
}
int main()
{
    citire();
    dinamica();
    g<<a[m][n]<<endl;
    afisare(m,n);
    return 0;
}
