#include <stdio.h>
#define maxn 1027

int a[maxn], b[maxn], maxx = 0, x[maxn], n, m, sol[maxn], i;


void read()
{
    int i;

    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i <= m; i++)
        scanf("%d", &b[i]);
}


int verif(int k)
{
    int i, j = 1, ok;

    /*for (i = 1; i <= k && j <= m; i++)
        for (; j <= m && b[j] != x[i]; j++);

    return j <= m;*/


    for(i = 1; i <= k && j <= m; i++)
    {
        ok = 0;

        for(; j <= m && !ok; j++)
            if(b[j] == x[i])
                ok = 1;

        if(!ok)
            return 0;
    }

    return 1;

}



void back(int niv, int l)
{
    int i;

    if(niv == n+1)
    {
        if(verif(l))
            if(l > maxx)
             {
                 maxx = l;

                   for (i = 1; i <= maxx; i++)
                    sol[i] = x[i];
             }

        return ;
    }

    back(niv + 1, l);

    x[l + 1] = a[niv];

    back(niv + 1, l + 1);
}


int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    read();

    back(1, 0);

    printf("%d\n", maxx);

    for (i = 1; i < maxx; i++)
        printf("%d ", sol[i]);
    printf("%d\n", sol[maxx]);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
