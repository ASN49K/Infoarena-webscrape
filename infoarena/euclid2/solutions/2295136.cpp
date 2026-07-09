#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T, a, b;
    cin >> T;

    while(T--){
        cin >> a >> b;
        while(a != b){
            if(a > b) a -= b;
            else if(a < b) b -= a;
        }
        cout << b << '\n';
    }
    return 0;
}
