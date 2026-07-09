#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlcs.in");
ofstream g("cmlcs.out");
int Tabel[1027][1027];
int m,n;
int v[1027];
void citire()
{
    f>>m>>n;
    int i;
    for(i=2;i<=m+1;i++)
    f>>Tabel[0][i];

    for(i=2;i<=n+1;i++)
    f>>Tabel[i][0];


}
void parcurgere()
{
    int i,k;
    for(i=2;i<=n+1;i++)
    {
        for(k=2;k<=m+1;k++)
        if(Tabel[i][0]==Tabel[0][k])
        Tabel[i][k]=Tabel[i-1][k-1]+1;
        else
        Tabel[i][k]=max(Tabel[i-1][k],Tabel[i][k-1]);


    }
}
void backwcitire()
{
    int t= Tabel[n+1][m+1];
    int i,j;
    i=n+1;
    j=m+1;
int h=1;
    while(Tabel[i][j]!=0)
    {


        if(Tabel[i][0]==Tabel[0][j])
        {

            h++;
            v[t]=Tabel[i][0];
            i--;
            j--;
            t--;
        }
        else
        {
            if(Tabel[i-1][j]<Tabel[i][j-1])
            j=j-1;
            else
            i=i-1;

        }

    }
    /*v[t]=Tabel[i][j];
    t--;
    i=i-1;
    j=j-1;

    if(Tabel[i-1][j]==Tabel[i][j-1])
        {
            g<<Tabel[i-1][0]<<" Hu:"<<'\n';
            v[t]=Tabel[i][0];
            t--;

            i=i-1;
            j=j-1;
        }
        else
        {
            if(Tabel[i-1][j]>Tabel[i][j-1])
            i--;
            else
            j--;
        }
    while(Tabel[i][j]!=0)
    {
        if(Tabel[i-1][j]==Tabel[i][j-1])
        {
            v[t]=Tabel[i-1][0];
            t--;

            i=i-1;
            j=j-1;
        }
        else
        {
            if(Tabel[i-1][j]>Tabel[i][j-1])
            i--;
            else
            j--;
        }
    }*/
}
int main()
{
    citire();
    parcurgere();
    g<<Tabel[n+1][m+1]<<'\n';

    backwcitire();


    int t=Tabel[n+1][m+1];

    int i;
    for(i=1;i<=t;i++)
    g<<v[i]<<' ';

    /*int i,k;

    for(i=0;i<=n+1;i++)
    {
        for(k=0;k<=m+1;k++)
        g<<Tabel[i][k]<<' ';

        g<<'\n';
    }*/
    f.close();
    g.close();
    return 0;
}
