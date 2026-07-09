#include <fstream>
#define DIM 1300
using namespace std;

ifstream fin ("cmlsc.in" );
ofstream fout("cmlsc.out");

int D[DIM][DIM], i, j, A[DIM], B[DIM], C[DIM], N, M;

void SetUp(){
    fin >> N >> M;
    for(i = 1; i <= N; i ++)
        fin >> A[i];
    for(j = 1; j <= M; j ++)
            fin >> B[j];
    return;
}

int MAX(int a, int b){
    if(a >= b) return a;
    if(a <= b) return b;
}

void Dinamic(){
    for(i = 1; i <= N; i ++)
        for(j = 1; j <= M; j ++){
            if(A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = MAX(D[i-1][j], D[i][j-1]);
        }
    return;
}

void Rebuild(){
    fout << D[N][M] << "\n";
    i = N; j = M;
    while(i != 0 && j != 0){
        if(A[i] == B[j]){
            C[D[i][j]] = A[i];
            i --;
            j --;
        }
        else{
            if(D[i-1][j] == D[i][j])
                i --;
            else
            if(D[i][j-1] == D[i][j])
                j --;
        }
    }
    for(i = 1; i <= D[N][M]; i ++)
        fout << C[i] << " ";
    return;
}

int main(){
    SetUp();
    Dinamic();
    Rebuild();
    return 0;
}
