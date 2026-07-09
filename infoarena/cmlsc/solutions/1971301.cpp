#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, i, j, k;
int a[1025], b[1025], sir[1025];
int d[1025][1025];

int maxim(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

int cmlsc(int a[], int b[])
{
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
    i = m;
    j = n;
    k = 0;
    while(i>=1 && j>=1)
        if(a[i]==b[j])
        {
            sir[++k] = a[i];
            --i;
            --j;
        }
        else
            if(d[i-1][j]>d[i][j-1])
                --i;
            else
                --j;
}

int main()
{
    fin >> m >> n;
    for(i=1; i<=m; i++)
        fin >> a[i];
    for(j=1; j<=n; j++)
        fin >> b[j];
    cmlsc(a, b);
    fout << k << "\n";
    for(i=k; i>=1; i--)
        fout << sir[i] << " ";
    fin.close();
    return 0;
}
