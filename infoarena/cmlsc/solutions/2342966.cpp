#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int M,N;
    f>>M>>N;
    int A[M],B[N];
    int k = 0;
    int C[M > N ? N : N];
    for(int i = 0; i < M; i++)
        f>>A[i];
    for(int j  = 0; j < N; j++)
    {
        f>>B[j];
        for(int i = 0; i < M; i++)
        {
            if(B[j] == A[i])
                C[k++] = B[j];
        }
    }
    g<<k<<"\n";
    for(int i = 0 ; i < k; i++)
        g<<C[i]<<" ";
    return 0;
}
