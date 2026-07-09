#include <fstream>
#include <algorithm>
using namespace std;

const string name("euclid2");
ifstream cin(name + ".in");
ofstream cout(name + ".out");

int main(){

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;
        cout << __gcd(x, y) << '\n';
    }

    return 0;
}
