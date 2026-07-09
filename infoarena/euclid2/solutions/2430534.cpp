#include <iostream>
#include <fstream>

using namespace std;

ifstream in("da.in");

int div(int a, int b) {
    if (!b)
        return a;
    return div(b, a % b);
}

int main()
{
    int a, b, t;
    in >> t;
    for(int i = 1; i <= t; i++) {
        in >> a >> b;
        cout << div(a, b) << "\n";
    }
    return 0;
}
