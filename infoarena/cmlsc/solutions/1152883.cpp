#include<cstdio>
#include<cstdlib>
#define Nmax 1024
#define maxim(a, b) (a>b) ? a:b

int m, n, cnt, a[Nmax], b[Nmax], C[Nmax][Nmax], sir[Nmax];

void citeste()
{
    //fisierul de intrare
    freopen("cmlsc.in", "r", stdin);

    scanf("%d %d", &m, &n);
    for(int i=1; i<=m; i++)
        scanf("%d", &a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d", &b[i]);
}

//C[k][h]-lungimea celui mai lung subsir comun a prefixelor Xk si Yh
void progr_dinamica()
{
    int i, j;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                C[i][j]=C[i-1][j-1]+1;
            else
                C[i][j]=maxim(C[i-1][j], C[i][j-1]);
}

void scrie()
{
    //fisierul de iesire
    freopen("cmlsc.out", "w", stdout);

    int i, j;
    for(i=m, j=n; i;    )
        if(a[i]==b[j])
            sir[++cnt]=a[i], --i, --j;
        else
            if(C[i-1][j]>C[i][j-1])
                --i;
            else
                --j;
    printf("%d\n", cnt);
    for(i=cnt; i; i--)
        printf("%d ", sir[i]);

}


int main()
{
    citeste();
    progr_dinamica();
    scrie();
    return 0;
}
