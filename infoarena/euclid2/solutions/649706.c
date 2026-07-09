#include<stdio.h>
int alg_euclid(int a,int b){
    if(!b)
    return a;
    return algeuclid(a,a%b);
                            }
    
int main()
  {
        int a,b,n,i;
        
       FILE *f=fopen("euclid2.in","r");
       
        FILE *g=fopen("euclid2.out","w");
        
         fscanf(f,"%d",&n);
         
       for (i=0;i<=n-1;i++){
        
      fscanf(f,"%d %d",&a,&b);
      
      fprintf(g,"%d \n",alg_euclid(a,b));
      
                       }
         fclose(f);
         
         fclose(g);
         
         return 0;
     }          
