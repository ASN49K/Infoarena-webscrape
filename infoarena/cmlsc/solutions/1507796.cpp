#include <iostream>
#include <stdio.h>

int mat[1030][1030],m,n;
int a[1030],b[1030];

using namespace std;

void citire()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int j=1;j<=m;j++)
        scanf("%d",&b[j]);

}

void cmlsc()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    printf("%d\n",mat[n][m]);
    int i=n,j=m;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            printf("%d ",a[i]);
            i--,j--;
        }
        else
            if(mat[i-1][j]<mat[i][j-1])
                j--;
        else
            i--;

    }
}

int main()
{

    citire();
    cmlsc();
    return 0;
}
