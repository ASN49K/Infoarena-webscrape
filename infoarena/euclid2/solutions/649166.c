#include <stdio.h>
int a,b,n;
int euclid (int a,int b)
         {  
    if (!b) return a;
         return euclid(b, a%b);
         }
int main(void){
  FILE *fin,*fout;  
    fin=fopen("euclid2.in", "r+");
    fout=fopen("euclid2.out", "w+");
     fscanf(fin,"%d", &n);
     for(;n;--n)
     {
       fscanf(fin,"%d %d",&a , &b);
       fprintf(fout,"%d\n",euclid(a, b));
     }
     fclose(fin);
     fclose(fout);
       return 0;
            }
       
