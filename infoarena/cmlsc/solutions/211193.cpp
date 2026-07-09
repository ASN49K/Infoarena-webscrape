#include<stdio.h>
int n,a[1025],m,k,afis[1025],b[1025];
void show ()
{
     int i;
     printf("%d\n",k);
     for(i=1;i<=k;++i)
     printf("%d ",afis[i]);
}

int solve ()
{
    int i,j;
    for(j=1;j<=m;++j)
    for(i=1;i<=n;++i)
    if(a[i]==b[j])
    {
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
}

int main ()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    read ();
    solve ();
    show ();
    return 0;
}
