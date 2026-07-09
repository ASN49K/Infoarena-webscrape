#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.out");
ofstream fout("cmlsc.out");

int D[1025][1025];
stack<int> rez;

int maxi(int a, int b){
    if( a > b ) return a;
    return b;
}

int main(){
    int A[1025], B[1025], M, N;
    fin >> M >> N ;
    for(int i=1; i<=M; i++)
        fin >> A[i];
    for(int i=1; i<=N; i++)
        fin >> B[i];
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(A[i] == B[j]) D[i][j] = D[i-1][j-1] + 1;
            else D[i][j] = maxi(D[i-1][j], D[i][j-1]);
        }
    }
    fout << D[M][N] << endl;
    for(int i = M, j= N; i && j;){
        if(A[i] == B[j] ) { rez.push(A[i]); i--, j--; } 
        else if( D[i-1][j] >= D[i][j-1] ) i--;
        else j --;
    }
    while(!rez.empty()){
        fout << rez.top() << ' ' ;
        rez.pop();
    }
    return 0;
}