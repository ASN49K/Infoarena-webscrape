#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
    long long a, b, c,d, rest;
    cin >> a >> b;
    c= min(a,b);
    d= max(a,b);
    rest = d%c;
    while(rest !=0)
    {
        long var = 0;
        var = c % rest;
        c = rest;
        rest = var;
    }

    cout << c << endl;
    }

}
