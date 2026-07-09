#include <iostream>
#include <fstream>
#define maxim(a,b) ((a>b)?a:b)
#define FOR(i,a) for(i=1;i<=a;i++)
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, A[1025], B[1025], D[1025][1025], sir[1025];

void citire()
{
    int i;
    f>>m>>n;
    FOR(i,m) f>>A[i];
    FOR(i,n) f>>B[i];
}

int main()
{
    int i, j, l=0;
    citire();
    FOR(i,m)
        FOR(j,n)
        if(A[i]==B[j])
            D[i][j]=1 + D[i-1][j-1];
        else
            D[i][j]=maxim(D[i-1][j],D[i][j-1]);

    for(i=m,j=n;i;)
        if(A[i]==B[j])
            sir[++l]=A[i],i--,j--;
        else if(D[i-1][j]<D[i][j-1]) j--;
            else i--;

    g<<l<<"\n";
    for(i=l;i>=1;i--)
        g<<sir[i]<<" ";
    return 0;
}
