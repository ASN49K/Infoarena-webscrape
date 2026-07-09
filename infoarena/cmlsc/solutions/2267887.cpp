#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int M,N,A[1024],B[1024],D[1024][1024],k,nr[1024];
int main()
{
    f>>M>>N;
    for(int i=1;i<=M;++i)f>>A[i];
    for(int i=1;i<=N;++i)f>>B[i];
    for(int i=1;i<=M;++i)
        for(int j=1;j<=N;++j)
                if(A[i]==B[j])D[i][j]=1+D[i-1][j-1];
                else D[i][j]=max(D[i-1][j],D[i][j-1]);
    for(int i=M,j=N;i>0;)
        if(A[i]==B[j])nr[++k]=A[i],--i;
        else if(D[i][j-1]>D[i-1][j])--j;
        else --i;
    g<<k<<'\n';
    for(int i=k;i>0;--i)g<<nr[i]<<' ';
    return 0;
}
