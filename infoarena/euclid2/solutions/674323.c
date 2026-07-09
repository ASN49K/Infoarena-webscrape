#include<stdio.h>
//#include<fstream.h>


int** aloc_memorie(int t, int** a) {
    int i;

    a = (int**)malloc(t*sizeof(int*));
    for(i=0; i<t; i++){
        a[i] = (int*)malloc(2*sizeof(int));
    }
    return a;
}

int** read(int *t, int** a) {
    FILE* in;
    in = fopen("euclid2.in", "r");
    int i;

    if(in == NULL) {
        printf("Nu a fost gasit fisierul!");
        fclose(in);
        return;
    }

    fscanf(in, "%d", t);
    a = aloc_memorie(*t, a);
    for (i=0; i<*t; i++) {
        fscanf(in, "%d%d", &a[i][0], &a[i][1]);
    }

    fclose(in);
    return a;
}

int cmmdc(int a, int b) {
    if (a==0)
        return b;
    if (b==0)
        return a;

    while(a!=b) {
        if(a>b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    return a;
}

int main() {
    int **a;
    int t, i, c;

    a = read(&t,a);

    FILE* out;
    out = fopen ("euclid2.out", "w");

    for (i=0; i<t; i++) {
        c = cmmdc(a[i][0], a[i][1]);
        fprintf(out, "%d \n", c);
    }
    fclose(out);
    return 0;
}
