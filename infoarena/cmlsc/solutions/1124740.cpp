#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream o("date.out");
int a[1025],b[1025],c[1025][1025],d[1025][1025],n,m;
void citire()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
}
void functie()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                {
                    d[i][j]=14;
                    c[i][j]=c[i-1][j-1]+1;
                }
            else
                if(c[i-1][j]<c[i][j-1])
                    {
                        d[i][j]=1;
                        c[i][j]=c[i][j-1];
                    }
                else
                    {
                        d[i][j]=-1;
                        c[i][j]=c[i-1][j];
                    }
}
void afisare(int i, int j)
{
    if(i!=0&&j!=0)
    if(d[i][j]==14)
    {
        afisare(i-1,j-1);
        cout<<a[i]<<" ";
    }
    else
        if(d[i][j]==-1)
            afisare(i-1,j);
        else
            afisare(i,j-1);
}
int main()
{
    citire();
    functie();
    cout<<c[n][m]<<endl;
    afisare(n,m);
    return 0;
}
