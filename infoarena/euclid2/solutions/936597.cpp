#include<stdio.h>
#include<stdlib.h>
using namespace std;
long a,b;
int t;

long cmmdc(long a, long b)
{long c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
	FILE * f, *g;
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");
    fscanf(f,"%d", &t);
    for(int i = 0; i < t; i++) {
	  fscanf(f,"%d %d", &a, &b);   
	  fprintf(g,"%d \n", cmmdc(a,b));
    }
    fclose(f);
    fclose(g);
 return 0;
}
