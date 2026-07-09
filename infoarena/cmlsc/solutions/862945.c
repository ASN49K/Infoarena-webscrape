#include <stdio.h>
#define maxim(a,b) ((a>b) ? a : b)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define MAXSIZE 1<<10


int A[MAXSIZE],B[MAXSIZE],C[MAXSIZE][MAXSIZE],sir[MAXSIZE],l,n,m;

int main(void)
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j;
    scanf("%d %d",&n,&m);
    FOR(i,1,n)
        scanf("%d",&A[i]);
    FOR(i,1,m)
        scanf("%d",&B[i]);

    FOR(i,1,n)
        FOR(j,1,m)
            if(A[i]==B[j])
                C[i][j]=C[i-1][j-1]+1;
            else
                C[i][j]=maxim(C[i-1][j],C[i][j-1]);

    for(i=n,j=m;i;)
        if(A[i]==B[j])
        {
            sir[++l]=A[i];
            --i;
            --j;
        }
        else if(C[i-1][j]<C[i][j-1])
            --j;
            else
            --i;

    printf("%d\n",l);
    for(;l;l--)
        printf("%d ",sir[l]);
    return 0;
}
