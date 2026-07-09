#include <cstdio>

using namespace std;

const int MAX_N = 1024, MAX_M = 1024;

FILE *in, *out;

int s1[MAX_N+1], s2[MAX_M+1];
int d[MAX_N+1][MAX_N+1];
int sol[MAX_N+1];
int m, n;

int maxim(int a, int b)
{
    return (a > b)?a:b;
}

int main()
{
    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");

    fscanf(in, "%d %d", &m, &n);

    int i, j;
    for(i = 1; i <= m; i++)
        fscanf(in, "%d", &s1[i]);
    for(i = 1; i <= n; i++)
        fscanf(in, "%d", &s2[i]);

    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
        {
            if(s1[i] == s2[j])
                d[i][j] = d[i-1][j-1]+1;
            else
                d[i][j] = maxim(d[i][j-1], d[i-1][j]);
        }

    int l = d[m][n];
    int cl = l;
    i = m;
    j = n;
    while(i > 0)
    {
        if(s1[i] == s2[j])
        {
            sol[l] = s1[i];
            i--;
            j--;
            cl--;
        } else if(d[i-1][j] > d[i][j-1])
            i--;
        else
            j--;
    }
    fprintf(out, "%d\n", l);
    for(i = 1; i <= l; i++)
        fprintf(out, "%d ", sol[i]);
    return 0;
}
