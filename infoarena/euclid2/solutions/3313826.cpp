#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    int t;
    for(cin>>t;t--;) {
        int a,b;
        cin>>a>>b,cout<<__gcd(a,b)<<'\n';
    }
    return 0;
}
