#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
#define MOD 713
vector<int> G[MOD];

inline vector<int>::iterator find_value(int x)
{
    int list = x % MOD;
    vector<int>::iterator it;

    for (it = G[list].begin(); it != G[list].end(); ++it)
        if (*it == x)
            return it;
    return G[list].end();
}

inline void insert_value(int x)
{
    int list = x % MOD;
    //if (find_value(x) == G[list].end())
        G[list].push_back(x);
}

inline void erase_value(int x)
{
    int list = x % MOD;
    vector<int>::iterator it = find_value(x);

    if (it != G[list].end())
        G[list].erase(it);
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,i,j=0,a;
    vector <int> x;
    deque <int> q;
    f>>n>>m;
    for(i=1;i<=n;i++)
    {f>>a;q.push_back(a);insert_value(a);}
    for(i=1;i<=m;i++)
    {
        f>>a;
        if(find_value(a)!=G[a % MOD].end())
            {
                j++;
                x.push_back(a);
                while(q.front()!=a)
                    {erase_value(q.front());q.pop_front();}
            }
    }
    g<<j<<"\n";
    for(i=0;i<x.size();i++) g<<x[i]<<" ";
    f.close();
    g.close();
    return 0;
}
