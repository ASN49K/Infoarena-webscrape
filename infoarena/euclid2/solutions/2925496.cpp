#include    <iostream>
#include    <algorithm>
#include    <cstring>
#include    <vector>
#include    <string>
#include    <map>
#include    <set>
#include    <cstring>
#include    <cmath>
#include    <climits>
#include    <list>
#include    <cassert>
#include    <queue>
#include    <fstream>

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t;

void Solve()
{
    ll a,b;
    fin >> a >> b;

    if(b > a)
        swap(a,b);

    while(a)
    {
        ll r = b%a;
        b = a;
        a = r;
    }

    fout << b<<"\n";

}

int main()
{
//    fast_io;
    fin >> t;

    while(t--)
    {
        Solve();
    }

    return 0;
}
