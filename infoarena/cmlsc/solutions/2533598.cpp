#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#define NMAX 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int res[NMAX]={0};

int strlen(char *s)
{
    int i=0;
    while(s[i]!='\0')
        ++i;

    return i;
}

void read(int *v,int n)
{
    for(int i=0;i<n;++i)
        fin>>v[i];
}

int lcs(int *x,int *y,int n,int m)
{
    if(n==0 || m==0)
        return 0;
    if(x[n-1]==y[m-1])
        {

            int nr=1+lcs(x,y,n-1,m-1);
            //if(res[nr]==0)
                res[nr]=x[n-1];
            return nr;
        }
    return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
}

int main()
{
    int a[NMAX],b[NMAX];
    int n,m;
    fin>>n>>m;
    read(a,n);
    read(b,m);
    int nr=lcs(a,b,n,m);
    fout<<nr<<'\n';
    for(int i=1;i<=nr;++i)
        fout<<res[i]<<' ';

    return 0;
}
