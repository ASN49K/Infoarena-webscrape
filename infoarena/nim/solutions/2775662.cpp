#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int n, ans;

void solve()
{
    int a;
    fin>>n>>a;
    ans=a;
    for(int i=2; i<=n; i++)
    {
        fin>>a;
        ans=ans^a;
    }
    if(ans==0)
        fout<<"NU";
    else
        fout<<"DA";
    fout<<'\n';
}

int main()
{
    int test;
    fin>>test;
    for(int t=1; t<=test; t++)
        solve();
    return 0;
}
