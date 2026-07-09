#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int T, a, b;
    in >> T;

    for (int i = 0; i < T; i++)
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