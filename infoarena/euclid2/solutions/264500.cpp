#include <stdio.h>
int mdc (int a, int b){
if (!b) return a;
else return mdc(b,a%b);}

int main {
int a, b, i, T;
FILE *fi, *fo;
fi=fopen ("euclid2.in", "r");
fo=fopen ("euclid2.out", "w");
fscanf (fi, "%d", &T);
for (i=1;i<=T;i++){
fscanf (fi, "%d %d", &a, &b);
a=mdc (a,b);
fprintf (fo, "%d\n", a);
}
fclose (fi);
flose (fo);
return 0;}