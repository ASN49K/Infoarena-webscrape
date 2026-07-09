#include <iostream>
#include <fstream>

using namespace std;

FILE * fin = fopen("euclid2.in", "r");
FILE * fout = fopen("euclid2.out", "w");

int cmmdc(int a, int b){
    int *_min, *_max;

    do{
        _min = (a < b ? &a : &b);
        _max = (a >= b ? &a : &b);
        *_max -= *_min;
    }while(a != 0 && b != 0);

    return (*_max == 0 ? *_min : *_max);
}

int main()
{
    int t, a, b;
    string line;

    fscanf(fin, "%d", &t);

    for(int i = 0; i < t; i++){
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d\n", cmmdc(a, b));
    }

    fclose(fin);
    fclose(fout);
    return 0;
}

