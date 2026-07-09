#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
  
int rs[1025],r,A[1025],B[1025],D[1025][1025],M,N,i,j;
int main(){
    fin >> N >> M;
    for(i = 1;i<=N;i++){
        fin >> A[i];
    }
    for(i = 1;i<=M;i++){
        fin >> B[i];
    }
     
    for(i = 1;i<=N;i++)
        for(j = 1;j<=M;j++){
            D[i][j] = max(D[i-1][j],D[i][j-1]);
            if(A[i] == B[j]) D[i][j] = min(D[i-1][j],D[i][j-1]) +1;
        }
    fout << D[N][M]<<'\n';
    i= N;
    j= M;
    while(r < D[N][M]){
        for(;D[i-1][j]!=D[i][j-1];--j);
        if(D[i-1][j] < D[i][j]) rs[++r] = A[i];
        i--;
    }
    for(i = r;i>0;i--) fout << rs[i]<<endl;
    return 0;
}
