#include<bits/stdc++.h>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int v[10005];

int main()
{
    int t,l,n,i,ans;
    cin>>t;
    for(l=1;l<=t;l++)
    {
        ans=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>v[i];
            ans=ans ^ v[i];
        }
        if(ans==0)
            cout<<"NU";
        else
            cout<<"DA";
        cout<<'\n';
    }
    return 0;
}
