#include<bits/stdc++.h>
using namespace std;

FILE *in = fopen("cmlsc.in", "r");
FILE *out = fopen("cmlsc.out", "w");

const int nmax = 1024 + 5;
const int mmax = 256;
int n, m;
int rez[nmax][nmax];
int a[nmax], b[nmax];
vector<int>v;
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
            if( b[i] == a[j] )
                rez[i][j] = rez[i-1][j-1] + 1;
            else
                rez[i][j] = max(rez[i][j-1], rez[i-1][j]);
        }
    fprintf(out, "%d\n", rez[m][n]);

    int x, y;
    x = m; y = n;
    while(rez[x][y] != 0)
    {
        if(b[x] == a[y])
        {
            v.push_back(b[x]);
            x -= 1;
            y -= 1;
        }
        else if( rez[x-1][y] > rez[x][y-1] )
            x -=1;
        else if( rez[x][y] != rez[x-1][y-1] + 1 && rez[x][y] == rez[x-1][y] && rez[x][y] == rez[x][y-1] )
            y -=1;
    }

    for( size_t i = 0; i != v.size(); ++i )
    {
        fprintf(out, "%d ", v[v.size() - i- 1]);
    }
    return 0;
}
