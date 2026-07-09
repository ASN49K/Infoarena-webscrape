#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int M,N;
    map< int,pair<int,int> > P;
    f>>M>>N;
    for(int i=0,x;i<M;i++)
    {
        f>>x;
        P[x].first++;
    }
    for(int i=0,x;i<N;i++)
    {
        f>>x;
        P[x].second++;
    }
    vector<int> V;
    for(auto i:P)
        if(i.second.first*i.second.second!=0) for(int j=0;j<min(i.second.first,i.second.second);j++) V.push_back(i.first);
    g<<V.size()<<'\n';
    for(auto i:V) g<<i<<' ';

    return 0;
}
