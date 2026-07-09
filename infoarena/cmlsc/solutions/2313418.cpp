#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1024;
int M,N, A[NMAX], B[NMAX], C[NMAX][NMAX], D[NMAX][NMAX];

void Read(){
    fin >> M >> N;
    for(int i = 1; i <= M; i++){
        fin >> A[i];
    }
    for(int i = 1; i <= N; i++){
        fin >> B[i];
    }
}

void LCS_Length() {
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(A[i] == B[j]){
                C[i][j] = C[i-1][j-1] + 1;
                D[i][j] = 1;
            }
            else if(C[i-1][j] >= C[i][j-1]){
                C[i][j] = C[i-1][j];
            }
            else{
                C[i][j] = C[i][j-1];
            }
        }
    }
    fout << C[M][N] << endl;
}

void Print_LCS(){
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(D[i][j] == 1)
                fout << A[i] << " ";
        }
    }
}

int main()
{
    Read();
    LCS_Length();
    Print_LCS();
}
