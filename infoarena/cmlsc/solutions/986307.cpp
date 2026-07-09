//solutia o construiesc in tabloul D [ ][ ]
//lungimea cmlsc va fi D[n][m]
#include <fstream>
#include <algorithm>
#include <vector>
#define Nmax 1500
#define pb push_back
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[Nmax],b[Nmax],D[Nmax][Nmax],L;
vector <int> sol;

void ReadInput()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)f>>a[i];
    for(int i=1;i<=m;i++)f>>b[i];
}

void MakeDynamic(int a[],int b[],int n,int m,int D[Nmax][Nmax])
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])D[i][j]=D[i-1][j-1]+1;
                     else D[i][j]=max(D[i-1][j],D[i][j-1]);
    L=D[n][m];
}

void MakeCMLSC(int D[Nmax][Nmax])
{
     for(int i=n,j=m;i>0;)
        if(a[i]==b[j])
        {
            sol.pb(a[i]);
            i--; j--;
        }
        else if(D[i-1][j]>D[i][j-1])i--;
                               else j--;
}

void PrintOutput()
{
    g<<L<<'\n';
    for(int i=L-1;i>=0;i--)g<<sol[i]<<' ';
    g<<'\n';
}

int main()
{
    ReadInput();
    MakeDynamic(a,b,n,m,D);
    MakeCMLSC(D);
    PrintOutput();
    f.close();g.close();
    return 0;
}
