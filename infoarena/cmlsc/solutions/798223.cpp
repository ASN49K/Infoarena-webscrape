#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define maxim(a,b) ( (a>b) ? a:b )

short int A[1024],B[1024],D[1024][1024], N,M,numar,R[1024];

int main()
{
    int i,j;
    f>>N>>M;
    for(i=1;i<=N;i++)   f>>A[i];
    for(i=1;i<=M;i++)   f>>B[i];

    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(A[i]==B[j])  D[i][j]=D[i-1][j-1] + 1;
            else            D[i][j]=maxim(D[i-1][j],D[i][j-1]);
    for(i=N,j=M;i;)
        if(A[i]==B[j]) R[++numar]=A[i],--i,--j;
        else if(D[i-1][j]<D[i][j-1])    j--;
        else i--;
    g<<numar<<'\n';
    for(i=numar;i>=1;i--)
        g<<R[i]<<" ";
    f.close();
    g.close();
    return 0;
}
