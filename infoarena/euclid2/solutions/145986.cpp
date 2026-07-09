#include<stdio.h>
FILE*fin=fopen("euclid2.in","r");
FILE*fout=fopen("euclid2.out","w");
int main()
{
  int a,b;
  fscanf(fin,"%d%d",&a,&b);
  while(a!=b)
    if(a<b) b-=a;
    else a-=b;
  fprintf(fout,"%d",a);
  fclose(fin);
  fclose(fout);
  return 0;
}