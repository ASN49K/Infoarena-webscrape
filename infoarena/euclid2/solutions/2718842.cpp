#include <bits/stdc++.h>

using namespace std;



int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int n,a,b;
    cin>>n;



    while(n--)
    {
        cin>>a>>b;
        while(b!=0&&a!=0)
        {
            if(b>a) b=b%a;
            else a=a%b;
        }
        a=a>b?a:b;
        cout<<a<<'\n';
    }
    return 0;
}
