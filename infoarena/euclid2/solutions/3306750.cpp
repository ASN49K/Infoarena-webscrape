#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n,a,b,r;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b;
        while(b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<"\n";
    }
    return 0;
}
