#include <fstream>
#include<deque>
#define lmax 1025

using namespace std;
unsigned short int n,m,i,x,D[lmax][lmax],maxim;
deque<unsigned short int> sol;
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
            {
                D[i][x]=D[i-1][x-1]+1;
                if(D[i][x]>maxim)
                sol.push_back((int)a[i]),maxim=D[i][x];
            }
            else
                D[i][x]=max(D[i-1][x],D[i][x-1]);
    g<<D[n][m]<<"\n";
    while(!sol.empty())
        {
            g<<sol.front()<<" ";
            sol.pop_front();
        }
    g.close();
    return 0;
}
