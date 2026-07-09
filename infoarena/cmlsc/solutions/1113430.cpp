//Infoarena. Arhiva Educationala. Cel Mai Lung Subsir Comun

#include<iostream>
#include<fstream>
using namespace std;

int maxim(int,int);
int C[1026][1026];

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int M,A[1028],N,B[1028];
    cin>>M>>N;
    for(int i=1;i<=M;i++) cin>>A[i];
    for(int i=1;i<=N;i++) cin>>B[i];


    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            if(B[i]==A[j]) C[i][j]=C[i-1][j-1]+1;
            else C[i][j]=maxim(C[i-1][j],C[i][j-1]);
        }

    int len=C[N][M];
    cout<<len<<endl;

    int sir[1026];
    int aux=len;
    int i=N,j=M;
    while(aux>0){
        if(B[i]==A[j]){
            sir[aux]=B[i];
            aux--;
            i--;j--;
        }else if(C[i-1][j]>=C[i][j-1]) i--;
               else j--;
    }

    for(int i=1;i<=len;i++) cout<<sir[i]<<" ";
}

int maxim(int a,int b){
    return (a>b)?a:b;
}
