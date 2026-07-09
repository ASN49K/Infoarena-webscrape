#include<stdio.h>

inline int maximum(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int n,m;
    int str1[1025];
    int str2[1025];
    int lcs[1025][1025];
    scanf("%d%d",&m,&n);

    for(int i = 1; i <= m; i++)
        scanf("%d",&str2[i]);
    for(int j = 1; j <= n; j++)
        scanf("%d",&str1[j]);

    for(int i = 0; i<=n; i++)
        lcs[i][0] = 0;
    for(int i = 0; i <= m; i++)
        lcs[0][i] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(str1[i] == str2[j])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = maximum(lcs[i-1][j-1],lcs[i][j-1]);

            printf("%d ",lcs[i][j]);
        }
        printf("\n");
    }

    printf("%d\n",lcs[n][m]);

    int previous = 0 ;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if( lcs[i][j] > previous)
            {
                printf("%d ",str1[i]);
                previous++;
            }
    printf("\n");
    return 0;
}
