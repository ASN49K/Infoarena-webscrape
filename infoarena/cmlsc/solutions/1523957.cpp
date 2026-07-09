#include <stdio.h>
#define maxn 1027

int a[maxn], b[maxn], maxx = 0, x[maxn], n, m, nr = 0, sol[maxn], i, p;


void read()
{
    int i;

    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i <= m; i++)
        scanf("%d", &b[i]);
}


int verif()
{
    int i, j = 1, ok;

    nr = 0;

    for (i = 1; i <= n && j <= m; i++)
        if(x[i])
        {
            ok = 0; nr++;

            for (; j <= m && !ok; j++)
                if(a[i] == b[j])
                    ok = 1;

            if(!ok)
                return 0;
        }

    return 1;
}



void backt(int k)
{
    if(k == n+1)
    {
        if(verif())
            if(nr > maxx)
            {
                 maxx = nr; p = 0;

                 for(i = 1; i <= n; i++)
                    if(x[i])
                      sol[++p] = a[i];
            }

    }
    else
        {

            x[k] = 0;

            backt(k + 1);

            x[k] = 1;

            backt(k + 1);
        }
}



int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    read();

    backt(1);

    printf("%d\n", maxx);

    for (i = 1; i < maxx; i++)
        printf("%d ", sol[i]);
    printf("%d\n", sol[maxx]);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
