#include <fstream>
#define maxim(a,b) ((a>b) ? a : b)
using namespace std;
int N,M,A[1024],B[1024],D[1024][1024],i,j,SOL[1024],t=0;
int main()
{
    ifstream f("mlsc.in");
    ofstream g("mlsc.out");
    f>>M>>N;

    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1;i<=N;i++)
        f>>B[i];

    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++){

        if(A[i]==B[j])
            D[i][j]=1+D[i-1][j-1];
        else
            D[i][j]=maxim(D[i-1][j],D[i][j-1]);
        }

    for(i=M,j=N;i!=0;)
        if(A[i]==B[j])
            SOL[++t]=A[i],--j,--i;
        else if (D[i-1][j]<D[i][j-1])
            --j;
        else --i;
    g<<t;
    for(i=t;i;--i)
        g<<SOL[i];
    return 0;
}
