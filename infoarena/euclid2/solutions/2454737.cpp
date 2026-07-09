#include <bits/stdc++.h>
using namespace std;

#define ll long long

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
/*
*/
#define cin fin
#define cout fout



const int MAXN=100005;
int n;
pair<int,int> v[MAXN];

void read()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>v[i].first>>v[i].second;
}

int Euclid(int a, int b)
{
    if(b==0)
        return a;
    return Euclid(b,a%b);
}
void solve()
{
    for(int i=1; i<=n; i++)
        cout<<Euclid(v[i].first,v[i].second)<<"\n";
}

int main()
{
    read();
    solve();

    return 0;
}
