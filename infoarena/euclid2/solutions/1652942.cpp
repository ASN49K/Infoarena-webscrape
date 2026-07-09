#include <iostream>
#include <fstream>

using namespace std;

FILE * fin = fopen("euclid2.in", "r");
FILE * fout = fopen("euclid2.out", "w");

int cmmdc(int a, int b){
    if(!b)
        return a;
    return cmmdc(b, a%b);
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

