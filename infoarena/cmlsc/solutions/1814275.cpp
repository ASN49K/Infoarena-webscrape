#include <cstdio>

#define max(a,b) ((a > b) ? a : b)

using namespace std;

int m,n,k=0;
int A[1025],B[1025],best[1025][1025],sol[1025];

void Read()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%i %i",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%i",&A[i]);
    for(int i=1;i<=n;i++)
        scanf("%i",&B[i]);
}

void Dinamic()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i] == B[j])
            {
                best[i][j] = best[i-1][j-1] + 1;
            }
            else
            {
                best[i][j] = max(best[i-1][j], best[i][j-1]);
            }
        }
    }

    int i=m,j=n,k=0;
    while(i > 0 && j > 0)
    {
        if(A[i] == B[j])
        {
            sol[++k] = A[i];
            i--;
            j--;
        }
        else if(best[i-1][j] > best[i][j-1])
            i--;
        else
            j--;
    }
    printf("%i\n",k);
    for(int i=k;i>=1;i--)
    {
        printf("%i ",sol[i]);
    }
}

int main()
{
    Read();
    Dinamic();
    return 0;
}
