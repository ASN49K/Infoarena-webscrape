/*
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
ifstream fin("bfs.in");
ofstream fout("bfs.out");
const int MAX_N=100005;
int n,m,start,nrc;
vector <int> v[MAX_N];
int VIZ[MAX_N];


void BFS(int nod){

  queue < int > Q;

  fill(VIZ+1, VIZ + n + 1, -1);
  VIZ[nod]=0;
  Q.push(nod);

  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();

    for (auto it : v[node]) {
        if (VIZ[it] == -1) {
            VIZ[it] = VIZ[node] + 1;
            Q.push(it);
        }
    }
  }

}

int main()
{
    fin>>n>>m>>start;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        fin>>x>>y;
        v[x].push_back(y);
    }

    BFS(start);

    for (int i = 1; i <= n; ++i)
        fout << VIZ[i] << " ";

    return 0;


}
*/

#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,x,y;

int cmmdc()
{
    int r=x%y;
    while(r)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}

int main()
{
    fin>>t;
    for(int i=1; i<=t; i++)
    {
        fin>>x>>y;
        fout<<cmmdc()<<"\n";
    }
}





























