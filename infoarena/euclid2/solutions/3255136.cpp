#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int a, b, r, t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        cout << a;
    }
    return 0;
}