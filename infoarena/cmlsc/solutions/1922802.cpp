#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1026],b[1025],L[1025][1025],P[1025][1025],c[1026],l;
void citire()
{
    int i,j;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(j=1; j<=m; j++)
        fin>>b[j];
}
void constr_matrice()
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
            {
                L[i][j]=L[i-1][j-1]+1;
                P[i][j]=1;
            }
            else if(L[i-1][j]>L[i][j-1])
            {
                L[i][j]=L[i-1][j];
                P[i][j]=2;
            }
            else
            {
                L[i][j]=L[i][j-1];
                P[i][j]=3;
            }
}
void afisare(int i,int j)
{
    if(i>0 && j>0)
        if(P[i][j]==1)
        {
            afisare(i-1,j-1);
            l++;
            //c[j]=b[j];
            fout<<a[i]<<' ';
        }
        else if(P[i][j]==2)
        {
            //l++;
            afisare(i-1,j);
        }
        else
        {
            //l++;
            afisare(i,j-1);
        }
}
int main()
{
    citire();
    constr_matrice();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(P[i][j]==1)
                l++;
    fout<<l<<'\n';
    afisare(n,m);

    //for(int i=1;i<=l;i++)
        //fout<<c[i]<<' ';
    return 0;
}
