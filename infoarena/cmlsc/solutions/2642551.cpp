#include <iostream>
#include <fstream>
#include <vector>

#define MAX(a,b) a>b?a:b

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int M, N, i, j;
int V1[1050], V2[1050];
int Matrix[1050][1050];

int main() {
    fin >> M >> N;

    for (i = 1; i <= M; i++)
        fin >> V1[i];

    for (i = 1; i <= N; i++)
        fin >> V2[i];

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            if (V1[i] == V2[j])
                Matrix[i][j] = Matrix[i - 1][j - 1] + 1;
            else
                Matrix[i][j] = MAX(Matrix[i - 1][j], Matrix[i][j - 1]);
        }
    }

    fout << Matrix[M][N] << "\n";

    for (i = 1; i <=M; i++) {
        for (j = 1; j <=N; j++) {
            if (Matrix[i][j] > (MAX(Matrix[i - 1][j], Matrix[i][j - 1]))) {
                fout << V1[i] << " ";
            }
        }
    }
    
        
    return 0;
}