#include <iostream>
#include <fstream>
#include <stdio.h>
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int a[1024], b[1024], d[1024][1024], s[1024], k, n, m;
int main()
{int i, j;
    f>>m>>n;
    for (i=1; i<=m; i++)
        f>>a[i];
    for (i=1; i<=n; i++)
        f>>b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            if (a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=maxim(d[i-1][j], d[i][j-1]);
    for (i=m, j=n; i;)
        if (a[i]==b[j]) s[++k]=a[i], i--, j--;
        else if (d[i-1][j]<d[i][j-1]) j--;
             else i--;
    for (i=k; i>=1; i--)
        g <<s[i]<<" ";
    return 0;
}
