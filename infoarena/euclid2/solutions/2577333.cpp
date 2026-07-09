#include<cstdio>
int q, a, b, c, r;
FILE *f, *g;
int main(){
    f = fopen("euclid2.in","r");
    g = fopen("euclid2.out","w");
    fscanf(f,"%d",&q);
    while(q--){
        fscanf(f,"%d%d",&a,&b);
        r = a % b;
        while(r){
            a = b;
            b = r;
            r = a % b;
        }
        fprintf(g,"%d\n",b);
    }

    fclose(f);
    fclose(g);
    return 0;
}
