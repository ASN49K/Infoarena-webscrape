#include<bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    long long n, a, b;
    f >> n;
    for(int i = 1; i <= n; i++)
    {
        f >> a >> b;
        if(a > b) swap(a, b);
        while(a != 0)
        {
            b %= a;
            swap(a, b);
        }
        g << b << endl;
    }
    return 0;
}