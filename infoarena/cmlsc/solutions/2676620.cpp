#include <fstream>
#define NMAX 1024
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int M, N;
int A[NMAX], B[NMAX], C[NMAX];
int lgh;
int i, j , poz, k;
int main()
{
    f>>M>>N;
    for(i=1; i<=M; i++)
        f>>A[i];
    for(i=1; i<=N; i++)
        f>>B[i];
    int poz=1;
    for(i=1; i<=M; i++)
        for(j=poz; j<=N; j++)
            if(B[i]==A[j])
            {
                C[++k]=A[j];
                lgh++;
                poz=i+1;
            }
    g<<lgh<<endl;
    for(int i=1; i<=k; i++)
        g<<C[i]<<" ";
    return 0;
}
