#include <stdio.h>
#include <stdlib.h>

using namespace std;

int cmmdc(int a, int b){
  int r=a%b;
  while(r!=0){
    a=b;
    b=r;
    r=a%b;
  }
  return b;
}

int main()
{
    FILE *fin, *fout;
    int n,a,b;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&n);
    for(n;n>0;n--){
      fscanf(fin,"%d%d",&a,&b);
      fprintf(fout,"%d\n",cmmdc(a,b));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
