#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
typedef long long ll;
int n,a[200005],x,y,b[100005];
int main()

{
    fin>>x>>y;
for(int i=1;i<=x;i++)
    fin>>a[i];
for(int i=1;i<=y;i++)
    {fin>>b[i];
    for(int j=1;j<=x;j++)
{if(a[j]==b[i])
    fout<<b[i]<<" ";}}
return 0;}
//'\n'
// ||
