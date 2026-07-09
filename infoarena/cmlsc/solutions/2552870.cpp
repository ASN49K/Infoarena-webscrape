#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,v1[1030],v2[1030];
unordered_map<int,unordered_map<int,bool>>viz;
stack<int>q;

int lcs(int l1,int l2)
{
    if(l1==0 || l2==0) return 0;
    if(v1[l1]==v2[l2])
    {
        if(viz[l1][l2]) return 1+lcs(l1-1,l2-1);
        viz[l1][l2]=1;
        q.push(v1[l1]);
        return 1+lcs(l1-1,l2-1);
    }
    return max(lcs(l1-1,l2),lcs(l1,l2-1));
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
