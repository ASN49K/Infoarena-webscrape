#include <bits/stdc++.h>
#define ll long long int
#define double long double
#define pb push_back
#define endl '\n'
#define er erase
#define sz size
#define in insert
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
using namespace std;



ll a, b, t;

ll gcd(ll x, ll y)
{
    if(y==0) return x;
    return gcd(y, x%y);
}

int main(){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<gcd(a, b)<<endl;
    }
    return 0;
}
