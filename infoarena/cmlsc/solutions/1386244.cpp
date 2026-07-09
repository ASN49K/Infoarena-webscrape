#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[101],b[101],n,m,mat[101][101],nr,v[101];
void citire()
{
    fin>>n>>m;
    for(int a1=1;a1<=n;a1++)
    {
        fin>>a[a1];
    }
    for(int a2=1;a2<=m;a2++)
    {
        fin>>b[a2];
    }
}
void fct()
{
    for(int a1=1;a1<=n;a1++)
        for(int a2=1;a2<=m;a2++)
    {
        if(a[a1]==b[a2])
        {
            if(mat[a1-1][a2-1]+1>=mat[a1-1][a2] and mat[a1-1][a2-1]+1>=mat[a1][a2-1])
            {
                mat[a1][a2]=mat[a1-1][a2-1]+1;
            }
            else
            {
                if(mat[a1-1][a2]>=mat[a1][a2-1])
                {
                    mat[a1][a2]=mat[a1-1][a2];
                }
                else
                {
                    mat[a1][a2]=mat[a1][a2-1];
                }
            }
        }
        else
        {
                if(mat[a1-1][a2]>=mat[a1][a2-1])
                {
                    mat[a1][a2]=mat[a1-1][a2];
                }
                else
                {
                    mat[a1][a2]=mat[a1][a2-1];
                }
        }
    }
}
void afisare()
{
    int a1=n,a2=m;
    while(mat[a1][a2])
    {
        if(mat[a1-1][a2]==mat[a1][a2]) a1--;
        else if(mat[a1][a2-1]==mat[a1][a2]) a2--;
        else
        {
            nr=mat[a1][a2];
            v[nr]=a[a1];
            a1--;
        }
    }
    for(int a=1;a<=mat[n][m];a++)
    {
        fout<<v[a]<<" ";
    }
}
int main()
{
    citire();
    fct();
    afisare();
}
