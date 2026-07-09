#include <cstdio>

using namespace std;

FILE *fin=freopen("cmlsc.in","r",stdin);
FILE *fout=freopen("cmlsc.out","w",stdout);

int m,n,p;
int a[1050],b[1050],mat[1050][1050],rez[1050];

void citire()
{
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d ",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d ",&b[i]);
}

inline int maxx(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void ceva()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if (a[i] == b[j])
                mat[i][j] = 1 + mat[i-1][j-1];
            else
                mat[i][j] = maxx(mat[i-1][j], mat[i][j-1]);

    for (int i = m, j = n; i; )
        if (a[i] == b[j]){
            rez[++p] = a[i];
             i--;
             j--;
        }
        else
            if (mat[i-1][j] < mat[i][j-1])
                j--;
            else
                i--;
}

void afisare()
{
    printf("%d\n",p);
    for(int i=p;p>0;p--)
        printf("%d ",rez[i]);
}

int main()
{
    citire();
    ceva();
    afisare();
    return 0;
}
