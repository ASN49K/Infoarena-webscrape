#include<iostream>
#include<fstream>
using namespace std;

#define dim 1050

//ifstream in("date.in");
//ofstream out("date.out");

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int x[dim],y[dim];
int l[dim][dim];
int n,m;

int maxim(int a, int b)
{
    if(a>b) return a;
    return b;
}

void afis(int i, int j)
{
    if(l[i][j]==0) return;

    if(x[j]==y[i])
    {
        afis(i-1, j-1);
        out<<y[i]<<" ";
    }
    else if(l[i][j]==l[i][j-1]) afis(i, j-1);
    else afis(i-1, j);
}

int main()
{
    int i,j;

    in>>m>>n;
    for(j=1;j<=m;++j) in>>x[j];
    for(i=1;i<=n;++i) in>>y[i];

    //
    for(j=0;j<=m;++j) l[0][j]=0;
    for(i=0;i<=n;++i) l[i][0]=0;

    //
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(x[j]==y[i]) l[i][j] = l[i-1][j-1] + 1;
            else l[i][j] = maxim(l[i][j-1], l[i-1][j]);

    //
    /*for(j=1;j<=m;++j) out<<x[j]<<" "; out<<"\n";
    for(i=1;i<=n;++i) out<<y[i]<<" "; out<<"\n";
    out<<"\n";

    for(i=0;i<=n;++i)
    {
        for(j=0;j<=m;++j) out<<l[i][j]<<" ";
        out<<"\n";
    }
    out<<"\n";*/

    out<<l[n][m]<<"\n";
    afis(n, m);

    return 0;
}
