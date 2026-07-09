#include<fstream>
using namespace std;
 ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],sol[1025][1025],v[1025],k;
void citire()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>a[i];
    for(int i=1;i<=m;++i)
        f>>b[i];
}
void PD1()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        if(a[i]==b[i])
        sol[i][j]=1+sol[i-1][j-1];
    else
        sol[i][j]=max(sol[i-1][j], sol[i][j-1]);
}
void PD2()
{
    g<<sol[n][m]<<endl;
    int i=n , j=m;
    k=sol[i][j];
    while(k>0)
    {
        if(a[i]==b[j])
        {
            v[k--]=a[i];
            i--; j--;
        }
        else
            if(sol[i][j-1]> sol[i-1][j])
            j--;
        else
            i--;
    }
    for(int i=1;i<=sol[n][m];++i)
        g<<v[i]<<' ';
        g.close();
}
int main()
{
    citire();
    PD1();
    PD2();
    return 0;
}
