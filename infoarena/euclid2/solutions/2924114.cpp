///https://infoarena.ro/problema/euclid2
#include <iostream>
#include <fstream>
using namespace std;
int a, b, d, i, T;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    in >> T;
    for (i = 1; i <= T; i++){
        in >> a;
        in >> b;
        while (a != b){
            if (a < b)
                b = b - a;
            else
                a = a - b;
        }
        out << a << "\n";
    }

    in.close();
    out.close();
    return 0;
}
