#include <stdio.h>

int main()

{
 FILE *fp;
 int a,b;
 fp=fopen("euclid2.in","r");
 fscanf(fp,"%d\n%d",&a,&b);
 fclose(fp);
fp=fopen("euclid2.out","w");
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
     putw(a,fp);
    fclose(fp);
 return 0;
 }

