#include <fstream>
#include <iostream>
using namespace std;
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a, b;
    f >> a >> b;
    g << euclid(a,b) << "\n";

    return 0;
}
