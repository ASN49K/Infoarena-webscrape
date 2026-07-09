#include <iostream>
#include <fstream>

using namespace std;
int T, a, b;
int main()
{

    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

        in >> T;

    for (T; T; T--)
    {
        in >> a >> b; // a,b > 0
        while (b != 0)
        {
            // (a, b) <- (b, a%b)
            int temp = a;
            a = b;
            b = temp % b;

            out << a << endl;
        }
    }
}