//cmlsc
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>


int main(){
int *a, *b, *aux,n, m, i,j,k=0;
FILE *f;
f=fopen("cmlsc.in","r");
fscanf(f,"%d",&m);
fscanf(f,"%d",&n);

a=(int *)malloc(m*sizeof(int));
b=(int *)malloc(n*sizeof(int));

for(i=0;i<m;i++)
fscanf(f,"%d",a+i);
for(i=0;i<n;i++)
fscanf(f,"%d",b+i);
fclose(f);

if(m<n){
  aux=(int *)malloc(m*sizeof(int));
  for(i=0;i<m;i++){
     for(j=0;j<n;j++){
        if(a[i]==b[j]) {
           aux[k++]=a[i];
           break;      
        }              
     }               
  }      
}else{
  aux=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
     for(j=0;j<m;j++){
        if(b[i]==a[j]) {
           aux[k++]=b[i];
           break;      
        }              
     }               
  }          
}

f=fopen("cmlsc.out","w");
fprintf(f,"%d\n", k);
for(i=0;i<k;i++)
  fprintf(f,"%d ", aux[i]);
fclose(f);
return 0;
   
}
