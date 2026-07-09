#include <stdio.h>
#include <stdlib.h>
int main () {
FILE *fin, *fout;
fin=fopen ("euclid2.in", "r");
fout=fopen ("euclid2.out", "w");
int a,b,r;
fscanf(fin,"%d",&a);
fscanf (fin, "%d",&b);
while (b){r=a%b; a=b; b=r;}
fprintf(fout, "%d", a);
fclose(fin);
fclose(fout);
return 0;

}