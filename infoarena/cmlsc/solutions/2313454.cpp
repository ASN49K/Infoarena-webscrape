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
                //D[i][j] = 1;
            }
            else if(C[i-1][j] >= C[i][j-1]){
                C[i][j] = C[i-1][j];
            }
            else{
                C[i][j] = C[i][j-1];
            }
        }
    }
    fout << C[M][N] << "\n";
}

void Print_LCS(){
    int aux[1024];
    int i=M,j=N, l = C[M][N];
    while(i && j){
        if(A[i]==B[j]){
           aux[--l]= A[i];
           i--;
           j--;
           }
        else{
           if(C[i-1][j]<C[i][j-1])--j;
           else --i;
        }
    }
    for(i=0;i<C[M][N];i++)
        fout<<aux[i]<<" ";
}

int main()
{
    Read();
    LCS_Length();
    Print_LCS();
}
