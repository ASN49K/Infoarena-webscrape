#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int *a;
int *b;

void citire(){
    ifstream fin("cmlsc.in");
    fin>>n>>m;

    a = new int[n];
    for(int i = 0; i < n; ++i){
        fin>>a[i];
    }

    b = new int[m];
    for(int i = 0; i < m; ++i){
        fin>>b[i];
    }

    fin.close();
}

int *c;
int lungimeMaxima = 0;
int k = 0;

void backTrackSubsir(int i, int j, int **&matrice){
    if(i == 0 || j == 0){
        return;
    }else if(a[i-1] == b[j-1]){
        backTrackSubsir(i-1, j-1, matrice);
        c[k++] = a[i-1];
    }else{
        if(matrice[i-1][j] > matrice[i][j-1]){
            backTrackSubsir(i-1, j, matrice);
        }else{
            backTrackSubsir(i, j-1, matrice);
        }
    }
}

void cmlsc(){
    int **matrice = new int* [n+1];
    for(int i = 0; i <= n; ++i){
        matrice[i] = new int [m+1];
        for(int j = 0; j <= m; ++j){
            matrice[i][j] = 0;
        }
    }

    int lungime = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i-1] == b[j-1]){
                lungime = matrice[i-1][j-1];
                matrice[i][j] = ++lungime;
                if(lungime > lungimeMaxima){
                    lungimeMaxima = lungime;
                }
            }else{
                matrice[i][j] = max(matrice[i][j-1], matrice[i-1][j]);
            }
        }
    }

    c = new int [lungimeMaxima];
    backTrackSubsir(n, m, matrice);
}

int main()
{
    citire();
    cmlsc();
    ofstream fout("cmlsc.out");
    fout<<lungimeMaxima<<"\n";
    for(int i = 0; i < lungimeMaxima-1; ++i){
        fout<<c[i]<<" ";
    }
    fout<<c[lungimeMaxima-1]<<"\n";
    fout.close();
    return 0;
}
