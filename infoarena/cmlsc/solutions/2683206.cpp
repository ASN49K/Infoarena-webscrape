#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int M,N,i,j,X[256],V[256],L[256],y=0;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>M;
    f>>N;
    for(i=1;i<=M;i++){
            f>>V[i];
    }
        for(j=1;j<=N;j++){
            f>>X[i];
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
