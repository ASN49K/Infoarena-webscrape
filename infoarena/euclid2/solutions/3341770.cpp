#include <bits/stdc++.h>

using namespace std;

int cmmdc(int a,int b)
{
    int R;
    while((a%b)>0)
    {
        R=a%b;
        a=b;
        b=R;
    }
    return b;
}

int main () 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n; cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
}