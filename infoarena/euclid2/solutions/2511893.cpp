#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    long long n;
    cin>>n;
    while (n--)
    {
        long long a,b;
        cin>>a>>b;
        cout<<__gcd(a,b)<<endl;
    }
}