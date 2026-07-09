#include <fstream>
using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int cmmdc(int a,int b)
{
    while(b){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void solve()
{
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
}
int main()
{
    solve();
}
