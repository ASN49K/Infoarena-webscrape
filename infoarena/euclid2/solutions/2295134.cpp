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
        int r;
        while((r = a % b) != 0){
            if(r == 0) break;
            a = b;
            b = r;
        }
        cout << b << '\n';
    }
    return 0;
}
