#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T, a, b;
    cin >> T;

    for(int i = 0; i < T; ++i){
        cin >> a >> b;
        cout << gcd(a, b) << "\n";
    }

    return 0;
}
