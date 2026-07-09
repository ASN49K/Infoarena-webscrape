#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n;
    cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<__gcd(a,b)<<endl;
    }
}