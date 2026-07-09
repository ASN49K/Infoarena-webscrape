#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int LCS[1025][1025];
int A[1025],B[1025];
stack<int>st;
void backtrack(int i,int j){
    if(i==0&&j==0)return ;
    if(A[j]==B[i]){
    st.push(A[j]);
    backtrack(i-1,j-1);
    }
   else if(LCS[i-1][j]>LCS[i][j-1]||j==0){
        backtrack(i-1,j);
    }
    else backtrack(i,j-1);
}

int main()
{
    int N,M;
    fi>>N>>M;
    for(int i=1;i<=N;i++){
        fi>>A[i];
    }
    for(int j=1;j<=M;j++){
        fi>>B[j];
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(A[j]==B[i]){
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);

        }

    }
    fo<<LCS[M][N]<<endl;
    backtrack(M,N);
    while(st.empty()==false){
        fo<<st.top()<<' ';
        st.pop();
    }


}
