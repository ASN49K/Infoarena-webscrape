#include<stdio.h>

int a[1025],b[1025],c[1025],d=1,i,j,m,n,poz=1;


int main(void){

freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

scanf("%d %d",&m,&n);

for(i=1; i<m+1; i++)scanf("%d",&a[i]);

for(i=1; i<n+1; i++)scanf("%d",&b[i]);

for(i=1; i<m+1; i++)for(j=poz; j<n+1; j++) if(a[i]==b[j]){ c[d]=a[i]; d++;poz=j+1; break;  }

printf("%d\n",d-1);

for(i=1; i<d; i++)printf("%d ",c[i]);

return 0;
} 
