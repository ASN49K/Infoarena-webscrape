//euclid2
#include <stdio.h>

int euclid(int a,int b){
int r;
while(1){
   if(a<b){
     b=b%a;
     if(b==0){
        r=a;
        return r;      
     }
   }
   else{
     a=a%b;
     if(a==0){
        r=b;
        return r;      
     }
   }
}   
}

int main(){
FILE *f, *f1;
int n,i,a,b;
f=fopen("euclid2.in","r");
f1=fopen("euclid2.out","w");
fscanf(f,"%d", &n);

for(i=1;i<=n;i++){
 fscanf(f,"%d", &a);  
 fscanf(f,"%d", &b); 
 fprintf(f1,"%d\n", euclid(a,b));                
}  

return 0;
}
