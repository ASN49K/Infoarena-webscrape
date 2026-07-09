#include <iostream>
#include<fstream>
#define len 1025
#define maxim(a,b) ((a>b)? a:b)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int sol[len][len], v1[len], v2[len], fin[len],k,n,m;
void citire()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>v1[i];
    for(int i=1;i<=m;i++)
        f>>v2[i];
}
void verificare()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v1[i]==v2[j])
                sol[i][j]=1+sol[i-1][j-1];
            else
                sol[i][j]=maxim(sol[i-1][j],sol[i][j-1]);
}
void parcurgere()
{
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(v1[i]==v2[j])
            fin[++k]=v1[i],i--,j--;
        else if(sol[i-1][j]>sol[i][j-1])
            i--;
        else j--;
    }
}
void afisare()
{
    for(int i=k;i>=1;i--)
        g<<fin[i]<<" ";
}
int main()
{
    citire();
    verificare();
    parcurgere();
    afisare();
    return 0;
}
