#include <iostream>
#include <stdio.h>

using namespace std;

int euclid(int a, int b){
    int r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int a, b, n;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    cin >> n;

    for (int i = 0 ; i < n ; i++){
        cin >> a;
        cin >> b;
        cout << euclid(a,b) << endl;
    }

    return 0;
}
