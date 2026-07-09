#include <fstream>
using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int M, N;
    fin >> M >> N;
    int A[M + 1], B[N + 1], C[M + N + 2];
    int i;
    for(i = 1; i <= M; ++ i)
        fin >> A[i];
    for(i = 1; i <= N; ++ i)
        fin >> B[i];
    int x;
    int MAX = 0, j = 0;

    for(i = 1, x = 1; x <= M; ++ x){
            i = 1;
    while(i <= N){
        if(A[x] == B[i]){
            ++ j;
            C[j] = A[x];
            ++ MAX;
            ++ i;
        }else{
            ++ i;
        }
    }

    }
    fout << MAX << endl;
    for(i = 1; i <= j; ++ i)
        fout << C[i] << " ";

    return 0;
}
