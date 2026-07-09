#include<stdio.h>

int cmmdc(int a, int b){
    int tmp;
    while(a!=0 && b!=0){
        a = a%b;
        tmp = a;
        a = b; 
        b = tmp;
        printf("%d %d\n", a,b);
    }
    return a;
}

void solve(){
    int i, a,b,c,n;
    FILE *f = fopen("euclid2.in", "r");
    FILE *g = fopen("euclid2.out", "w");

    fscanf(f, "%d", &n);
    for(i = 0; i<n ;i++){
        fscanf(f, "%d %d", &a, &b);
        c = cmmdc(a, b);
        fprintf(g, "%d\n", c);
    }

    fclose(f);
    fclose(g);
}
int main(){
    solve();
    return 0;
}
