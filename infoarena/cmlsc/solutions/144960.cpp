#include <stdio.h>
#define max(a,b) ((a>b)?a:b)

long n,m,i,j,a[1024],b[1024],sir[1024],l,p;
unsigned int C[1024][1024] ={0};

int comun(){
   int i,j;
   
   for (i=n;i>0;i--)
      for (j=m;j>0;j--)
	      if (a[i]==b[j])
             C[i][j] = C[i+1][j+1] + 1;
	      else
	          C[i][j] = max(C[i+1][j],C[i][j+1]);
   return C[1][1];
}


int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    
    scanf("%ld %ld",&n,&m);
    for (i=1;i<=n;i++)
        scanf("%ld",&a[i]);
    for (j=1;j<=m;j++)
        scanf("%ld",&b[j]);

    l=comun();
    printf("%ld\n",l);
    i=n;j=m;
    p=l;
    while (i&&j){
          if (a[i]==b[j]){
             sir[p]=a[i];
             p--;
             i--;
             j--;
          }
          else{
              if (p==0)break;
              if (C[i-1][j]<C[i][j-1])
                 j--;
              else i--;
          }
    }
    for (i=1;i<=l;i++)
        printf("%ld ",sir[i]);
    printf("\n");

return 0;
}
