#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short m,n,v[1026][1026];

short maxa(short a,short b)
{
    if(a>b) return a;
    return b;
}

void crss()
{
    short i=n+1,j=m+1,v1[1025],k=0;
    while(v[i][j]!=0)
    {
        if(v[i-1][j]==v[i][j]) i--;
        else if(v[i][j-1]==v[i][j]) j--;
        else
        {
            v1[++k]=v[i][0];
            i--;
            j--;
        }
    }
    for(i=k;i>=1;i--) g<<v1[i]<<" ";
}

int main()
{
    short i,j;
    f>>m>>n;
    for(i=2;i<=m+1;i++) f>>v[0][i];
    for(i=2;i<=n+1;i++) f>>v[i][0];
    for(i=2;i<=n+1;i++)
    for(j=2;j<=m+1;j++)
    {
        if(v[i][0]==v[0][j]) v[i][j]=v[i-1][j-1]+1;
        else v[i][j]=maxa(v[i-1][j],v[i][j-1]);
    }
    crss();
    return 0;
}
