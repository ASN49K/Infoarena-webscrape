#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1024;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int s1[NMAX], s2[NMAX], vec[NMAX];
int N1, N2, Max;

int read(){
    fin >> N1 >> N2;
    for(int i = 0; i < N1; i++)
        fin >> s1[i];
    for(int i = 0; i < N2; i++)
        fin >> s2[i];
}

int LSC(int x, int y, int Max){
    if(y < 0){
        return LSC(x - Max - 1, N2 - Max - 1, Max);
    } else {
        if(x < 0){
            return Max;
        } else {
            if(s2[y] == 0){
                return LSC(x, y - 1, Max);
            } else {
                if(s1[x] == s2[y]){
                    vec[Max] = s1[x];
                    s2[y] = 0;
                    return LSC(x - 1, y - 1, Max + 1);
                } else {
                    return LSC(x, y - 1, Max);
                }
            }
        }
    }
}

int afisare(int v[NMAX], int N){
    for(int i = 0; i < N; i++)
        fout << v[i] << ' ';
}

int main(){

    read();
    Max = LSC(N1 - 1, N2 - 1, 0);
    fout << Max << endl;
    reverse(vec, vec+Max);
    afisare(vec, Max);

    return 0;
}
