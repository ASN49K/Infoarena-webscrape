#include <fstream>
using namespace std;

int main()
{
    int a,b,c;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>a>>b;
    while (b) {
        c = a % b;
        a = b;
        b = c;

    }

    g<<a;



    return 0;
}
