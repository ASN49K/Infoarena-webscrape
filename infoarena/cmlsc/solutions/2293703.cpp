#include <iostream>
#include <fstream>
using namespace std;
#define Max 1024
int main()
{
    int A[Max],B[Max],C[Max],N,M,k=0;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>M;
    f>>N;
    for(int i=0;i<M;i++)
        f>>A[i];
    for(int i=0;i<N;i++)
        f>>B[i];
    for(int i=0;i<(N<M ? M:N );i++)
    {
        for(int j=0;j<(N<M ? N:M);j++){
           if(A[i] == B[j])
            C[k++]=A[i];}
    }
    g<<k<<'\n';
    for(int i=0;i<k;i++)
        g<<C[i]<<" ";
    return 0;
}
