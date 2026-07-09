#include<stdio.h>
int n,a[1025],m,k,afis[1025],b[1025],lin;
void show ()
{
     int i;
     printf("%d\n",k);
     for(i=1;i<=k;++i)
     printf("%d ",afis[i]);
}

int solve1 ()
{
    int i,j;
    lin=1;
    for(j=1;j<=n;++j)
    for(i=lin;i<=m;++i)
    if(b[i]==a[j])
    {
                  lin=i;
                  ++k;
                  afis[k]=b[i];
    }                         
}

int solve ()
{
    int i,j;
    lin=1;
    for(j=1;j<=m;++j)
    for(i=lin;i<=n;++i)
    if(a[i]==b[j])
    {
                  lin=i;
                  ++k;
                  afis[k]=a[i];
    }                  
}

void read ()
{
     int i,x,y;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;++i)
     scanf("%d",&a[i]);
     for(i=1;i<=m;++i)
     scanf("%d",&b[i]);
     if(n>m)
     solve ();
     else
     solve1 ();
}

int main ()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    read ();
    show ();
    return 0;
}
