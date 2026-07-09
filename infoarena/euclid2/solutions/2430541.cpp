#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int a, b, t, i;

int euclid(int a, int b) {
    if (!b)
        return a;
    return euclid(b, a % b);
}

int main()
{
    in >> t;
    for(i = 1; i <= t; i++) {
        in >> a >> b;
        cout << euclid(a, b) << "\n";
    }
    return 0;
}
