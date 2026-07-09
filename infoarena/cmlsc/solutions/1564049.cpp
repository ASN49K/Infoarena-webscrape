#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,k;
int a[1026],b[1026];
int subsir[1026][1026];
int sol[1026];
int maxim(int x,int y)
{
    if(x>y)
        return x;
    return y;
}
void citire()
{
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
}
void matrice()
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            {
                if(a[i]==b[j])
                {
                    subsir[i][j]=subsir[i-1][j-1]+1;
                }
                else
                    subsir[i][j]=maxim(subsir[i][j-1],subsir[i-1][j]);
            }
}
void sir(int k)
{
int i=m,j=n;
while(j>1)
{
    if(subsir[i-1][j-1]<subsir[i][j])
    {
        sol[k--]=a[i];
        i--;
    }
    j--;
}
while(k)
{
    sol[k--]=b[1];
}
}
void afisare()
{
for(int i=1;i<=k;i++)
    fout<<sol[i]<<' ';
}
int main()
{
    citire();
    matrice();
    k=subsir[m][n];
    fout<<k<<'\n';
    sir(k);
    afisare();
    return 0;
}
