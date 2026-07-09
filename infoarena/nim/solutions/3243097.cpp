#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("nim.in");
    ofstream cout("nim.out");
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        int val, x=0;
        while(n--)
        {
            cin>>val;
            x=x^val;
        }
        if(x)cout<<"DA\n";
        else cout<<"NU\n";
    }
    return 0;
}
