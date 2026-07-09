#include <iostream>
#include <fstream>
#define NMax 1024
using namespace std;

int M,N,A[NMax],B[NMax],D[NMax][NMax],i,j,sir[NMax],nr;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>M>>N;
    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1;i<=N;i++)
    f>>B[i];
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
    {
        if(A[i]==B[j])D[i][j]=1+D[i-1][j-1];
        else D[i][j]=max(D[i-1][j],D[i][j-1]);
    }i=M;j=N;

     for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++nr] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    g<<nr<<endl;
    for(i=nr;i>=1;i--)
        g<<sir[i]<< " ";
}
