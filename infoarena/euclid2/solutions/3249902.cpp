//Rares 0net
using namespace std;
#ifdef RS
#include<d:\Rares0.hpp>
#else
#include<fstream>
#include<algorithm>
const string N_file="euclid2";
ifstream fin(N_file+".in");
ofstream fout(N_file+".out");
#define cin fin
#define cout fout
#endif
#define endl '\n'
#define INF 0x3f3f3f3f
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
int n;
int x, y;
void Solve()
{
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>x>>y,
        cout<<__gcd(x, y)<<endl;
}
main()
{
    Solve();
}