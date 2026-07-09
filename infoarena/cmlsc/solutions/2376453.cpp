#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[1025], b[1025], sir[1025][1025], aux_n, aux_m, rez[1025];

void lcs()
{
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            if(a[i] == b[j])
            {
                sir[i][j] = sir[i - 1][j - 1] + 1;
            }
            else
            {
                sir[i][j] = max(sir[i - 1][j], sir[i][j - 1]);
            }
        }
    }

}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int j = 1; j <= m; j++)
    {
        scanf("%d", &b[j]);
    }
    for(int i = 0; i < n; i++)
    {
        sir[i][0] = 0;
    }
    for(int j = 0; j < m; j++)
    {
        sir[0][j] = 0;
    }
    lcs();
    aux_n = n;
    aux_m = m;
    int index = 1;
    while(aux_n != 0 && aux_m != 0)
    {
        if (sir[aux_n][aux_m] == sir[aux_n][aux_m -1])
        {
            aux_m--;
        }
        else
        {
            if(sir[aux_n][aux_m] == sir[aux_n - 1][aux_m])
            {
                aux_n--;
            }
            else
            {
                rez[index] = a[aux_n];
                index++;
                aux_n--;
                aux_m--;
            }
        }
    }
    printf("%d\n", sir[n][m]);
    for(int i = index - 1; i >= 1; i--)
    {
        printf("%d ", rez[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
