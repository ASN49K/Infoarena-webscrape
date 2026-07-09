#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

struct adat
{
    int a,h;
};

adat a[1050][1050];

int kiir(adat a[1050][1050],int n,int m,vector<int> x,vector<int> y)
{
    if(a[n][m].h!=0)
    {
        if(a[n][m].h==3)
        {
            kiir(a,n-1,m-1,x,y);
            if(a[n-1][m-1].a<a[n][m].a) fout<<x[n]<<" ";
        }
        else
        {
            if(a[n][m].h==2)
            {
                kiir(a,n-1,m,x,y);
            }
            else
            {
                kiir(a,n,m-1,x,y);
            }
        }
    }
}

int main()
{
    int n,m,i,j;
    fin>>n>>m;

    vector<int> x(n+1),y(m+1);

    for(i=1;i<=n;i++)
    {
        fin>>x[i];
    }

    for(i=1;i<=n;i++)
    {
        fin>>y[i];
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
            {
                a[i][j].a=a[i-1][j-1].a+1;
                a[i][j].h=3;
            }
            else
            {
                if(a[i][j-1].a>a[i-1][j].a)
                {
                    a[i][j].a=a[i][j-1].a;
                    a[i][j].h=1;
                }
                else
                {
                    a[i][j].a=a[i-1][j].a;
                    a[i][j].h=2;
                }
            }
        }
    }

    fout<<a[n][m].a<<"\n";

    kiir(a,n,m,x,y);
}
