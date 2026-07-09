#include <stdio.h>
#include <stdlib.h>

int main() {



int x;
FILE *f,*g;
char s[10],s2[20],s3[256];
f =fopen  ("numar.in","r");
g =fopen ("numar.out","w");
fscanf (f,"%s  %[a-z]", s, s2);
x=atoi( s);
sprintf (s3,"%d",x-10);
fprintf (g,"Int %d\n",x);
fprintf (g,"nr este %s\n",s3);
return 0;
}




