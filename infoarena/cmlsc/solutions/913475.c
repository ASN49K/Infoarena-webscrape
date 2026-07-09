#include <stdio.h>
#include <stdlib.h>
int X[257], Y[257], Sub[257];
int t=0,m,n;
 int LSC(int i, int j)
    {
        if(X[i]==Y[j])
        {
            Sub[t]=X[i];

            t++;
            m=i-1;
            if((i>0)&&(j>0))
                LSC(i-1,j-1);
            else
                return 0;
        }
        else
            if((i==0)&&(j>0))
                LSC(m,j-1);
            else
                LSC(i-1,j);
        return -1;
    }
int main()
{
    int i;
    freopen("cmls.in", "r", stdin);
    freopen("cmls.out", "w", stdout);
    scanf("%d %d", &m, &n);
    for(i=0; i<m;i++)
        scanf("%d", &X[i]);
    for(i=0; i<n;i++)
        scanf("%d", &Y[i]);
    LSC(m-1,n-1);
    printf("%d\n",t);
    for(i=t-1;i>=0;i--)
        printf("%d ", Sub[i]);
    return 0;
}
