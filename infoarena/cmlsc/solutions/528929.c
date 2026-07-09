#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
   if(a>=b) return a; 
   else return b;
}

int main(){
int *a,*b,*sir,**c,m,n,i,j,l;    
FILE *f;

f=fopen("cmlsc.in","r");
fscanf(f,"%d", &m);
fscanf(f,"%d", &n);

a=(int*)malloc(m*sizeof(int));
b=(int*)malloc(n*sizeof(int));
for(i=0;i<m;i++)
   fscanf(f,"%d", a+i);
for(i=0;i<n;i++)
   fscanf(f,"%d", b+i);
fclose(f);

c=(int **)malloc((m+1)*sizeof(int*));
for(i=0;i<=m;i++)
   c[i]=(int*)malloc((n+1)*sizeof(int));
   
for(i=0;i<=m;i++)
   c[i][0]=0;
for(i=0;i<=n;i++)
   c[0][i]=0;

for(i=1;i<=m;i++){
  for(j=1;j<=n;j++){
    if(a[i-1]==b[j-1]) 
      c[i][j]=c[i-1][j-1]+1;
    else
      c[i][j]=max(c[i-1][j],c[i][j-1]);               
  }               
}

//aflare sir
l=c[m][n];
j=l;
sir=(int*)malloc(l*sizeof(int));

while(l>0){
  if(a[m-1]==b[n-1]){ 
     sir[--l]=a[m-1];
     m--;
     n--;
  }else{
     if(c[m-1][n]>c[m][n-1])
        m--;
     else
        n--;
  }        
}

f=fopen("cmlsc.out","w");
fprintf(f,"%d\n", j);
for(i=0;i<j;i++){
   fprintf(f,"%d ", sir[i]);                    
}
fclose(f);
return 0;
}
