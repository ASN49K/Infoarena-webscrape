#include <stdio.h>

long i,j,n,m,best;
long a[1100],b[1100],d[1100][1100],s[1100];

inline long maxim(long q,long w)
{
  if(q>w) return q; else return w;     
}

int main()
{
  freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
  
  scanf("%ld %ld\n",&n,&m);
  for(i=1;i<=n;++i) scanf("%ld ",&a[i]);
  scanf("\n");  
  for(i=1;i<=m;++i) scanf("%ld ",&b[i]);
    
  for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
      if(a[i]=b[j]) d[i][j]=d[i-1][j-1]+1;
      else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
      
  
  i=n;
  j=m;          
  best=0;           
  while(i&&j)
  {
    if(a[i]=b[j]) { s[++best]=a[i]; --i; --j; }
      else if(d[i][j-1]>d[i-1][j]) --j;
      else --i;               
                   
  }
    
  printf("%ld\n",best);
  for(i=best;i>=1;--i) printf("%ld ",s[i]);  
    
    
  return 0;    
}
