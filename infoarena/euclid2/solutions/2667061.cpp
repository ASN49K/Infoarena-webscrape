#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    ifstream cin ("euclid2.in");
    ofstream cout ("euclid2.out");
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        cout<<__gcd(a,b)<<"\n";
    }
    return 0;
}
