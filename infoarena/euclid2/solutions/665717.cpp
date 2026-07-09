#include <stdio.h>

long cmmdc ( long a, long b)
{
if (a == 0) return b;
else if (b == 0) return a;
else if (a>b) return cmmdc(b,a%b);
else return cmmdc(a,b%a);
}

int main()
{
    long a,b;
    FILE *f;
    FILE *g;
    int t;	
    f = fopen("euclid2.in","r");
    g = fopen("euclid2.out","w");
    fscanf(f,"%d",&t);
    for (int i=1;i<=t;i++){
	fscanf(f,"%ld %ld",&a,&b);
    	fprintf(g,"%ld\n",cmmdc(a,b));
    }
    fclose(g);
    fclose(f);
    return 0;
}