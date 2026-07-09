#include <iostream>
#include <fstream>
#define NMax 1024
#define FOR(i,a,b) for(i=a;i<b;i++)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
long long nr,i,j,v[3000],m,n;
int A[NMax+1],B[NMax+1],V[NMax+1];
int main()
{
    f>>n>>m;
    FOR(i,0,n)
    f>>A[i];
    FOR(i,0,m)
    f>>B[i];

    FOR(i,0,n)
    FOR(j,0,m)
    if(A[i]==B[j])
        V[nr]=A[i],nr++;

    g<<nr<<"\n";
    FOR(i,0,nr)
    g<<V[i]<<" ";

    return 0;
}
