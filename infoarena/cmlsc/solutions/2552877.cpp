#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,v1[1030],v2[1030];
unordered_map<int,unordered_map<int,int>>viz;
stack<int>q;

int lcs(int l1,int l2)
{
    if(l1==0 || l2==0) return 0;
    if(viz[l1][l2]!=0) return viz[l1][l2];
    if(v1[l1]==v2[l2])
    {
        q.push(v1[l1]);
        viz[l1][l2]=1+lcs(l1-1,l2-1);
        return viz[l1][l2];
    }
    viz[l1][l2]=max(lcs(l1-1,l2),lcs(l1,l2-1));
    return viz[l1][l2];
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++) in>>v1[i];
    for(int i=1;i<=m;i++) in>>v2[i];
    out<<lcs(n,m)<<'\n';
    while(!q.empty())
    {
        out<<q.top()<<' ';
        q.pop();
    }
    return 0;
}
