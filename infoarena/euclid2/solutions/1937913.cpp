#include <iostream>
#include <fstream>

using namespace std;


ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b){
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main()
{

    int t, a, b, r;

    in >> t;;

    for (int i = 1; i <= t; ++i) {
        in >> a >> b;
        out << cmmdc(a, b) << "\n";
    }


    return 0;
}
