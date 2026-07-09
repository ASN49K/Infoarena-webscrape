#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t,n,m;
int euclid(int n,int m){
    while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}
int main()
{
    cin>>t;
    while(t){
        cin>>n>>m;
        cout<<euclid(n,m)<<'\n';
        t--;
    }
    return 0;
}
