#include <iostream>
using namespace std;

int gcd(int x, int y){
    while(y){
        int c = x % y;
        x = y;
        y = c;
    }
    return x;
}

int main(){
    int n, x, y;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> x >> y;
        cout << gcd(x, y);
    }
}
