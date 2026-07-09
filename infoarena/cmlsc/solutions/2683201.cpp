#include <iostream>
using namespace std;
int main()
{
    int M,N,i,j,X[255],V[255],L[255],y=0;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    M<<f;
    N<<f;
    for(i=1;i<=M;i++){
            V[i]<<f;
    }
        for(j=1;j<=N;j++){
            X[i]<<f;
    }
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            if(X[i]==V[j]){
                y++;
                L[y]=X[i];
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
