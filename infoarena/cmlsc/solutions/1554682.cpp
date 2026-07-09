#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a[1050],b[1050],matrice[1050][1050],sir[1050],z;

void afisare()
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            printf("%d ",matrice[i][j]);
        }
        printf("\n");
    }
}

void recursiv(int x, int y)
{
    if(matrice[x][y]==0)
    {
        return;
    }
    if(a[x]==b[y])
    {
        recursiv(x-1,y-1);
        printf("%d ",a[x]);
    }
    else
    {
        if(matrice[x][y]==matrice[x-1][y])
        {
            recursiv(x-1,y);
            return;
        }
        if(matrice[x][y]==matrice[x][y-1])
        {
            recursiv(x,y-1);
        }
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int lungime=0,x,y;

    scanf("%d %d\n",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d ",&a[i]);
    }
    for(int i=1; i<=m; i++)
    {
        scanf("%d ",&b[i]);
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                matrice[i][j]=matrice[i-1][j-1]+1;
                if(matrice[i][j]>lungime)
                {
                    lungime=matrice[i][j];
                    x=i;
                    y=j;
                }
            }
            else
            {
                matrice[i][j]=max(max(matrice[i][j-1],matrice[i-1][j-1]),matrice[i-1][j]);
            }
        }
    }

    printf("%d\n",lungime);

    recursiv(x,y);

    return 0;
}
