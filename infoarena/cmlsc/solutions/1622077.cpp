#include <fstream>
#define DIM 1026
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int M,N,A[DIM],B[DIM],sir[DIM],bst;
int C[DIM][DIM];
int main()
{
    int i,j;
    f>>M>>N;
    for(i=1;i<=M;++i) f>>A[i];
    for(i=1;i<=N;++i) f>>B[i];
    for(i=1;i<=M;++i){
        for(j=1;j<=N;++j){
            if(A[i]==B[j])
                C[i][j]=1+C[i-1][j-1];
            else C[i][j]=max(C[i][j-1],C[i-1][j]);
        }
    }
    for(i=M,j=N;i; ){
        if(A[i]==B[j]){
            sir[++bst]=A[i];
            --i;--j;
        }
        else if(C[i-1][j]<C[i][j-1]) --j;
        else --i;
    }
    g<<bst<<'\n';
    for(i=bst;i;--i)
        g<<sir[i]<<' ';
    f.close();
    g.close();
    return 0;
}
