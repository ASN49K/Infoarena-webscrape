#include <bits/stdc++.h>

using namespace std;
using fun = int;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMAX = 1025;
int a[NMAX], b[NMAX], sir[NMAX], sol[NMAX];
int bst, m, n;

int subsir(int nr){
    int j = 0;
    for(int i = 0; i < nr && j < n; i++)
        for(; j < n && b[j] != sir[i]; j++);

    return j < n;
}

void backt(int nivel, int len){
    int i;

    if(nivel == m){
        if(subsir(len)){
            if(len > bst){
                bst = len;
                for(i = 0; i < bst; i++)
                    sol[i] = sir[i];
            }
        }

        return;
    }

    backt(nivel+1, len);
    sir[len] = a[nivel];
    backt(nivel+1, len+1);
}

fun main(){
    f >> m >> n;
    for(int i = 0; i < m; i++)
        f >> a[i];

    for(int i = 0; i < n; i++)
        f >> b[i];

    backt(0, 0);

    g << bst << '\n';
    for(int i = 0; i < bst; i++)
        g << sol[i] << ' ';
}
