#include <stdio.h>
#include <stdlib.h>

FILE *fisierInput, *fisierOutput;

int Euclid(int a, int b)
{
  if(a==0) return b;
  return Euclid(b%a,a);
}

int main()
{
    fisierInput=fopen("euclid2.in","r");
    fisierOutput=fopen("euclid2.out","w");
    int n, i, x, y;
    fscanf(fisierInput, "%d",&n);
    for(i=1;i<=n;i++)
    {
      fscanf(fisierInput, "%d %d", &x, &y);
      fprintf(fisierOutput,"%d\n", Euclid(x,y));
    }
    return 0;
}
