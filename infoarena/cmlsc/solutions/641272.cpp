#include<iostream>
#include<fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short x[1030],y[1030],a[1030][1030], d[1030];;
short m,n;

void citire()
{
    short i;
    f>>n>>m;
    for(i=1;i<=n;i++)f>>x[i];
    for(i=1;i<=m;i++)f>>y[i];
    f.close();
}
void subsirmax()
{ short i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)

            if(x[i]==y[j])a[i][j]=1+a[i-1][j-1];
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
    g<<(int)a[n][m]<<endl;
}

void scrie(short val)
{short k=0, i=n,j=m;
 while(val&&i&&j)
 {
    if (x[i]==y[j]){ d[++k]=x[i];i--; j--;}
    else
    if(a[i][j]==a[i-1][j])i--;
    else j--;
 }
 g<<d[k];
 for(i=k-1;i>=1;i--) g<<' '<<d[i];
 g<<endl;
 g.close();
}

int main()
{
    citire();
    subsirmax();
    scrie(a[n][m]);
    return 0;
}
