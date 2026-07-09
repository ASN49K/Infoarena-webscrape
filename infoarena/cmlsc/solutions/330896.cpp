#include<stdio.h>
#include<string.h>
int m,n,lmax;
unsigned char d[1030],a[1030],b[1030],c[1030][1030];
void read()
{
int i;
scanf("%d%d",&m,&n);
for(i=1;i<=m;++i)
   scanf("%u",&a[i]);
for(i=1;i<=n;++i)
   scanf("%u",&b[i]);
}

int max(int a,int b)
{
if(a>b)
  return a;
return b;
}

int cmlsc()
{
int i,j,mx;
for(i=1;i<=m;++i)
   for(j=1;j<=n;++j)
      {
      if(a[i]==b[j])
         c[i][j]=c[i-1][j-1]+1;
      else
         {
         mx=max(c[i][j-1],c[i-1][j]);
         c[i][j]=mx;
         }
      }
lmax=c[m][n];
}

void constr()
{
int u=0,i,j;
for(i=m;i>=1;--i)
   {
   for(j=n;j>=1;--j)
      if(c[i][j]==lmax && a[i]==b[j])
       {
       d[++u]=a[i];
       --lmax;
       }
   }
}

int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

int i,lm;
read();
cmlsc();
lm=lmax;
printf("%d\n",lmax);
constr();
for(i=lm;i>=1;--i)
   printf("%u ",d[i]);
return 0;
}
