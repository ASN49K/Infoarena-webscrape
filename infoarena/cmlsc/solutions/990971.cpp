#include <cstdio>

int a[1030],b[1030];

int c[1030][1030],prv[1030][1030];

void printeaza( int l, int c)
{
    if(prv[l][c]==1)
        printeaza(l-1,c-1);
    if(prv[l][c]==2)
        printeaza(l-1,c);
    if(prv[l][c]==3)
        printeaza(l,c-1);

    if(a[l]==b[c])
        printf("%d ",a[l]);

}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&a[0],&b[0]);

    for(int i=1;i<=a[0]; i++)
        scanf("%d",&a[i]);

    for(int j=1; j<=b[0]; j++)
        scanf("%d",&b[j]);

    for(int i=1;i<=a[0]; i++)
        for(int j=1;j<=b[0]; j++)
        {
            if(a[i]==b[j])
            {
                c[i][j]=1+c[i-1][j-1];
                prv[i][j]=1;
            }

            else
            {
                if(c[i-1][j]>c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    prv[i][j]=2;
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    prv[i][j]=3;
                }

            }

        }
    printf("%d\n",c[a[0]][b[0]]);
    printeaza(a[0],b[0]);

    return 0;
}
