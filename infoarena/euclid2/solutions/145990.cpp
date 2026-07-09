#include<stdio.h>
FILE*fin=fopen("euclid2.in","r");
FILE*fout=fopen("euclid2.out","w");
int main()
{
  int a,b,aux;
  fscanf(fin,"%d%d",&a,&b);
  if(b>a)
    a^=b^=a^=b;
  while(b!=0)
  {
    aux=a;
    a=b;
    b=aux%b;
  }  
  fprintf(fout,"%d",a);
  fclose(fin);
  fclose(fout);
  return 0;
}