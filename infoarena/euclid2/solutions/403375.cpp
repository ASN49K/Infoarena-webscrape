#include <stdio.h>
#include <conio.h>

int cm(int a,int b)
{
    int aux=0;
    while (b!=0)
          {
                aux=a;
                a=b;
                b=aux%b;
          }
          
    return a;
}

int main()
{
    int a,b,n;
    FILE *f,*g;
    f=fopen("euclid2.in","rt");
    g=fopen("euclid2.out","wt");
    fscanf(f,"%d",&n);
    printf("\n%i",n);
    while (n!=0)
    {
          fscanf(f,"%d",&a);
          fscanf(f,"%d",&b);
          printf("\n%d %d ",a,b);
          fprintf(g,"%d\n",cm(a,b));
          n--;
    }
    fclose(f);
    fclose(g);
    return 0;
}
