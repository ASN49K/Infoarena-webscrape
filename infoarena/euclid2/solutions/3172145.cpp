#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a, b, rest, t;

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++){
    cin >> a >> b;
    while(b)
    {
        rest = a % b;
        a = b;
        b = rest;

    }
    cout << a << "\n";
    }
    return 0;
}
