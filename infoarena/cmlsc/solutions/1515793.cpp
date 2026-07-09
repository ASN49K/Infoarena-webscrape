#include <cstdio>
#include <algorithm>

using namespace std;

int a[1027], b[1027], mat[1027][1027], sol[1027];

int main()
{
    FILE *in, *out;
    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");
    int m, n, i, j, ind;
    fscanf(in, "%d", &m);
    fscanf(in, "%d", &n);
    for(i = 1; i <= m; i++)
        fscanf(in, "%d", &a[i]);
    for(i = 1; i <= n; i++)
        fscanf(in, "%d", &b[i]);
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(a[i] == b[j])
                mat[i][j] = 1 + mat[i-1][j-1];
            else
            {
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    fprintf(out, "%d\n", mat[m][n]);
    i = m;
    j = n;
    ind = 1;
    while(mat[i][j] != 0)
    {
        if(a[i] == b[j])
        {
            sol[ind++] = a[i];
            i--;
            j--;
        }
        else
        {
            if(mat[i-1][j] > mat[i][j-1])
            {
                i--;
            }
            else
                j--;
        }
    }
    ind--;
    for(i = ind; i>= 1; i--)
        fprintf(out, "%d ", sol[i]);
    return 0;
}
