#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
char D[1025][1025]={0};
///0:|
///1:<-
///2: \                                                                  /
int N[1025],M[1025];
short R[1025][1025]={0};
void af(int n,int m)
{
    if(n==0 || m==0)    return;
    if(D[n][m]==0)  af(n-1,m  );
    if(D[n][m]==1)  af(n  ,m-1);
    if(D[n][m]==2) {af(n-1,m-1);   out<<N[n]<<" ";}

}
int f(int n,int m)
{
    if(R[n][m]!=0)
    {
        if(R[n][m]==-1) return 0;
        return R[n][m];
    }

    if(n==0 || m==0)
    {
        return 0;
    }
    if(N[n]==M[m])
    {
        D[n][m]=2;
        R[n][m]=1+f(n-1,m-1);
        return R[n][m];
    }
    int a=f(n-1,m),b=f(n,m-1);
    if(a>=b)
    {
        D[n][m]=0;
        if(a==0)      R[n][m]=-1;
        else          R[n][m]=a;
        return a;
    }
    else
    {
        D[n][m]=1;
        if(b==0)      R[n][m]=-1;
        else          R[n][m]=b;
        return b;
    }
}
int main()
{
    int n,m;
    in>>n>>m;
    for(int i=1;i<=n;i++)   in>>N[i];
    for(int i=1;i<=m;i++)   in>>M[i];
    out<<f(n,m)<<" "; af(n,m);

}
