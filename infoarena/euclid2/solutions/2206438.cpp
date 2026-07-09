#include <fstream>
#include <queue>
using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
int n, m;
bool b[50005];
int af[50005], k=1;
 queue <int> q[50005];

void parc(int poz)
{
    b[poz]=true;
    if(q[poz].empty()) {af[k]=poz; k++;}
    else
    {
    while(!q[poz].empty())
    {parc(q[poz].front());
    q[poz].pop();}
    af[k]=poz; k++;
    }
}

int main()
{   int x, y;
    f>>n>>m;
    for(int i=1; i<=m; i++)
    {
    f>>x>>y;
    q[x].push(y);
    }
    for(int i=1; i<=n; i++)
    {
    if(b[i]==false)
    {
    parc(i);
    }
    }
    for(int i=n; i>=1; i--)
    g<<af[i]<<" ";
    return 0;
}
