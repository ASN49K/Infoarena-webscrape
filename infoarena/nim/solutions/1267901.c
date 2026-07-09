#include <stdio.h>
int main(){
    int T, t, n, a, xorsum, i;
    FILE *fin, *fout;
    fin=fopen("nim.in", "r");
    fout=fopen("nim.out", "w");
    fscanf(fin, "%d", &T);
    for(t=0; t<T; t++){
        fscanf(fin, "%d", &n);
        xorsum=0;
        for(i=0; i<n; i++){
            fscanf(fin, "%d", &a);
            xorsum^=a;
        }
        if(xorsum==0){
            fprintf(fout, "NU\n");
        }else{
            fprintf(fout, "DA\n");
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
