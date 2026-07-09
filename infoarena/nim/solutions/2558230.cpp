#include <bits/stdc++.h>
#define ff first
#define ss second
#define NMAX
#define pb push_back
using namespace std;
const string file = "nim";

ifstream fin (file+".in");
ofstream fout (file+".out");
typedef long long ll;
typedef long double ld;

const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, inf = 2147483647;
int t;
int xorsum;
int main()
{
    int x,N;
    fin>>t;
    while(t)
    {
        t--;
        fin >> N;
        xorsum = 0;
        for(int i=1;i<=N;++i)
            fin>>x, xorsum^=x;
        if(xorsum) fout<<"DA\n";
        else fout<<"NU\n";
    }
    return 0;
}
