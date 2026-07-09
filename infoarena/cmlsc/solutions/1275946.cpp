#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int p1[1025],p2[1025],pd[1025][1025];
int sol[1025];
inline int maxi(int a,int b)
{
    if(a>=b) return a;
    return b;
}
inline void solutie(int n,int m)
{
    if(pd[n][m])
    {

        if(p1[n]==p2[m])
        {
            solutie(n-1,m-1);
            sol[++sol[0]]=p1[n];
        }

    else

        if(pd[n][m]==pd[n-1][m])
        {
            solutie(n-1,m);
        }
        else if(pd[n][m]==pd[n][m-1])
        {
            solutie(n,m-1);
        }
    }
}
int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>p1[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>p2[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
                if(p1[i]==p2[j]) pd[i][j]=pd[i-1][j-1]+1;
                else pd[i][j]=maxi(pd[i][j-1],pd[i-1][j]);
        }
    }
    fout<<pd[n][m]<<"\n";
    solutie(n,m);
    for(i=1;i<=sol[0];i++) fout<<sol[i]<<" ";
}
