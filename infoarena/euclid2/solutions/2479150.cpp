#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    cin>>t;

    while(t--)
    {
        int a,b,r;
        cin>>a>>b;

        if(a<b)
            swap(a,b);

        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }

        cout<<a<<'\n';
    }

}
