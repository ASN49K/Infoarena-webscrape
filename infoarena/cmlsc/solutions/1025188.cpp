#include <iostream>
#include <fstream>
#define NMAX 1024

using namespace std;

ifstream f("lcs.in");
ofstream g("lcs.out");

int retval,N,M, A[NMAX],B[NMAX],DP[NMAX][NMAX], subsir[NMAX];

int maxim(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}
void Read(){
    f>>M>>N;
    for (int i = 1; i <= M; ++i) {
        f>>A[i];
    }
    for (int i = 1;  i <= N; ++i) {
        f>>B[i];
    }
}
void Solve(){
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j<= N; ++j) {
            if (A[i] == B[j]) {
                DP[i][j] = 1 + DP[i-1][j-1];
            }else{
                DP[i][j] = maxim(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    int i, j;
    for ( i = M, j = N; i; ) {
        if (A[i]==B[j]) {
            subsir[++retval] = A[i];
            --i; --j;
        }
        else if (DP[i-1][j] < DP[i][j-1]){
            --j;
        }else{
            --i;
        }
    }
}

void Print(){
    g<<retval<<"\n";
    for (int i = retval; i; i--) {
        g<<subsir[i]<<" ";
    }
}

int main()
{
    Read();
    Solve();
    Print();
    return 0;
}

