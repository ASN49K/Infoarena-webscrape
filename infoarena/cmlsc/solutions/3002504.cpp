#include <fstream>
using namespace std;
#define NMax 1024
#define maxim(a, b) ((a > b) ? a : b)
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int M, N, A[NMax+1], B[NMax+1], D[NMax+1][NMax+1], sir[NMax+1], bst;
int main(){
    int i, j;
    f>>M>>N;
    for(int i=1;i<=m;++i)
        f>>A[i];
    for(int i=1;i<=N;++i)
        f>>B[i];
    for(int i=1;i<=M;++i)
        for(int j=1;j<=N;++j)
            if (A[i]==B[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=maxim(D[i-1][j],D[i][j-1])
    for(i=M,j=N;i; )
        if(A[i]==B[j])
            sir[++bst]=A[i],--i,--j;
        else 
            if(D[i-1][j]<D[i][j-1])
                --j;
            else
                --i;
    g<<bst<<'\n';
    for (i=bst;i;--i)
        g<<sir[i]<<" ";
    return 0;
}