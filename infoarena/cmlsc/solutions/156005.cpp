#include <cstdio>
#define vv 1025

using namespace std;

int a[vv],b[vv],w[vv][vv],m,n,q=0,s[vv];

void citire()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d%d", &n, &m);
    int i;
    for (i=1; i<=n; i++)
	scanf("%d", &a[i]);
    for (i=1; i<=m; i++)
        scanf("%d", &b[i]);
    fclose(stdin);
}

int max(int w,int q)
{
if (w>q)
   return w;
return q;
}

void subsir_comun_maximal()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])
                w[i][j]=1+w[i-1][j-1];
            else
                w[i][j]=max(w[i-1][j],w[i][j-1]);
}

void afisare(int q, int e)
{
    for (int i=e; i>0; i--)
        if (w[q-1][i-1]+1==w[q][i] && w[q][i]>0 && w[q][i-1]<w[q][i])
        {
            afisare(q-1, i-1);
            printf("%d ",b[i]);
            break;
        }
}

int main()
{
    citire();
    subsir_comun_maximal();
    freopen("cmlsc.out","w",stdout);
//    printf("%d\n", w[n][m]);
    //afisare(n,m);
    for (int i=n, j=m; i;)
        if (a[i]==b[j])
            s[++q]=a[i], --i, --j;
        else if (w[i-1][j]<w[i][j-1])
            --j;
        else
            --i;
    printf("%d\n", q);
    for (int i=q; i; --i)
        printf("%d ", s[i]);

    fclose(stdout);
    return 0;
}
