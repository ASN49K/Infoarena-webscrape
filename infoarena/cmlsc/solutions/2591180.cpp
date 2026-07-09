#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX = 1024;
unsigned int AB[MAX][MAX];
unsigned int A[MAX], B[MAX];

void afis(unsigned int i,unsigned int j){
    if(i>=1 && j>=1){
        if(A[i] == B[j]){
            afis(i-1, j-1);
            fout<<A[i]<<" ";
        }
        else{
            if(AB[i-1][j] > AB[i][j-1]) afis(i-1, j);
            else afis(i, j-1);
        }
    }
}

int main(){

    unsigned int M,N;
    unsigned int i, j;
    fin>>M>>N;

    for(i = 1; i<=M; i++) fin>>A[i];
    for(i = 1; i<=N; i++) fin>>B[i];

    for(i=1; i<=M; i++) AB[i][0] = 0;
    for(j=1; j<=N; j++) AB[0][j] = 0;

    for(i=1; i<=M; i++){
        for(j=1; j<=N; j++){
            if(A[i] == B[j]) AB[i][j] = AB[i-1][j-1] + 1;
            else{
                if(AB[i-1][j] > AB[i][j-1]) AB[i][j] = AB[i-1][j];
                else AB[i][j] = AB[i][j-1];
            }
        }
    }

    fout<<AB[M][N]<<"\n";
    afis(M,N);

    fout.close();
    return 0;
}
