#include <fstream>
#include <math.h>
using namespace std;
fstream f1("cmlsc.in", ios::in);
fstream f2("cmlsc.out", ios::out);
int n, m, x[1025], y[1025];
long int a[1026][1026];
///a[i][j]= lungimea celui mai lung subsir comun
///pt x[i], x[i+1],...,x[n] si y[j], y[j+1],...,y[m]
void citire()
{
    int i;
    f1>>n>>m;
    for(i=1; i<=n; i++)
        f1>>x[i];
    for(i=1; i<=m; i++)
        f1>>y[i];
}
void dinamica()
{
    int i, j;
    for(i=n; i>=1; i--)
      for(j=m; j>=1; j--)
    {
        if(x[i]==y[j]) a[i][j]=1+a[i+1][j+1];
        else
        {
            long int maxi=0;
            if(((j+1)<=m)&&(maxi<a[i][j+1])) maxi=a[i][j+1];
            if(((i+1)<=n)&&(maxi<a[i+1][j])) maxi=a[i+1][j];
            a[i][j]=maxi;
        }
    }
}
void rec(int i, int j)
{

    if((i==n)&&(j==m))
    {
        if(x[i]==y[j]) f2<<x[i]<<" ";
    }
    else
    {
         if(x[i]==y[j]) {f2<<x[i]<<" ";rec(i+1, j+1);}
         else
         {
             if(a[i][j+1]>=a[i+1][j]) rec(i, j+1);
             else if(a[i][j+1]<=a[i+1][j]) rec(i+1, j);
         }
    }
}
void afisare()
{
    f2<<a[1][1]<<"\n";
    ///reconstituim solutia mergand invers pe recurenta
    rec(1, 1);
}
int main()
{
    citire();
    dinamica();
    afisare();
    return 0;
}
