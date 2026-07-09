#include <bits/stdc++.h>
using namespace std;

int eucl(int x, int y){
    int r;
    while(y){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    int T, x, y;
    cin >> T;
    for(;T;T--){
        cin >> x >> y;
        cout << eucl(x, y) << '\n';
    }

}
