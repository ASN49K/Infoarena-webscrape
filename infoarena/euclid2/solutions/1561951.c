#include <stdio.h>

int cmmdc(int a, int b) {
    if (!b)
        return a;
    else 
        return cmmdc(b, a % b);
}

int main()
{
    int T, x, y, i;
    FILE *f, *p;
    
    f = fopen("euclid2.in","r");
    p = fopen("euclid2.out","w");
    
    do {
        fscanf(f, "%d", &T);
    }
    while(T < 1 || T > 100000 );
        
    for(i = 0; i < T; i++) {
       do {
        fscanf(f, "%d %d", &x, &y);
       }
       while(x < 2 || y > 2000000000);
    
    fprintf(p, "%d\n", cmmdc(x,y));
    }

    fclose(f);
    fclose(p);
    
    return 0;
}

