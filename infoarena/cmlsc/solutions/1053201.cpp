#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
#include <cmath>
#define x first
#define y second
#define Nmax 1024
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[Nmax], b[Nmax], d[Nmax][Nmax], sol[Nmax], best, N, M;

int main()
{
    f>>N>>M;
    for (int i=1; i<=N; ++i) f>>a[i];
    for (int j=1; j<=M; ++j) f>>b[j];

    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j)
            if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
                else d[i][j]=max(d[i-1][j], d[i][j-1]);

    for (int i=N, j=M; i;)
        if (a[i]==b[j]) sol[++best]=a[i], --i, --j;
            else if (d[i-1][j]<d[i][j-1]) --j;
                else --i;

    g<<best<<'\n';
    for (int i=1; i<=best; ++i)
        g<<sol[i]<<' '; g<<'\n';
    return 0;
}
