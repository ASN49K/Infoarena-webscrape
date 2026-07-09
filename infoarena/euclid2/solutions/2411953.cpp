#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T, a, b, r;
    in >> T;
    for(int i = 1; i <= T; i++)
    {
        in >> a >> b;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        out << a << endl;
    }
    in.close();
    out.close();
    return 0;
}
