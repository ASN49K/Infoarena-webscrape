#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int n;

void citire();

int euclid(int a, int b) {
    int r;

    while(r != 0) {
        r = a%b;
        a = b;
        b = r;
    }
    g << a << '\n';
}

int main()
{
    citire();
    return 0;
}

void citire() {
    int a, b;

    f >> n;
    for(int i = 1; i <= n; ++i) {
        f >> a >> b;

           euclid(a,b);


    }
}
