#include<fstream>
#include<algorithm>
#include<set>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

void rez(int nr)
{
    int z=0;
    for(i=1;i<=nr;i++)
        d[i]=inf,c[i]=0;
    d[nr]=0;
    q.push(make_pair(0,nr));
    while(!q.empty())
    {
        while(!q.empty()&&f[q.top().second]==1) q.pop();
        if(q.empty()) break;
        nod=q.top().second;val=q.top().first;f[nod]=1;
        if(t[nod]==nr) c[nod]=++z;
        for(auto it:v[nod])
        {
            if(f[it.second]==0&&d[it.second]>val+it.first)
            {
                d[it.second]=val+it.first;
                t[it.second]=nod;c[it.second]=c[nod];
                q.push(make_pair(d[it.second],it.second));
            }
        }
    }

}

int main()
{
    fin>>n>>m;
    for(i=1;i<=m;i++)
    {
        fin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for(i=1;i<=n;i++)
        rez(i);
    return 0;
}
