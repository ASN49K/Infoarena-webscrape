#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,i;
    long long int a,b;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<endl;
    }
    return 0;
}
