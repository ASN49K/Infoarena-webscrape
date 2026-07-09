#include <cstdio>
#include <vector>

#define dmax 1025

using namespace std;

int a[dmax], b[dmax], c[dmax][dmax], n, m, sol[dmax];

void read()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%i %i", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%i", &a[i]);
    for(int i=1; i<=m; i++)
        scanf("%i", &b[i]);

}

int main()
{

    read();

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
            c[i][j]=max(c[i-1][j], c[i][j-1]);
        }

    printf("%i \n",c[n][m]);
    int lg=0;
    for(int i=n, j=m;lg<c[n][m];)
    {
        if(a[i]==b[i])
        {
            i--; j--;
            sol[++lg]=a[i];
        }
        else if(c[i-1][j]<=c[i][j-1])
        {

            sol[++lg]=b[j]; j--;
        }
        else{

            sol[++lg]=a[i]; i--;

        }
    }

for(int i=c[n][m];i>0;i--)
    printf("%i ", sol[i]);
    return 0;
}
