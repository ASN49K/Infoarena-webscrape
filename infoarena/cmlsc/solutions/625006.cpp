/*
    d[i][j] = (a[i] == b[j])? a[i-1][j-1]+1: max (a[i-1][j],a[i][j-1])
    fara initializari


    solutie O(N) memorie pt dinamici
    retin de la elem n/2 un vector pt fiecare elem din linia curenta catre ce coloana de pe linia n/2 duce drumul
    apoi apelez recursiv pt sfert stanga sus si dreapta jos
*/

#include <cstdio>
#include <cstring>

const int N_MAX = 1030;
const int M_MAX = 1030;

int d[2][N_MAX];
int a[M_MAX],m,b[N_MAX],n;
int v[N_MAX]; //v[j] -> catre elem de pe ce coloana din linia n/2 ajunge drumul solutie care pleaca de pe linia curenta si coloana j
int v_pred[N_MAX];

inline int max (int a, int b)
{
    return (a>b)?a:b;
}

void citire()
{
    scanf("%d%d",&m,&n);
    for (int i = 1; i <= m; ++i)
        scanf("%d",&a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d",&b[i]);
}

void dinamica (int x1, int y1, int x2, int y2)
{
    if (x1 == x2)//cmlsc dintre elem x1 din sirul a si subsecventa y1...y2 din sirul b
    {
        for (int j = y1; j <= y2; ++j)
            if (a[x1] == b[j])
            {
                printf("%d ",a[x1]);
                return;
            }
        return;
    }
    for (int j = y1; j <= y2; ++j)
        d[(x1-1) % 2][j] = 0;
    for (int i = x1; i <= x2; ++i) {
        d[i%2][y1 - 1] = 0;
        for (int j = y1; j <= y2; ++j)
        {
            d[i%2][j] = (a[i] == b[j])?d[(i-1)%2][j-1] + 1:max(d[(i-1)%2][j],d[i%2][j-1]);  //Atentie la procenta cu nr negative (merg prost pe C), dar la %2 e corect.
            if (x1 == 1 && y1 == 1 && x2 == m && y2 == n && i == m && j == n)
                printf("%d\n",d[i%2][j]);
            if (i == (x1 + x2)/2)
                v[j] = j;
            if (i > (x1 + x2)/2)
            {
                if (a[i] == b[j])
                    v[j] = v_pred[j-1];
                else
                    if (d[(i-1)%2][j] >= d[i%2][j-1])
                        v[j] = v_pred[j];
                    else
                        v[j] = v[j-1];
            }
        }
        for (int j = y1; j <= y2; ++j)
            v_pred[j] = v[j];
    }
    int aux = v[y2];
    dinamica(x1,y1,(x1+x2)/2,aux);
    dinamica((x1+x2)/2+1,aux+1,x2,y2);

}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    dinamica(1,1,m,n);
    return 0;
}
