#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("nim.in");
ofstream g ("nim.out");

int n, t;

void rezolva () {
    f >> n;
    int x, s = 0;
    for (int i = 1; i <= n; i++) {
        f >> x;
        s = (s ^ x);
    }
    if (s) g << "DA\n";
    else g <<"NU\n";

}

int main () {
    f >> t;
    for (int i = 1; i <= t ; i++) rezolva ();
    return 0;
}
