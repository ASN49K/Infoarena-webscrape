#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX = 1024;
unsigned int AB[MAX][MAX], k = 0, C[MAX];
unsigned int A[MAX], B[MAX];

void construire(int i, int j){
    if(i>=1 && j>=1){
        construire(i-1, j-1);
        k++;
        C[k] = A[i];
    }
    else{
        if(AB[i-1][j] > AB[i][j-1]) construire(i-1, j);
        else construire(i, j-1);
    }
}

int main(){

    unsigned int M,N;
    unsigned int maxSubsir;
    fin>>M>>N;

    for(int i = 1; i<=M; i++) cin>>A[i];
    for(int i = 1; i<=N; i++) cin>>B[i];

    for(int i=1; i<=M; i++) AB[i][0] = 0;
    for(int j=1; j<=N; j++) AB[0][j] = 0;

    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(A[i] == B[j]) AB[i][j] = AB[i-1][j-1] + 1;
            else{
                if(AB[i-1][j] > AB[i][j-1]) AB[i][j] = AB[i-1][j];
                else AB[i][j] = AB[i][j-1];
            }
        }
    }

    maxSubsir = AB[M][N];
    construire(M, N);

    fout<<maxSubsir<<"\n";
    for(int i=1;i<=k;i++){
        fout<<C[i]<<" ";
    }

    fout.close();
    return 0;
}
