#include<iostream>
#include<cstdio>
using namespace std;
int ct = 1, v1[1027], v2[1027], m, n, d[1027][1027], vaux[1027];
int main()
{
    FILE* in = fopen("cmlsc.in", "r");
    FILE* out = fopen("cmlsc.out", "w");
    fscanf(in, "%d%d", &m, &n);
    for(int i = 0; i <= m; ++i)
    {
        d[i][0] = 0;
        if(i == 0) continue;
        fscanf(in, "%d", &v1[i]);
    }
    for(int i = 0; i <= n; ++i)
    {
        d[0][i] = 0;
        if(i == 0) continue;
        fscanf(in, "%d", &v2[i]);
    }
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(v1[i] == v2[j]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    int i = m;
    int j = n;
    fprintf(out, "%d\n", d[m][n]);
    while(true)
    {
        if(v1[i] == v2[j])
        {
            vaux[ct] = v1[i];
            ++ct;
        }
        if(d[i][j] == d[i - 1][j - 1] + 1 && v1[i] == v2[j])
        {
            --i;
            --j;
        }
        else
        {
            if(d[i - 1][j] < d[i][j - 1]) -- j;
            else --i;
        }
        if(i == 0 || j == 0) break;
    }
    --ct;
    for(int i = ct; i >= 1; --i)
    {
        fprintf(out, "%d ", vaux[i]);
    }
}
