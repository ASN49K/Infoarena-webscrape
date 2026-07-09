#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int R[1025][1025];
int V[1025],C[1025],n,m;

inline int maxim(int a,int b){if(a>b)return a;return b;};

void reconstituire(int i,int j)
{
    if(R[i][j])
    if(V[i]==C[j]){reconstituire(i-1,j-1);out<<V[i]<<' ';}
    else if(R[i][j]==R[i-1][j])reconstituire(i-1,j);
    else if(R[i][j]==R[i][j-1])reconstituire(i,j-1);
}

int main()
{
    int i,j;
    in>>n>>m;
    for(i=1;i<=n;i++)in>>V[i];
    for(i=1;i<=m;i++)in>>C[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(V[i]==C[j])R[i][j] = R[i-1][j-1]+1;
            else R[i][j] = maxim(R[i-1][j],R[i][j-1]);
    out<<R[n][m]<<'\n';
    reconstituire(n,m);
    return 0;
}
