#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
const int inf=100005;

ifstream fin("darb.in");
ofstream gout("darb.out");
vector <unsigned int> g[inf];

unsigned int lungMaxima,pozitie,n;

bool vizitat[inf];

void dfs(unsigned int nod,unsigned int nivel)
{

    vizitat[nod]=true;
    if(nivel>lungMaxima)
    {
        lungMaxima=nivel;
        pozitie=nod;
    }
    for(unsigned int i=0;i<g[nod].size();i++)
    {
        unsigned int vecin=g[nod][i];
        if(!vizitat[vecin])
            dfs(vecin,nivel+1);
    }
}

void reset()
{

    for(unsigned int i=1;i<=n;i++)
        vizitat[i]=false;
}

void read()
{
    unsigned int x,y,i;
    fin>>n;
    for(i=1;i<n;i++)
    {
        fin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

int main()
{
    read();
    dfs(1,0);
    reset();
    dfs(pozitie,0);
    gout<<lungMaxima+1;
    return 0;
}
