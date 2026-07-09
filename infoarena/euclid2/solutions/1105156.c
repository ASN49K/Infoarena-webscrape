#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,n,m,aux,a[100][100];
    FILE *in, *out;
    in = fopen("euclid2.in", "r");
    out = fopen("euclid2.out", "w");
 
    fscanf(in,"%d",&n); 
    
    for (m=0;m<n;m++)
      {  
      fscanf(in,"%d%d",&i,&j); 
      if (i<j)
      {
        aux=i%j;
        i=j;
        j=aux;
        }
         
        while (i%j)
        {
        aux=i%j;
        i=j;
        j=aux;
        }
        fprintf(out,"%d\n",j);
        
        }
        
    return 0;
}   
