

#include <stdio.h>
#include <stdlib.h>
int main () {
FILE *fin, *fout;
fin=fopen ("euclid2.in", "r");
fout=fopen ("euclid2.out", "w");
int a,b,r,i,n;
fscanf (fin,"%d", &n);
for (i=0; i<n;i++){
fscanf(fin,"%d",&a);
fscanf (fin, "%d",&b);
while (b){r=a%b; a=b; b=r;}
fprintf(fout, "%d\n", a);}
fclose(fin);
fclose(fout);
return 0;

}
