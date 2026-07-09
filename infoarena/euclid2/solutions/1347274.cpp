#include <iostream>

using namespace std;

int n,a,b;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a mod b);
}

int main()
{
    int i;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "rw, stdout);

    cin >> n;

    for(i=1; i<=n; i++){
        int d;
        cin >> a >> b;
        cout << gcd(a,b) << '\n';
    }

    return 0;
}
