#include<stdio.h>
 int n , a, b,i,aux ;
  int main()
{
  
  FILE * f,*g;
  f=fopen("euclid2.in","r");
  g=fopen("euclid2.out","w");
fscanf(f,"%d",&n);
for(i=1;i<=n;i++)
{
                 
                 fscanf(f,"%d%d",&a,&b);
/*if(a<b)
{
        aux=a%b;
        a=b;
        b=aux;
        }
        */
        while (aux=a%b)
        {
        a=b;
        b=aux;
        
        
        
        }
fprintf(g,"%d\n",b);
        }
 fclose(f);
 fclose(g);       

return 0;

}

