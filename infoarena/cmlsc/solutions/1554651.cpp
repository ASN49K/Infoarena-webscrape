#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a[1050],b[1050],matrice[1050][1050],sir[1050];

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

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int lungime=0;

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
                lungime++;
            }
            else
            {
                matrice[i][j]=max(max(matrice[i][j-1],matrice[i-1][j-1]),matrice[i-1][j]);
            }
        }
    }
    int x=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(matrice[i][j]==x+1)
            {
                sir[x]=a[i];
                x++;
            }
        }
    }
    printf("%d\n",lungime);

    for(int i=0; i<x; i++)
    {
        printf("%d ",sir[i]);
    }




    return 0;
}
