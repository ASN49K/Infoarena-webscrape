#include <fstream>
#define N 1030
#include <iostream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A[N],B[N],din[N][N];
void solve(int m, int n)
{
    if(din[m][n])
    {
        if(A[m]==B[n])
        {
            solve(m-1,n-1);
            g<<A[m]<<' ';
        }
        else
            if(din[m-1][n]>din[m][n-1]) solve(m-1,n);
            else solve(m,n-1);
    }
}
int main()
{
    int a,b;
    f>>a>>b;
    for(int i=1;i<=a;++i) f>>A[i];
    for(int j=1;j<=b;++j) f>>B[j];
    for(int i=1;i<=a;++i)
        for(int j=1;j<=b;++j)
            if(A[i]==B[j]) din[i][j]=1+din[i-1][j-1];
            else din[i][j]=max(din[i-1][j],din[i][j-1]);
    g<<din[a][b]<<'\n';
    solve(a,b);
    f.close();
    g.close();
    return 0;
}
