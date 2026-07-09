#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMax = 1024;
int D[NMax][NMax], A[NMax], B[NMax], sir[NMax], bst;

int main()
{
    int N, M;
    f >> M >> N;
    for(int i = 1; i <= M; i++){
        f >> A[i];
    }
    for(int i = 1; i <= N; i++){
        f >> B[i];
    }
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(A[i] == B[j]){
                D[i][j] = 1 + D[i-1][j-1];
            } else {
                D[i][j] = ((D[i][j - 1] > D[i - 1][j]) ? D[i][j - 1] : D[i - 1][j]);
            }
        }
    }
    int i = M;
    int j = N;
    while(i != 0 && j != 0){
        if(A[i] == B[j]){
            sir[++bst] = A[i];
            i--;
            j--;
        } else {
            if(D[i][j - 1] < D[i - 1][j]){
                i--;
            } else {
                j--;
            }
        }
    }
    g << bst << "\n";
    for(int i = bst; i != 0 ; i--){
        g << sir[i] << " ";
    }
    return 0;
}
