#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int N, M, A[1024], B[1024], D[1024][1024], sl[1024], l;
int main(){
    int i, j;
    fin >> N >> M;
    for(i=1; i <= N; i++) fin >> A[i];
    for(j=1; j <= M; j++) fin >> B[j];
    for(i=1; i <= N; i++)
        for(j=1; j <= M; j++)
            if(A[i] == B[j]) D[i][j] = 1 + D[i-1][j-1];
            else D[i][j] = max(D[i-1][j], D[i][j-1]);
    i = N;
    j = M;
    while(i > 0 && j > 0){
        if(A[i] == B[j]){
            sl[++l] = A[i];
            i--;
            j--;
        }
        else if(D[i-1][j] < D[i][j-1])
            j--;
        else i--;
    }
    fout << l << "\n";
    for(i = l; i >= 1; i--) fout << sl[i] << " ";
}