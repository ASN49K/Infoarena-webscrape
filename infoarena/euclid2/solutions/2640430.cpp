#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,a,b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

ll gcd(int a,int b)
{
    ll maxx = max(a,b);
    if(maxx == b)
        swap(a,b);

    while(b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    fin >> t;
    while(t--)
    {
        fin >> a >> b;
        fout << gcd(a,b) << "\n";
    }
}
