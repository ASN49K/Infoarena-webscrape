#include <stdio.h>
char a[1025],b[1025],f[1025];
char m[1025][1025];
int n,s,x;
int max (int a,int b)
{
    return a>b?a:b;
}
void read ()
{
    int i;
    scanf ("%d%d",&n,&s);
    for (i=1; i<=n; ++i)
        scanf ("%c",a[i]);
    for (i=1; i<=s; ++i)
        scanf ("%c",b[i]);
}
void solve ()
{
    int i,j;
    for (i=1; i<=n; ++i)
        for (j=1; j<=s; ++j)
            if (a[i]==b[j])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=max (m[i-1][j],m[i][j-1]);
    printf ("%c\n",a[n][m]);
    for (i=n, j=s; i>=1 && j>=1; )
    {
        if (a[i]==b[i])
        {
            f[++x]=a[i];
            --i;
            --j;
        }
        else if (m[i-1][j]<m[i][j-1])  
            --j;  
        else  
            --i;  
    }
    for (i=x; i>=1; --i)
        printf ("%c ",f[i]);
}
int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read ();
    solve ();
    return 0;
}
