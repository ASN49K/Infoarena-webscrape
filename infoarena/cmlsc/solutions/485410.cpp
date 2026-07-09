#include <iostream>

using namespace std;
int s[2000][2000],a[2000],b[2000],m,n,rez[2000],p=0;
void fabrica()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[j-1]==b[i-1])
                s[i][j]=s[i-1][j-1]+1;
            else
                if(s[i][j-1]>s[i-1][j])
                    s[i][j]=s[i][j-1];
                else
                    s[i][j]=s[i-1][j];
}
void cauta(int i, int j)
{   if(i>0&&j>0)
    if(a[j-1]==b[i-1])
    {   rez[p]=a[j-1]; p++; cauta(i-1,j-1);}
    else
        if(s[i][j-1]>s[i-1][j])
            cauta(i,j-1);
        else
            cauta(i-1,j);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d\n%d\n", &n,&m);
    for(int i=0;i<n;i++)
        scanf("%d ",&a[i]);
    scanf("\n");
    for(int i=0;i<m;i++)
        scanf("%d ",&b[i]);
    fabrica();
    printf("%d\n",s[m][n]);
    cauta(m,n);
    for(int i=p-1;i>=0;i--)
        printf("%d ",rez[i]);


    return 0;
}
