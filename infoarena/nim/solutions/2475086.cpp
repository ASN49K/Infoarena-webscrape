#include <bits/stdc++.h>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int t,n,ans,x;
int main()
{
    in>>t;
    while(t--)
    {
        in>>n;
        ans=0;
        while(n--)
            in>>x,ans^=x;
        if(ans) out<<"DA\n";
        else out<<"NU\n";
    }
}
