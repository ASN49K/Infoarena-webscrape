#include <stdio.h>
int a[1025],b[1025],c[1025];
int m[1025][1025];
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
        scanf ("%d",&a[i]);
    for (i=1; i<=s; ++i)
        scanf ("%d",&b[i]);
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
    for (i=n, j=s; i; )
    {
        if (a[i]==b[j])
        {
            c[++x]=a[i];
            --i;
            --j;
        }
        else if (m[i-1][j]<m[i][j-1])  
            --j;  
        else  
            --i;  
    }
    printf ("%d\n",m[n][s]);
    for (i=x; i; --i)
        printf ("%d ",c[i]);
}
int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read ();
    solve ();
    return 0;
}
