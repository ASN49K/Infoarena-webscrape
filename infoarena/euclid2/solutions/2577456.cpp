#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b) {
    int c, r;
    r = a%b;
    if (r != 0) {
        euclid(b, r);
    } else {
        return b;
    }
}

void citire() {
    int t;
    int a, b;
    int n;

    f >> t;
    cout << t << '\n';
    for (int i = 0; i < t; ++i){
        f >> a >> b;

        cout << a << ' ' << b << '\n';

        g << euclid(a,b) << '\n';
    }
//    cout << t << b;
}

int main()
{
    citire();
    return 0;
}

