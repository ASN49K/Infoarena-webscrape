#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int M,N,i,j,A[256],B[256],L[256],y=0;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>M;
    f>>N;
    for(i=1;i<=M;i++){
            f>>A[i];
    }
        for(j=1;j<=N;j++){
            f>>B[i];
    }
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            if(B[i]==A[j]){
                y++;
                L[y]=B[i];
            }
        }
    }
    g<<y;
    g<<endl;
    for(i=1;i<=y;i++){
        g<<L[i]<<" ";
        }
        return 0;
}
