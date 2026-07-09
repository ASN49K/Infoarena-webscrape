#include <iostream>
#include <fstream>
#include <stdlib.h>
#define maxim(a, b) ((a > b) ? a : b)
#define NMax 1024
#define FOR(i, a, b) for(i = a; i <= b; i++)
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,a[NMax],b[NMax],n,m,D[NMax][NMax],s[NMax],bst;
int main()
{

    f>>m>>n;
    FOR (i, 1, m)
        f>>a[i];
    FOR (j, 1, n)
        f>>b[j];
    FOR (i, 1, m)
        FOR (j, 1, n)
            if(a[i] == b[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);
    for(i = m, j = n; i; )
        if(a[i] == b[j])
            s[++bst] = a[i], --i, --j;
        else if(D[i-1][j] < D[i][j-1])
            --j;
        else --i;
    g<<bst<<"\n";
    for(i=bst;i;i--)
        g<<s[i]<<" ";


}
