
//Arhiva Educationala - 001. Cel mai lung subsir comun

#include <iostream>
#include <fstream>
#include <vector>

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
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= N; ++j){
            if(A[i - 1] == B[j - 1]){
                DP_table[i][j] = DP_table[i - 1][j - 1] + 1;
            }
            else{
                DP_table[i][j] = std::max(DP_table[i][j - 1], DP_table[i - 1][j]);
            }
        }
    }

    out << DP_table[M][N] << '\n';

    int i = M;
    int j = N;

    std::vector<int> lcs;
    while(i > 0 && j > 0){
        if(A[i - 1] == B[j - 1]){
            lcs.push_back(A[i - 1]);
        }

        if(DP_table[i][j - 1] < DP_table[i - 1][j]){
            --i;
        }
        else{
            --j;
        }
    }

    for(int i = lcs.size() - 1; i >= 0; --i){
        out << lcs[i] << ' ';
    }
    return 0;
}
