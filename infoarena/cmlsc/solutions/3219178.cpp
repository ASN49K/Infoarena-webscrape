#include <bits/stdc++.h>
#include <iostream>
#include<fstream>
using namespace std;
stack<int> st;
int a[1001][1001];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int A[1001],B[1001];
    int i,j,N,M;
    fin>>M>>N;
    for(i=1;i<=M;i++){
        fin>>A[i];
    }
    for(j=1;j<=N;j++){
        fin>>B[j];
    }
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            if(A[i]==B[j]){
                a[i][j]=a[i-1][j-1]+1;
            }
            else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    fout<<a[M][N]<<endl;
    i=M;
    j=N;
    while(i>0 && j>0){
        if(A[i]==B[j]){
            st.push(A[i]);
            i--;j--;
        }
        else{
            if(a[i-1][j]<a[i][j-1]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    while(!st.empty()){
        fout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}