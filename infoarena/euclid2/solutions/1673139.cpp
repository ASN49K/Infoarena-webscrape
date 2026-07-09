#include <iostream>
#include <stdio.h>

using namespace std;

int euclid(int a, int b){
    if (b == 0)
        return a;
    else
        return euclid(b, a%b);
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
