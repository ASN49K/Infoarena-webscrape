#include <fstream>
#include <vector>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int n;
pair < int, int > p;
vector < pair < int, int > > v;
int gcd(int a, int b) {
    int t;
    while(b) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{
    cin>>n;
    for(; cin>>p.first>>p.second; )
        v.push_back(p);
    cin.close();

    for(int i = 0; i < n; i++) {
        cout<<gcd(v.at(i).first, v.at(i).second)<<'\n';
    }

    cout.close();
    return 0;
}
