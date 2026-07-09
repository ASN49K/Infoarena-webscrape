#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE*fi,*fo;
    fi=fopen("nim.in","r");
    fo=fopen("nim.out","w");

    int t;
    fscanf(fi,"%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        fscanf(fi,"%d", &n);
        int xor1 = 0;
        for(int j = 0; j < n; j++){
            int x;
            fscanf(fi,"%d", &x);
            xor1 = xor1 ^ x;
        }
        if(xor1)
            fprintf(fo,"DA\n");
        else
            fprintf(fo,"NU\n");
    }

    fclose(fi);
    fclose(fo);
    return 0;
}
