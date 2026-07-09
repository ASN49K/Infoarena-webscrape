#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int a[1001],b[1001],c[1001][1001],x[1001],k,i,n,m,j;

void citire()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
}

int maxim(int x,int y)
{
    if(x>y) return x;
    else return y;
}

void afisare()
{
    for(i=k;i>=1;i--)
        g<<x[i]<<' ';
}

int main()
{
    citire();
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j]) c[i][j]=1+c[i-1][j-1];
    else c[i][j]=maxim(c[i-1][j],c[i][j-1]);
    //afisare();
    i=n;
    j=m;
    //x=c[i][j];
    while(c[i][j]!=0)
    {

        if(c[i][j]==c[i][j-1]) j--;
        else if(c[i][j]==c[i-1][j]) i--;
        else if(c[i][j]==c[i-1][j-1]+1) {k++; x[k]=a[i]; i--; j--;}
    }
    afisare();

    return 0;

}
