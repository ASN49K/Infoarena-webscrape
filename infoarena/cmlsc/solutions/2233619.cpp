
//Arhiva Educationala - 001. Cel mai lung subsir comun

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in("cmlsc.in");
    std::ofstream out("cmlsc.out");

    int M; //numarul de elemente ale vect. A
    in >> M;
    int N; //numarul de elemente ale vect. B
    in >> N;

    //citirea elementelor vect. A
    int A[M];
    for(int i = 0; i < M; ++i){
        in >> A[i];
    }

    //citirea elementelor vect. B
    int B[N];
    for(int i = 0; i < N; ++i){
        in >> B[i];
    }

    //Voi utiliza programarea dinamica, metoda tabulara
    int DP_table[M + 2][N + 2] = {};
    int lcs[std::max(M, N)];
    int lung_max = 0;
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= N; ++j){
            if(A[i - 1] == B[j - 1]){
                DP_table[i][j] = DP_table[i - 1][j - 1] + 1;
                if(lung_max < DP_table[i][j]){
                    lcs[DP_table[i][j]] = A[i - 1];
                    ++lung_max;
                }
            }
            else{
                DP_table[i][j] = std::max(DP_table[i][j - 1], DP_table[i - 1][j]);
            }
        }
    }

    out << DP_table[M][N] << '\n';
    for(int i = 1; i <= DP_table[M][N]; ++i){
        out << lcs[i] << ' ';
    }
    /*for(int i = 0; i <= M; ++i){
        for(int j = 0; j <= N; ++j){
            std::cout << DP_table[i][j] << ' ';
        }
        std::cout << '\n';
    }
    */
    return 0;
}
