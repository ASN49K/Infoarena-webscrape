#include <stdio.h>
02. 
03.int main()
04.{   FILE *f=fopen("euclid2.in","r");
05.int N;
06.fscanf(f,"%d",&N);
07.int a,b;
08.FILE *g=fopen("euclid2.out","w");
09.for (;N;--N)
10.{   fscanf(f,"%d %d",&a,&b);
11.int m;
12.while (b!=0)
13.{   m=a%b;
14.a=b;
15.b=m;
16.}
17.fprintf(g,"%d\n",a);
18.}
19.fclose(g);
20.}