#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    int n, a, b, c;
    in >> n;
    ofstream out("euclid2.out");
    for (;n;--n)
    {
        in >> a >> b;
        while(b)
        {
            c = a;
            a = b;
            b = c%b;
        }
        cout << a;
    }
    return 0;
}
