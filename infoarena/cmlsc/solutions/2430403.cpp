#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int A[1024],B[1024],M,N;
int i,j,ok,k;
int C[1024];
int main()
{   f>>M>>N;
    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1;i<=N;i++)
        f>>B[i];
    if(M>=N)
    {
        for(i=1;i<=M;i++)
            for(j=1;j<=N;j++)
                if(A[i]==B[j])
            {
                ok++;
                C[++k]=A[i];
                j=N+1;
            }
    }
    else
    {
        for(i=1;i<=N;i++)
            for(j=1;j<=M;j++)
                if(A[i]==B[j])
            {
                ok++;
                C[++k]=A[i];
                j=M+1;
            }
    }
    g<<ok<<"\n";
    for(i=1;i<=ok;i++)
        g<<C[i]<<" ";
    return 0;
}
