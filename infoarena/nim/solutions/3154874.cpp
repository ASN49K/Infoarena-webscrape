#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

#define cin fin
#define cout fout

int main()
{
    int t,n,x;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n; int s=0;
        for(int j=1;j<=n;j++)
        {
            cin>>x; s=s^x;
        }
        if(s==0) cout<<"NU"<<"\n";
        else cout<<"DA"<<"\n";
    }
    return 0;
}
