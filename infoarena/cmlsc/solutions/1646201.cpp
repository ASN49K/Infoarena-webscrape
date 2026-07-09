#include <iostream>
#include <fstream>
using namespace std;

int M,N,A[1024],B[1024],Mat[1024][1024],lS,SOL[1024];

int maxim(int a,int b){
    return a>b?a:b;
}


int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>M>>N;
    int i,j;
    for(i=1;i<=M;++i)
        f>>A[i];
    for(i=1;i<=N;++i)
        f>>B[i];
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            if(A[i]==B[j]){
                Mat[i][j]=Mat[i-1][j-1]+1;
            }else{
                Mat[i][j]=maxim(Mat[i-1][j],Mat[j-1][i]);
            }
        }
    }
    for(i=M,j=N;i>0;){
        if(A[i]==B[j]){
            SOL[++lS]=A[i];
            --i;
            --j;
        }else if(Mat[i-1][j]>Mat[i][j-1]){
            --i;
        }else{
            --j;
        }
    }
    g<<lS<<"\n";
    for(i=lS;i>0;--i){
        g<<SOL[i];
    }
    f.close();
    g.close();
    return 0;
}
