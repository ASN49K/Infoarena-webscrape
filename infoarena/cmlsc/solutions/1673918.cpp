#include <iostream>
#include <cstdio>

using namespace std;

short int v1[1025];
short int v2[1025];
short int d[1025][1025];

void citesteVector(short int v[], short int n, FILE *f);
void refa(int x, int y, FILE *f);
short int maxim(short int a, short int b);

int main()
{
    FILE *fin = fopen("cmlsc.in", "r");
    FILE *fout = fopen("cmlsc.out", "w");

    short int n, m;

    fscanf(fin, "%hd%hd", &n, &m);
    citesteVector(v1, n, fin);
    citesteVector(v2, m, fin);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(v1[i] == v2[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = maxim(d[i - 1][j], d[i][j - 1]);
        }
    }

    fprintf(fout, "%hd\n", d[n][m]);
    refa(n, m, fout);

    return 0;
}

void refa(int x, int y, FILE *f){
    if(x == 0 || y == 0)
        return;

    if(v1[x] == v2[y]){
        refa(x - 1, y - 1, f);
        fprintf(f, "%hd ", v1[x]);
    }
    else if(d[x - 1][y] > d[x][y - 1]){
        refa(x - 1, y, f);
    }
    else{
        refa(x, y - 1, f);
    }
}

void citesteVector(short int v[], short int n, FILE *f){
    for(int i = 1; i <= n; ++i)
        fscanf(f, "%hd", &v[i]);
}

short int maxim(short int a, short int b){
    return (a >= b) ? a : b;
}
