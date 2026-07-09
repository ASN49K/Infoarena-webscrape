#include <iostream>
#include <fstream>
using namespace std;

int cmlsc(int *A,int M,int *B,int N,int *S){
    int k=-1;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            if(A[i]==B[j]){
                k++;
                S[k]=A[i];
            }
    return ++k;
}

int main(){
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int M,N;
    fin>>M>>N;
    int* A = new int[M];
    int* B = new int[N];
    int* S = new int[M+N];


    for(int i=0;i<M;i++) {
        fin>>A[i];
    }
    for(int i=0;i<N;i++) {
        fin>>B[i];
    }

    int aux=cmlsc(A,M,B,N,S);

    fout<<aux<<endl;
    for(int i=0;i<aux;i++) {
        fout<<S[i]<<" ";
    }


    delete []A;
    delete []B;
    delete []S;
    fin.close();
    fout.close();
    return 0;
}
