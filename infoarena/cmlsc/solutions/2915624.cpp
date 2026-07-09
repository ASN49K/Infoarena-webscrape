#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define DIM 1027

int n, m;
int CMS[DIM][DIM], x[DIM], y[DIM];
string rasp = "a";

void gen();
void printCMS();
int backtrack();
int current(int i, int j);

int main(){

    fin >> n >> m;

    for(int i = 1; i <= n; i++){
        fin >> x[i];
    }

    for(int j = 1; j <= m; j++){
        fin >> y[j];
    }

    gen();
    backtrack();

    fout << CMS[n][m] << '\n';

    for(int i = rasp.size() - 1; i > 0; i--){
        fout << rasp[i] << ' ';
    }

    return 0;
}

void gen(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            CMS[i][j] = current(i, j);
        }
    }
}

void printCMS(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            fout << CMS[i][j] << ' ';
        }

        fout << '\n';
    }
}

int backtrack(){    //int backtrack si nu void backtrack pt a da end la functie cu comanda return
    int i = n, j = m;

    while(CMS[i][j] > 0){
        while(i > 0 && j > 0 && x[i] == y[j]){
            rasp = rasp + (char)(x[i] + '0');
            i--;
            j--;
        }

        if(CMS[i][j] == 0){
            return 0;   // ca sa iasa din functie
        }

        if(CMS[i-1][j] >= CMS[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    return 0;
}

int current(int i, int j){
    if(x[i] == y[j]){
        int cont = 0;

        while(i >= 1 && j >= 1 && x[i] == y[j]){
            i--;
            j--;
            cont++;
        }

        return (cont + CMS[i][j]);

    }else{
        return max(CMS[i-1][j], CMS[i][j-1]);
    }
}
