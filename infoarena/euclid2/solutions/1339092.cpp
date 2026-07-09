#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

inline int gcd (int A, int B)
{
    int r = A % B;

    while (r){
        A = B;
        B = r;
        r = A % B;
    }

    return B;
}

int main()
{
    int T, A, B;

    for (in >> T; T; T --){
        in >> A >> B;
        out << gcd (A, B) << "\n";
    }

    return 0;
}
