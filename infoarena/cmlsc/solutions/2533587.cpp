#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#define NMAX 1024

using namespace std;

ifstream fin("subsir.in");
ofstream fout("subsir.out");

int nr;

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
    //cout<<n<<' '<<m<<'\n';
    ++nr;
    if(n==0 || m==0)
        return 0;
    if(x[n-1]==y[m-1])
        return 1+lcs(x,y,n-1,m-1);
    return lcs(x,y,n-1,m);
}

int main()
{
    int a[NMAX],b[NMAX];
    int n,m;
    fin>>n>>m;
    read(a,n);
    read(b,m);
    fout<<lcs(a,b,n,m);

    return 0;
}
