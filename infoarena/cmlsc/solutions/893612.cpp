#include <fstream>
#include<deque>
#include<stack>
#define lmax 1025

using namespace std;
unsigned short int n,m,i,x,D[lmax][lmax],cl;
stack<unsigned short int> sol;
char a[lmax],b[lmax];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(i=1;i<=n;i++) f>>x,a[i]=(char)x;
    for(i=1;i<=m;i++) f>>x,b[i]=(char)x;
    f.close();
    for(i=1;i<=n;i++)
        for(x=1;x<=m;x++)
            if(a[i]==b[x])
                D[i][x]=D[i-1][x-1]+1;
            else
                D[i][x]=max(D[i-1][x],D[i][x-1]);
    g<<D[n][m]<<"\n";
    for(i=1;i<=n;i++,g<<"\n")
        for(x=1;x<=m;x++)
        g<<D[i][x]<<" ";
    g<<"\n";
    i=n;
    x=m;
    cl=D[n][m];
    while(D[i][x])
    {
        while(D[i-1][x]==D[i][x])
            --i;
        while(D[i][x-1]==D[i][x])
            --x;
        sol.push((int)a[i]);
        --x;

    }
    g<<"\n";
    while(!sol.empty())
        {
            g<<sol.top()<<" ";
            sol.pop();
        }
    g.close();
    return 0;
}
