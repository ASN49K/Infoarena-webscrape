#include <iostream>
#include <fstream>
#include <vector>
#define MAX(a,b) (((a)>=(b))?(a):(b))
using namespace std;


int main(){
    ifstream ifs("cmlsc.in");
    ofstream ofs("cmlsc.out");

    int M,N; ifs>>M>>N;

    vector<int> A(M+1,0),B(N+1,0);

    for(int i=1;i<=M;i++) ifs>>A[i];
    for(int i=1;i<=N;i++) ifs>>B[i];

    vector<vector<int> > m(N+1,vector<int>(M+1,0));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(A[j]==B[i])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=MAX(m[i][j-1],m[i-1][j]);
        }
    }


    int len=m[N][M];
    vector<int> ans(len);
    ofs<<len<<"\n";

    int i=N,j=M;
    while((i!=0)&&(j!=0)){
        if(A[j]!=B[i]){
            if(m[i][j-1]>m[i-1][j])
                j--;
            else
                i--;
        }
        else{
            ans[--len]=A[j--]; i--;
        }
    }

    for(int i=0;i<m[N][M];i++) ofs<<ans[i]<<" ";
}
