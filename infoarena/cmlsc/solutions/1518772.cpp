#include <iostream>
#include <fstream>

#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define NMax 1024

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main(int argc, char *argv[]){
    int i, j;

    //Citire
    fin >> M >> N;
    FOR (i, 1, M)
        fin >> A[i];
    FOR (i, 1, N)
        fin >> B[i];

    //Construire matrice
    FOR (i, 1, M)
        FOR (j, 1, N)
            if (A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = maxim (D[i-1][j], D[i][j-1]);

    //Construire subsir
    for (i = M, j = N; i != 0; ){
        if (A[i] == B[j]){
            sir[++bst] = A[i];
            i--;
            j--;
        } // if()
        else if (D[i-1][j] < D[i][j-1])
                j--;
        else
            i--;
    } // for()

    //Afisare
    fout << bst << "\n";
    for (int i = bst; i != 0; i--)
        fout << sir[i] << " ";

    return 0;
} //main()
