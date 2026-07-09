#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int M,N,a[10000][10000],v[10000],k;
int MAx(int a,int b)
{
    if(a>=b)
    return a;
    else
    return b;
}
int main()
{
    f>>M>>N;
    for(int i=2;i<=M+1;i++)
        f>>a[0][i];
    for(int i=2;i<=N+1;i++)
        f>>a[i][0];
    for(int i=2;i<=N+1;i++)
    {
        for(int j=2;j<=M+1;j++)
        {
            if(a[i][0]==a[0][j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                a[i][j]=MAx(a[i-1][j],a[i][j-1]);
            }
        }
    }
    int j=M+1,i=N+1;

    while(a[i][j])
    {
        if((a[i-1][j]==a[i][j-1])&&a[i-1][j]<a[i][j])
        v[++k]=a[i][0];
        if(a[i-1][j]==a[i][j-1])
        {
            i--;j--;
        }
        else
        {
            if(a[i-1][j]>a[i][j-1])
            i--;
            else
            j--;
        }
    }
    g<<a[N+1][M+1]<<'\n';

    for(int i=k;i>=1;i--)
    g<<v[i]<<" ";
    return 0;
}
