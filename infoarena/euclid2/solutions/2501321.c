#include <stdio.h>
#include <stdlib.h>

int euclid(int a, int b) {
        while(a!=b){
            if(a>b)
                a-=b;
            else b-=a;
        }
        return a;
}

int main()
{
    int n;
int a,b;
FILE*f= fopen("euclid2.in", "r");
fscanf(f,"%d",&n);
FILE *g=fopen("euclid2.out", "w");
while(n) {
    fscanf(f,"%d %d", &a, &b);
    fprintf(g,"%d\n", euclid(a,b));
    n-=1;
}
}
