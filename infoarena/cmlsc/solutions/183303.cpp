#include<stdio.h>   
  
int X,Y,sol[120],n,m,i,x[1200],y[1200],j,a[110][110];   
  
int max(int a,int b){   
  
if(a>=b)   
return a;   
  
return b;   
  
}   
  
  
int main(){   
  
  
FILE *f=fopen("cmlsc.in","r");   
  
fscanf(f,"%d %d",&n,&m);   
  
  for(i=1;i<=n;i++)   
  fscanf(f,"%d",&x[i]);   
  
  for(i=1;i<=m;i++)   
  fscanf(f,"%d",&y[i]);   
  
  
fclose(f);   
  
  
for(i=1;i<=n;i++){   
  for(j=1;j<=m;j++){   
  
    if(x[i]==y[j])   
    a[i][j]=a[i-1][j-1]+1;   
  
    else  
    a[i][j]=max(a[i-1][j],a[i][j-1]);   
  
  }   
  
  
}   
  
int k=0;   
  
X=n;   
Y=m;   
  
  
while(a[X][Y]!=0){   
  
  if(x[X]==y[Y]){   
  k++;   
  sol[k]=x[X];   
  X--;   
  }   
  
  else{   
  
    if(a[X-1][Y]>=a[X][Y-1])   
    X--;   
  
    else  
    Y--;
  
  }   
  
}   
  
  
FILE *g=fopen("cmlsc.out","w");   
fprintf(g,"%d\n",a[n][m]);   
  
  for(i=k;i>=1;i--)   
  fprintf(g,"%d ",sol[i]);   
  
fclose(g);   
  
return 0;   
}  