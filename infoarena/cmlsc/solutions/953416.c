#include<stdio.h>
int na, nb, a[1025], b[1025], d[1025][1025];

int max(int a, int b, int c){
    if(a>=b && a>=c) return a;
    if(b>=c && b>=a) return b;
    return c;
}

void read(){
    int i;
    FILE *f = fopen("cmlsc.in", "r");

    fscanf(f, "%d %d", &na, &nb);
    for(i =0; i<na; i++)
        fscanf(f," %d", a+i);

    for(i=0; i<nb; i++)
        fscanf(f, "%d", b+i);

    fclose(f);
}
int main(){
    read();

    int i,j;
    for(i=1; i<=na; i++)
        for(j=1; j<=nb; j++)
            if(a[i-1] == b[j-1])
                d[i][j] = max(d[i-1][j] , d[i][j-1], 1+d[i-1][j-1]);
            else
                d[i][j] = max(d[i-1][j], d[i][j-1], d[i][j-1]);

    i = na; j=nb;
    int n = d[na][nb]
      , rezultat[n];

    while(n){
       if(i>0 && d[i][j] == d[i-1][j]) { i--; continue; }
       if(j>0 && d[i][j] == d[i][j-1]) { j--; continue; }
       rezultat[--n] = a[i-1];
       i--; j--;
    }

    FILE *g = fopen("cmlsc.out", "w");

    fprintf(g, "%d\n", d[na][nb]);
    for(i=0; i<d[na][nb]; i++)
        fprintf(g, "%d ", rezultat[i]);

    fclose(g);

    return 0;
}
