#include <bits/stdc++.h>
using namespace std;

#ifdef INFOARENA
ifstream f("euclid2.in");
#define cout g
#else
ifstream f("date.in");
#endif // INFOARENA

ofstream g("euclid2.out");

int a,b,n;

int main()
{
    f>>n;
    for(;n;--n)
    {
        f>>a>>b;
        while(a%=b) swap(a,b);
        cout<<b<<'\n';
    }
    return 0;
}
