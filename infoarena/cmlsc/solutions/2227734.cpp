#include <iostream>
#include <fstream>

using namespace std;

int a[1030],b[1030],c[1030][1030],n,m;
ofstream fout("cmlsc.out");

void citire()
{
    ifstream fin("cmlsc.in");
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
}

void fct()
{
    int maxi;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
            {
                if(c[i-1][j]>c[i][j-1])
                    maxi=c[i-1][j];
                else
                    maxi=c[i][j-1];
                c[i][j]=maxi;
            }
        }
    fout<<c[n][m]<<"\n";
}

void afisare(int i,int j)
{
    if(c[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        afisare(i-1,j-1);
        fout<<a[i]<<" ";
        return;
    }
    if(c[i][j-1]==c[i][j])
    {
        afisare(i,j-1);
        return;
    }
    afisare(i-1,j);
}

int main()
{
    citire();
    fct();
    afisare(n,m);
    return 0;
}
