#include <cstdio>


int m,n, A[1024], B[1024], D[1024][1024], sir[1024], bst;


int maxim(int x, int y)
{
    if(x>y)
        return x;
    return y;
}



int main(void)
{

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&B[i]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i]==B[j])
            {
                D[i][j]=1+D[i-1][j-1];
            }
            else
            {
                D[i][j]=maxim(D[i-1][j],D[i][j-1]);
            }
        }
    }
    for(int i=m,j=n;i;)
    {
        if (A[i]==B[j])
        {
            sir[bst]=A[i],i++,j++;
            bst++;
        }
        else
        {
            if(D[i-1][j]<D[i][j-1])
                j++;
            else
                i++;
        }
    }
    printf("%d\n",bst);
    for(int i=bst;i>=1;i--)
    {
        printf("%d ",sir[i]);
    }
    return 0;
}
