#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

void cit(unsigned nr, unsigned mat[1025])
{
    for(unsigned i=1;i<=nr;i++)
        fi>>mat[i];
}

unsigned d[1025][1025];

unsigned maxim(unsigned x, unsigned y)
{
    if( x > y )
        return x;
    return y;
}

int main()
{
    unsigned n,m;
    unsigned a[1025];
    unsigned b[1025];

    unsigned sir[1025];
    unsigned nrc=0;

    fi>>n>>m;

    cit(n,a);
    cit(m,b);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);

    for(int i=n,j=m ; i ; )
        if(a[i]==b[j])
            {sir[nrc++]=a[i];
            i--; j--;}
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;

    fo<<nrc<<'\n';

    for(int i=nrc-1; i>=0; i-- )
        fo << sir[i]<<" ";

    return 0;
}

