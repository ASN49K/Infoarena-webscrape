#include<bits/stdc++.h>
using namespace std;

FILE *in = fopen("cmlsc.in", "r");
FILE *out = fopen("cmlsc.out", "w");

const int nmax = 1024 + 5;
const int mmax = 256;
int n, m;
int rez[nmax][nmax];
int a[nmax], b[nmax];
bool vis[nmax];

void read()
{
    fscanf(in, "%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        fscanf(in, "%d", &a[i]);
        assert(a[i] <= 256);
    }
    for(int i = 1; i <= m; i++)
    {
        fscanf(in, "%d", &b[i]);
        assert(b[i] <= 256);
    }
}



int main()
{
    read();

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if( b[i] == a[j] ){
                rez[i][j] = rez[i-1][j-1] + 1;
                vis[b[i]] = true;
            }
            else
                rez[i][j] = max(rez[i][j-1], rez[i-1][j]);
        }
    fprintf(out, "%d\n", rez[m][n]);

    for(int i = 1; i <= mmax; i++)
        if(vis[i])
            fprintf(out, "%d ", i);
    return 0;
}
