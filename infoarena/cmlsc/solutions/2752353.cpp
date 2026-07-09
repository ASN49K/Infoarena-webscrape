#include <iostream>
#include <fstream>

#define NMAX (1024+7)

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M, N, A[NMAX], B[NMAX], cmlsc[NMAX][NMAX];

void afiseaza(int x, int y) {
    int newX, newY;
    if(!cmlsc[x][y]) return ;
    if(cmlsc[x-1][y-1] == cmlsc[x][y]) afiseaza(x-1, y-1);
    else if(cmlsc[x-1][y] == cmlsc[x][y]) afiseaza(x-1, y);
    else if(cmlsc[x][y-1] == cmlsc[x][y]) afiseaza(x, y-1);
    else {
        afiseaza(x-1, y-1);
        fout << A[x] << ' ';
    }
}

int main() {
    fin >> M >> N;
    for(int i = 1; i<= M; ++i) fin >> A[i];
    for(int i = 1; i<= N; ++i) fin >> B[i];

    /// Construirea dinamicii
    for(int i = 1; i<= M; ++i) {
        for(int j = 1; j<= N; ++j) {
            cmlsc[i][j] = max(cmlsc[i][j-1], cmlsc[i-1][j]);
            if(A[i] == B[j]) cmlsc[i][j] = max(cmlsc[i][j], cmlsc[i-1][j-1] + 1);
        }
    }

    fout << cmlsc[M][N] << "\n";

    /// Reconstructia drumului
    afiseaza(M, N);



    fin.close();
    fout.close();

    return 0;
}
