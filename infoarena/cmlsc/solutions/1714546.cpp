#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <iterator>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int maxim(const int &a, const int &b){
    return a > b ? a : b;
}

void afiseaza(const int &i, const int &j, const vector<int> &A, const vector<vector<int>> &sol){
    if(i!=0 && j!=0){
        if(sol[i][j] == 2)
            afiseaza(i-1,j,A,sol);
        else if(sol[i][j] == 1)
            afiseaza(i,j-1,A,sol);
        else if(sol[i][j] == 3){
            afiseaza(i-1,j-1,A,sol);
            out << A[i] << ' ';
        }
    }
}

int main(){

    int M, N;

    in >> M >> N;

    vector<int> A(M+1);
    vector<int> B(N+1);
    vector<vector<int>> sol(M+1, vector<int>(N+1));
    vector<vector<int>> matrice(M+1, vector<int>(N+1));

    for(int i = 1; i <= M; i++)
        in >> A[i];
    for(int i = 1; i <= N; i++)
        in >> B[i];

    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++){
            if(A[i] != B[j]){
                matrice[i][j] = maxim(matrice[i-1][j], matrice[i][j-1]);
                if(matrice[i][j] == matrice[i-1][j])
                    sol[i][j] = 2;
                else
                    sol[i][j] = 1;
            }
            else{
                matrice[i][j] = 1 + matrice[i-1][j-1];
                sol[i][j] = 3;
            }
        }
    out << matrice[M][N] << '\n';
    afiseaza(M, N, A, sol);


    return 0;
}
