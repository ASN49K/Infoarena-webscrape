#include<bits/stdc++.h>

using namespace std;
int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int t,x,y;
    cin>>t;
    while (t--)
    {
        cin>>x>>y;
        cout<<__gcd(x,y)<<"\n";
    }
    return 0;
}
