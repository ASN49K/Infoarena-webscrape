#include <iostream>
#include <fstream>

using namespace std;

FILE * fin = fopen("euclid2.in", "r");
FILE * fout = fopen("euclid2.out", "w");

int cmmdc(int a, int b){
    int c = 0, sol = 1, m = (a < b ? a : b);
    do{
        c++;
        if(a % c == 0 && b % c == 0){
            sol = c;
        }

    }while(c < m);

    return sol;
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

