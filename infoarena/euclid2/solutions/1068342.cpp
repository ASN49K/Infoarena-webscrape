#include <fstream>
  
using namespace std;
  
int gcd(int a,int b) {
    return !b ? a : gcd(b,a % b);
}
  
int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int a, b, T;
    for (cin >> T;T;T--) {
        cin >> a >> b;
        cout << gcd(a,b) << "\n";
    }
    return 0;                                                               
}
