#include <cstdio>
#define max(a,b) ((a)>(b) ? (a):(b))
int n, m, d[1030][1030], a[1030], b[1030];
void citire()
{
    int i;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;++i)
        scanf("%d", &a[i]);
    for(i=1;i<=m;++i)
        scanf("%d", &b[i]);
}
void dinamica()
{
    //determinarea matricii in care retin lungimea maxima a subsirului comun
    int i, j;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j]) //daca coincid adaug 1 la maximul precedent
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]); //daca nu sunt egale aleg maximul
}
void afisare()
{
    //construire sir
    int i=n, j=m, bst=0, sir[1030];
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            sir[++bst]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
    }
    //afisare
    printf("%d\n", bst);
    for(i=bst;i>=1;--i)
        printf("%d ", sir[i]);
    printf("\n");
}
void rezolva_problema()
{
    citire();
    dinamica();
    afisare();
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    rezolva_problema();
    return 0;
}
