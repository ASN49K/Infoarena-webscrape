#include <iostream>
#include <fstream>
#define Max_N 1024
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,lmax=0;
int v[Max_N],u[Max_N],sir[Max_N];
int O[Max_N][Max_N];

void citire()
{
    f>>n>>m;
    for(int i = 1 ; i <= n ; i++)
        f>>v[i];

    for(int j = 1 ; j <= m ; j++)
        f>>u[j];

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            O[i][j] = 0;
}

void dinamic()
{
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(v[i]==u[j])
                O[i][j] = O[i-1][j-1] + 1;
            else
                O[i][j] = max(O[i-1][j],O[i][j-1]);
}

void reconstruire()
{
    int i=n,j=m;
    while(i >=1 && j >= 1 )
    {
    if(v[i]==u[j])
        {
        sir[++lmax] = v[i];
        i--;
        j--;
        }
    else if(O[i-1][j] < O[i][j-1])
        j--;
    else
        i--;

    }
}
int main()
{
    citire();
    dinamic();
    reconstruire();
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
            g<<O[i][j]<<' ' ;
        g<<'\n';
    }
    g<<lmax<<'\n';
    for(int i = lmax ; i >= 1 ; i--)
        g<<sir[i]<<' ';
    return 0;
}
