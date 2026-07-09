#include <stdio.h>
#include <stdlib.h>
unsigned short int max(unsigned short int a,unsigned short int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    unsigned short int n,m,bst;
    scanf("%hu",&n);
    scanf("%hu",&m);
    unsigned char *v=malloc(sizeof(unsigned char)*n);
    unsigned char *u=malloc(sizeof(unsigned char)*m);
    unsigned short int **dp=malloc(sizeof(unsigned short int*)*n);

    for(unsigned short int i=0; i<n; i++)
    {
        dp[i]=malloc(sizeof(unsigned short int)*m);
        scanf("%u",&v[i]);
    }

    for(unsigned short int i=0; i<m; i++)
        scanf("%u",&u[i]);

    if(v[0]==u[0])
        dp[0][0]=1;
    else dp[0][0]=0;

    for(unsigned short int i=0; i<n; i++)
        for(unsigned short int j=(i==0) ? 1:0; j<m; j++)
        {
            if(v[i]==u[j])
            {
                if(i==0 || j==0) dp[i][j]=1;
                else dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                if(i==0) dp[i][j]=dp[i][j-1];
                else
                {
                    if(j==0) dp[i][j]=dp[i-1][j];
                    else dp[i][j]=(dp[i-1][j]>dp[i][j-1]) ? dp[i-1][j]:dp[i][j-1];
                }
            }

        }


    printf("%u\n",dp[n-1][m-1]);
    unsigned short int *arr=malloc(sizeof(unsigned short int)*bst);
    int i=n;
    int j=m;

    while(i>0 || j>0)
    {
        if(v[i]==u[j])
        {
            arr[bst++]=v[i];
            i--;
            j--;
        }
        else
        {
            if(i==0) j--;
            else
            {
                if(j==0) i--;
                else
                {
                    if(dp[i-1][j]>dp[i][j-1])
                        i--;
                    else j--;
                }
            }

        }
    }

    if(v[i]==u[j])
        arr[bst++]=v[i];

    for(int i=bst-1;i>0;i--)
        printf("%u ",arr[i]);

    free(arr);
    free(v);
    free(u);

    for(int i=0;i<n;i++)
        free(dp[i]);
    free(dp);

    return 0;
}
